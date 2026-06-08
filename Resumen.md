# GTA V RealVR - Hallazgos de Ingeniería Inversa y Posibles Causas del Render Congelado

## Estado actual observado

Síntomas reportados:

* El HMD recibe imágenes ocasionales.
* La imagen permanece congelada la mayor parte del tiempo.
* Al pausar el juego puede aparecer un frame nuevo.
* Algunas veces actualiza únicamente un ojo.
* El tracking de cabeza parece funcionar.
* El problema principal parece estar en la entrega de imágenes al visor.

---

# Hallazgos encontrados en el código

## 1. El propio código describe exactamente el síntoma observado

Se encontró un comentario indicando:

```cpp
// frozen image symptom
// only occasionally
// does a single capture survive long enough
// to be presented
```

Esto indica que los autores ya habían identificado que:

* La captura ocurre.
* Algunos frames llegan al visor.
* La mayoría se pierden antes del submit.

---

# 2. Dependencia crítica de sceneResSlot

Existe una ruta similar a:

```cpp
sceneResSlot = base - 0x1948;
```

equivalente a:

```cpp
0x36BDC8
```

Posteriormente:

```cpp
if (*sceneResSlot != nullptr)
{
    bridge->RVRGetFrameDesc(...)
}
```

Conclusión:

Si este offset cambió entre versiones de GTA V:

```text
sceneResSlot == NULL
```

el pipeline VR jamás recibe la textura correcta.

---

# 3. Posible offset roto por actualización de GTA V

La investigación original parece haber identificado offsets mediante ingeniería inversa manual.

Posibles candidatos rotos:

```text
0x36BDC8
0x3C
0xE0
```

Todos son usados como estructuras compartidas con el proxy VR.

Debe verificarse si:

* siguen apuntando a la misma estructura
* siguen siendo válidos en la versión actual

---

# 4. El hook parece ejecutarse demasiadas veces

Comentario encontrado:

```cpp
ViewInverse runs ~27x/frame
```

Esto es sospechoso.

Un render estereoscópico normal debería dispararse:

```text
1 vez/frame
o
2 veces/frame
```

27 veces indica que probablemente el hook está siendo llamado desde:

* Shadow Pass
* Reflection Pass
* Water Pass
* Depth Pass
* Occlusion Pass
* Post Processing Pass

además del render principal.

Posible consecuencia:

El sistema VR recibe matrices válidas mezcladas con matrices irrelevantes.

---

# 5. El proyecto parece usar heurísticas para identificar el render correcto

Hay comentarios indicando:

```cpp
proxy's own scene-begin fire during gameplay
under investigation
```

Esto sugiere que:

* El proxy intenta detectar el inicio del render principal.
* La detección no es completamente confiable.
* Menús y pausa generan resultados diferentes.

Coincide perfectamente con el síntoma observado.

---

# 6. Existe una bandera interna desconocida

Se encontró:

```cpp
g_RVRData[0xE0]
```

y comentarios similares a:

```cpp
forcing g_RVRData[0xE0]=1
FROZE THE WHOLE GAME
```

Esto sugiere que:

```text
0xE0
```

podría representar:

* Capture Active
* Scene Active
* Render Pass Active
* Submit Enabled

Todavía no está completamente identificado.

---

# 7. Posible problema de sincronización de frame index

Se encontró una lógica relacionada con:

```cpp
g_RVRData + 0x3C
```

Los comentarios indican que el proxy:

```text
solo hace submit cuando detecta un nuevo valor
```

Si el contador no aumenta correctamente:

```text
frame 100
frame 100
frame 100
frame 100
```

el HMD puede ignorar los submits.

Síntoma resultante:

```text
imagen congelada
```

aunque la textura cambie.

---

# 8. Evidencia de matemáticas VR completas

Se identificaron rutinas SSE avanzadas:

```cpp
mulps
addps
subps
shufps
cmpleps
```

y operaciones de matrices 4x4.

Esto indica que:

* Quaternions
* Matrices
* Transformaciones de cámara

ya están implementadas.

No parece que el problema esté en el tracking.

---

# 9. Inicialización masiva de matrices

Existe una función que inicializa repetidamente:

```cpp
3F800000h
```

equivalente a:

```cpp
1.0f
```

en bloques consecutivos.

Probablemente:

```text
Matrix4x4
Transform Buffers
Eye Matrices
```

---

# 10. Registro dinámico de callbacks

Se encontraron llamadas indirectas:

```cpp
[1800232D8]
[1800232E0]
[1800232E8]
```

Patrón típico de:

```text
Hook registration
Event registration
Proxy callbacks
```

Debe identificarse exactamente qué eventos representan.

---

# Lo que NO encontré

No apareció evidencia clara de:

* OpenXR
* OpenVR
* Oculus SDK
* ID3D11Device::Present
* IDXGISwapChain::Present
* CreateTexture2D
* CopyResource
* ResolveSubresource

Por lo tanto parece que:

El repositorio analizado corresponde principalmente al ASI.

El trabajo pesado de VR probablemente ocurre dentro del proxy:

```text
d3d11.dll
```

que actualmente no fue analizado.

---

# Hipótesis principal

La causa más probable es una combinación de:

## Opción A

Offset roto:

```cpp
0x36BDC8
```

ya no apunta a la textura correcta.

---

## Opción B

El hook actual intercepta demasiados render passes.

```text
27 llamadas/frame
```

pero muy pocas corresponden al render final visible.

---

## Opción C

El proxy VR no detecta correctamente el render principal.

Por eso:

```text
menús = funciona a veces
pausa = funciona a veces
gameplay = casi nunca
```

---

## Opción D

Frame index desincronizado.

```cpp
g_RVRData + 0x3C
```

no coincide con el ritmo de Present.

---

# Próximos pasos recomendados

## Prioridad 1

Identificar quién escribe:

```cpp
0x36BDC8
```

No quién lo lee.

---

## Prioridad 2

Instrumentar logs sobre:

```cpp
g_RVRData[0x3C]
g_RVRData[0xE0]
```

por frame.

---

## Prioridad 3

Localizar el proxy:

```text
d3d11.dll
```

y analizar:

```cpp
Present
CopyResource
ResolveSubresource
Submit
```

---

## Prioridad 4

Registrar:

```cpp
RenderTarget
Width
Height
Format
```

cada vez que ViewInverse es ejecutado.

Esto permitirá descubrir cuál de las ~27 llamadas corresponde al render principal.

---

# Conclusión

La evidencia encontrada apunta a que el tracking VR ya funciona.

El fallo parece estar en el pipeline:

```text
GTA V
↓
Render Target
↓
Captura
↓
Proxy D3D11
↓
Frame Descriptor
↓
Submit
↓
HMD
```

y no en:

* quaternions
* matrices
* tracking
* pose del visor

La investigación debería concentrarse en:

```text
Render Target Discovery
Frame Synchronization
Present Hook
Proxy d3d11.dll
```

antes de seguir ajustando código de cámara o tracking.
