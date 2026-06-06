# GTA V OpenXR VR Mod - Architecture Specification

## Project Goal

Develop a modern VR mod for GTA V (latest versions) that:

* Works with current GTA V updates.
* Uses OpenXR instead of Oculus SDK.
* Supports Quest 2, Quest 3, Quest 3S, Valve Index, Pico and future OpenXR headsets.
* Minimizes dependency on hardcoded memory offsets.
* Uses DirectX 11 interception.
* Supports stereoscopic rendering.
* Can eventually support motion controllers.

---

# High Level Architecture

```text
GTAV.exe
│
├── ScriptHookV.dll
│
├── OpenVR.asi
│
│   ├── Bootstrap
│   ├── HookManager
│   ├── Renderer
│   ├── OpenXRManager
│   ├── CameraSystem
│   ├── InputSystem
│   ├── DepthExtractor
│   ├── StereoComposer
│   ├── ConfigManager
│   └── OverlayUI
│
└── DirectX 11 Runtime
```

---

# Core Modules

## Bootstrap

Responsible for startup and initialization.

### Responsibilities

* Load configuration.
* Initialize hooks.
* Initialize OpenXR.
* Initialize renderer.
* Start worker threads.

### Entry Point

```cpp
BOOL APIENTRY DllMain(...)
{
    CreateThread(
        nullptr,
        0,
        InitializeVR,
        nullptr,
        0,
        nullptr);
}
```

---

## HookManager

Responsible for all runtime hooks.

### Technologies

* MinHook
* PolyHook2 (optional)

### Hook Targets

```cpp
IDXGISwapChain::Present
ID3D11DeviceContext::OMSetRenderTargets
ID3D11DeviceContext::ClearDepthStencilView
```

### Responsibilities

* Install hooks.
* Remove hooks.
* Handle update-safe pattern scanning.

---

## Renderer

Main graphics subsystem.

### Responsibilities

* Obtain DirectX device.
* Obtain device context.
* Manage render targets.
* Create eye textures.
* Handle GPU resources.

### Resources

```cpp
ID3D11Device*
ID3D11DeviceContext*
IDXGISwapChain*
```

### Render Targets

```cpp
LeftEyeTexture
RightEyeTexture
DepthTexture
MirrorTexture
```

---

# OpenXR Manager

Handles all VR runtime communication.

### Responsibilities

* Create OpenXR instance.
* Create OpenXR session.
* Create reference spaces.
* Create swapchains.
* Poll headset state.

### OpenXR Objects

```cpp
XrInstance
XrSystemId
XrSession
XrSpace
XrSwapchain
```

### Per Frame Operations

```cpp
xrWaitFrame()
xrBeginFrame()

xrLocateViews()

xrEndFrame()
```

### Data Provided

```cpp
Head Position
Head Rotation
Eye Views
Projection Matrices
```

---

# Camera System

Controls GTA V camera behavior.

### Responsibilities

* Read GTA camera.
* Apply HMD rotation.
* Apply HMD translation.
* Build final VR camera.

### Sources

ScriptHookV camera natives:

```cpp
CAM::GET_GAMEPLAY_CAM_COORD()
CAM::GET_GAMEPLAY_CAM_ROT()
```

### Output

```text
Gameplay Camera
+
OpenXR Head Pose
=
VR Camera
```

---

# Coordinate Spaces

```text
World Space
│
├── Player Space
│
├── Head Space
│
├── Left Eye
│
└── Right Eye
```

---

# Input System

Converts VR controller actions into GTA actions.

### Inputs

```text
Trigger
Grip
Thumbstick
A/B/X/Y
Menu
```

### GTA Mapping

```text
Trigger -> Fire Weapon
Grip -> Aim
Thumbstick -> Movement
Menu -> Pause
```

### Future Features

* Two handed weapons
* Steering wheel simulation
* Vehicle interaction
* Gesture support

---

# Depth Extraction System

Most critical subsystem.

## Goal

Extract GTA V depth information.

### Potential Hook Points

```cpp
OMSetRenderTargets
ClearDepthStencilView
```

### Desired Resources

```cpp
ID3D11DepthStencilView
ID3D11Texture2D
```

### Output

```text
Color Buffer
+
Depth Buffer
```

Used by stereo compositor.

---

# Stereo Composer

Generates VR eye images.

## Mode A

### Native Stereo Rendering

```text
Render Scene Left Eye
Render Scene Right Eye
```

Pros:

* Highest quality

Cons:

* Roughly 2x GPU cost

---

## Mode B

### Depth Based Reprojection

```text
Color Buffer
+
Depth Buffer
↓
Stereo Shader
↓
Left Eye
Right Eye
```

Pros:

* Faster
* More update resistant

Cons:

* Reprojection artifacts

Recommended initial implementation.

---

# Shader Pipeline

## Vertex Shader

```hlsl
VSMain()
```

Responsible for:

* Geometry processing
* Coordinate transforms

---

## Pixel Shader

```hlsl
PSMain()
```

Responsible for:

* Final image output

---

## Stereo Reprojection Shader

```hlsl
DepthToStereoPS()
```

Responsibilities:

* Read color texture
* Read depth texture
* Reconstruct world position
* Generate left eye image
* Generate right eye image

---

# OpenXR Frame Submission

Per frame process:

```cpp
xrAcquireSwapchainImage()

Render Left Eye
Render Right Eye

xrReleaseSwapchainImage()
```

Submit:

```text
LeftEyeTexture
RightEyeTexture
```

To headset runtime.

---

# Overlay UI

Technology:

* ImGui
* ImGui DX11 Backend

### Information Displayed

```text
FPS
CPU Frame Time
GPU Frame Time
Head Tracking Status
IPD
OpenXR Runtime
Stereo Mode
Depth Buffer Status
```

---

# Configuration System

File:

```text
OpenVR.ini
```

Example:

```ini
[Graphics]
StereoMode=Depth
ResolutionScale=1.0

[VR]
IPD=0.064
SnapTurning=0

[Performance]
MotionSmoothing=1

[Debug]
Overlay=1
LogLevel=Verbose
```

---

# Update Resistant Design

Avoid:

```cpp
0x141AB1230
0x140AA4450
```

Hardcoded addresses.

Use:

```cpp
Pattern Scanning
Signature Scanning
```

Examples:

```cpp
48 8B ?? ?? ?? ?? ?? 48 85 C0

F3 0F 10 ?? ?? ?? ?? ??
```

Locate:

```text
Camera
Renderer
World
Viewport
```

At runtime.

---

# Logging System

File:

```text
OpenVR.log
```

Log categories:

```text
OpenXR
DirectX
Hooks
Camera
Input
Stereo
Depth
Performance
```

---

# Development Roadmap

## Phase 1

OpenXR bootstrap.

Deliverables:

* OpenXR initialization.
* VR headset detection.

---

## Phase 2

DX11 interception.

Deliverables:

* Present hook.
* Frame capture.

---

## Phase 3

Head tracking.

Deliverables:

* Camera synchronization.

---

## Phase 4

Depth extraction.

Deliverables:

* Depth buffer acquisition.
* Debug visualization.

---

## Phase 5

Stereo rendering.

Deliverables:

* Left eye.
* Right eye.

---

## Phase 6

VR optimization.

Deliverables:

* Foveated rendering.
* Motion smoothing.
* Dynamic resolution.

---

## Phase 7

Motion controllers.

Deliverables:

* Weapon aiming.
* Vehicle interaction.
* Full VR gameplay.

---

# Recommended Third Party Libraries

## Hooking

* MinHook
* PolyHook2

## VR

* OpenXR SDK

## Graphics

* DirectX 11

## UI

* Dear ImGui

## Configuration

* SimpleIni

## Logging

* spdlog

## Math

* DirectXMath

---

# Long Term Goal

Create a GTA V VR framework that survives future GTA V updates by relying primarily on:

* OpenXR
* DirectX 11 hooks
* Pattern scanning
* ScriptHookV

while minimizing dependencies on version-specific game internals.
