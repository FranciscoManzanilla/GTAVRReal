# GTAVRReal — Notas de RE del render VR (estado actual)

Objetivo: VR para GTA V que **sobreviva updates** (1.0.3xxx) usando **pattern
scanning** en vez de direcciones hardcodeadas (el original de LukeRoss usa
direcciones fijas y rompe en versiones nuevas). El render lo hace el proxy
`d3d11.dll` (3Dmigoto + funciones RVR); nuestro `.asi` lo alimenta.

## ✅ Resuelto (reconstruido por RE puro)

- ASI carga, parchea GTA5.exe con **6 trampolines de longitud variable**
  (13/16/15/16/14/16 bytes — alineados a límite de instrucción; un tamaño fijo
  de 16 partía instrucciones y crasheaba).
- Registros correctos por sitio: ViewInverse=rbx, Proj=rbx, FOV1stCar=**rbp**, etc.
- **Matriz de cámara real en `camObj+0xF0`** (no 0x70, que es FOV/near/far):
  filas right/up/forward/pos. Stride de salida en g_RVRData = **64** (no 256).
- **Handshake por frame** (igual al original):
  1. `RVRWaitAndTrackHMD(0x55)` — frame-begin (flag 0x55 cada frame, no 0x00)
  2. `RVRGetPoseFrame(&buf, 0)` → posePtr
  3. `RVRSeqCheck(poseBuf, outDesc)` — **2 argumentos** (rcx=pose, rdx=buffer
     salida). Pasar solo 1 arg = crash duro. ESTE fue el muro principal.
  4. `RVRGetFrameDesc(counter, outBuf)` — bit 0 del counter = ojo (0x4C/0x52)
- Loop a **72 fps** (= refresh Oculus); compositor paceado (WaitGetPoses OK).
- **Pose del HMD = quaternion** en `posePtr+0x00` [x,y,z,w], pos en +0x10.
- **Head-tracking por reproyección**: escribir el quaternion a `g_RVRData+0x77C`
  (SOLO 16 bytes; el struct de pose es 0x38 bytes, 0x7B4 es otro bloque que NO
  hay que pisar) hace que el proxy reproyecte un ojo según la cabeza. ✔ probado.
- Config (12 keys reales), script hashes, natives, version check (63/64/73).

## 🧱 Lo que FALTA (el muro real)

**AER (Alternate Eye Rendering) no completa los dos ojos.** Síntomas:
- Un ojo reproyecta con la cabeza (head-tracking funciona vía 0x77C). ✔
- El otro ojo queda congelado/plano.

Intentos de forzar la alternancia de ojo desde el contador de `RVRGetFrameDesc`:
- Contador propio incrementando → rompe la sincronía del proxy (peor).
- Híbrido (frame index del proxy + bit0 alternado) → un ojo, tarda ~1min, congela.
- Conclusión: **el ojo lo controla el frame index interno del proxy
  (`g_RVRData[0x34]`), que NO avanza en nuestro flujo.** Quién/cómo lo avanza
  está en el Present del proxy (no resuelto).

## Layout confirmado de g_RVRData (proxy r7)

| Offset | Contenido |
|--------|-----------|
| +0x00  | VR API state (1=OpenVR/SteamVR) |
| +0x34  | frame index interno del proxy (controla ojo AER) — NO avanza para nosotros |
| +0x5D8 | ring de pose (stride 0x38) que llena el proxy |
| +0x77C | pose "actual": quaternion [x,y,z,w] (16B) + extra hasta 0x7B3 (0x38 total) |
| +0x7B4 | bloque de matriz (NO escribir) |
| +0x890 | matriz de vista de salida, stride 64, 4 slots (la lee el proxy para render) |

## Funciones del proxy d3d11.dll (RVA, ImageBase 0x180000000)

| Export (GetProcAddress) | RVA | Rol real |
|---|---|---|
| RVRSeqCheck | 0x84560 | frame-begin (cl=0x55) — nuestro `RVRWaitAndTrackHMD` |
| RVRWaitAndTrackHMD | 0x84670 | pose getter bloqueante (WaitGetPoses) — nuestro `RVRGetPoseFrame` |
| RVRGetPoseDesc | 0x84B70 | (poseBuf, outDesc) 2 args — nuestro `RVRSeqCheck` |
| RVRGetFrameDesc | 0x84B30 | (counter, outBuf), bit0=ojo |
| g_RVRData | dato 0x36D710 | buffer compartido |
| g_fRVRGameProj | dato 0x36BDD0 | matriz proyección |

## GROUND TRUTH del proxy (de d3d11_disasm.txt, función 0x86DF6 = core RVRGetFrameDesc)

Confirmado por desensamble del proxy d3d11.dll:

| Dato | Dirección que LEE el proxy |
|---|---|
| Eye | `eye = (counterPasado + 1) & 1`  (0=izq, 1=der) |
| **View matrix** | `g_RVRData + 0x890 + eye*64` → **0x890 (izq), 0x8D0 (der)** — solo 2 slots |
| **Projection**  | `g_RVRData + 0xA10 + eye*64` → **0xA10 (izq), 0xA50 (der)** |
| Pose input | `g_RVRData + slot*0x1C + 0x77C` (el proxy la copia a 0x550 interno) |
| Frame index | el PROXY lo avanza solo: `inc edi; mov [g_RVRData+0x34], edi` |
| [0x3C] | umbral: `cmp [g_RVRData+0x3C], edi; jge` |
| Manager | `[g_RVRData + 0x8]` = puntero a RVRMgr (0x36D718) |
| Subida a GPU | `call 0x1F7370(recurso=[0x36BDC8]+0xC0, matriz)` |

### EL GATE DEL CONGELAMIENTO (0x86E14-0x86E4B)
El render fresco SOLO ocurre si AMBAS:
1. `manager->vtable[0x38]()` (en `[[g_RVRData+8]]+0x38`) devuelve **TRUE**, y
2. `g_RVRData[0x11]` (0x36D721) ≠ 0

Si falla cualquiera → salta a 0x86F6B → `[0x36BDC8] = 0` (limpia el recurso GPU) → **frame congelado**. Esto coincide con "se actualiza solo al pausar/cambiar hora".

→ Investigar: qué pone `g_RVRData[0x11]` y qué chequea `vtable[0x38]` del manager (probablemente "WaitGetPoses OK" / "frame de escena capturado"). El color de escena se captura por shaders (3Dmigoto), no por CopyResource.

NOTA: el layout de datos que escribe el ASI actual (view 0x890/0x8D0, proj-flip 0xA10/0xA50) coincide con lo que el proxy lee. El problema restante NO es el layout — es el gate de captura (vtable[0x38] / g_RVRData[0x11]).

## Próximos pasos para cerrar AER

1. RE del **Present hook del proxy** (3Dmigoto) para ver cómo y cuándo avanza
   `g_RVRData[0x34]` y cómo decide renderizar/submitir cada ojo. El proxy lee
   g_RVRData vía puntero base (no RIP-absoluto), así que hay que rastrear el
   registro base. Funciones candidatas: cluster en 0x86AF6-0x874D9 y el writer
   de pose en ~0x24500.
2. Confirmar si el offset de ojo (IPD ±) debe aplicarse a la matriz de 0x890
   por frame (AER del lado ASI) o lo hace el proxy.
3. Idealmente: conseguir el **fuente del R.E.A.L. mod** para el contrato exacto.

## Hotkeys de debug (build actual)
- F8 VR on/off · F11 recenter · B frame-begin 0x00/0x55 · H head-track on/off
- K convención quaternion (no usado en modo reproyección) · N/T/Y/End/J/Num.
