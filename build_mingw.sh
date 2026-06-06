#!/usr/bin/env bash
# ============================================================
#  build_mingw.sh — compilación de verificación con MinGW
#
#  Esto NO produce el .asi final de producción (eso se hace en
#  Visual Studio con ScriptHookV.lib real), pero verifica que
#  todo el código C++ compila y linkea correctamente.
#
#  Para el build de producción usa GTAVRReal.vcxproj en VS 2022.
# ============================================================
set -e

CXX=x86_64-w64-mingw32-g++
SHIM=$(mktemp -d)
echo '#include <windows.h>' > "$SHIM/Windows.h"
echo '#include <psapi.h>'   > "$SHIM/Psapi.h"

# NOTA: '-D__declspec(x)=' desactiva dllimport para que los símbolos de
# ScriptHookV se resuelvan contra el stub local en esta build de prueba.
# En el build real de VS, ScriptHookV.lib provee los símbolos __imp_ y
# este flag NO se usa.
FLAGS="-std=c++17 -O2 -msse2 -Iinclude -Isdk/inc -I$SHIM \
  -DWIN32_LEAN_AND_MEAN -DNOMINMAX -D_CRT_SECURE_NO_WARNINGS -D__declspec(x)="

mkdir -p obj bin

echo "== Compilando =="
for f in RVRBridge AdjustViewInverse RVRConfig RealVR; do
  echo "  $f.cpp"
  $CXX -c $FLAGS "src/$f.cpp" -o "obj/$f.o"
done

# Stub de ScriptHookV (en producción esto es ScriptHookV.lib)
cat > obj/shv_stub.cpp << 'EOF'
#define WIN32_LEAN_AND_MEAN
#include "main.h"
void scriptWait(DWORD){}
void scriptRegister(HMODULE,void(*)()){}
void scriptRegisterAdditionalThread(HMODULE,void(*)()){}
void scriptUnregister(HMODULE){}
void scriptUnregister(void(*)()){}
void nativeInit(UINT64){}
void nativePush64(UINT64){}
static UINT64 g; PUINT64 nativeCall(){return &g;}
int getGameVersion(){return 0x40;}
void keyboardHandlerRegister(KeyboardHandler){}
void keyboardHandlerUnregister(KeyboardHandler){}
BYTE* getScriptHandleBaseAddress(int){return 0;}
EOF
$CXX -c -std=c++17 -O2 -Isdk/inc -I"$SHIM" '-D__declspec(x)=' \
  obj/shv_stub.cpp -o obj/shv_stub.o 2>/dev/null

echo "== Linkeando bin/GTAVRReal.asi =="
$CXX -shared -static-libgcc -static-libstdc++ \
  obj/*.o -o bin/GTAVRReal.asi \
  -lpsapi -lkernel32 -luser32

echo "== OK =="
ls -lh bin/GTAVRReal.asi
file bin/GTAVRReal.asi
rm -rf "$SHIM"
