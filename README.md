# POLYGLOT HYPEROBJECT

POLYGLOT HYPEROBJECT is a visually intense, living 3D experiment built as a single HTML page. It renders a breathing, evolving, silver wireframe entity that feels alive — constantly moving, pulsing, wobbling, and reacting over time.

The project intentionally combines multiple technologies in one place to demonstrate a stable but extreme real-time visual system running entirely in the browser.

Technologies used:
- Three.js for real-time 3D rendering
- GLSL shaders for vertex displacement and breathing effects
- Python (via Pyodide) running asynchronously in the browser to influence motion
- Rust (conceptual / WASM-style) math logic mirrored as it would be in a real Rust → WASM pipeline

The result is a dynamic “hyperobject” that looks engineered, organic, and sentient while remaining stable and performant.

WHAT IT DOES

- Renders a high-detail silver wireframe 3D form
- Applies continuous vertex displacement for breathing and internal turbulence
- Uses layered rotation, wobble, scale pulsing, and spatial drift to feel alive
- Loads Python asynchronously without blocking rendering
- Remains stable over time (no geometry rebuilding, no disappearing objects)

Everything runs client-side in the browser.

HOW TO RUN IT

Requirements:
- Python 3
- A modern browser (Chrome or Firefox recommended)

Setup:
Create a folder containing:
- index.html
(Optional) README.md

Start a local server from inside the folder:
python -m http.server

You should see:
Serving HTTP on :: port 8000

Open a browser and navigate to:
http://localhost:8000

IMPORTANT:
The file must be served over HTTP. Opening index.html directly with file:// will not work because ES modules and Pyodide require a local server.

WHAT YOU SHOULD SEE

- A dark background
- A silver wireframe 3D object centered on screen
- Continuous motion including rotation, breathing, turbulence, and subtle drifting
- After a few seconds, Python finishes loading and increases motion complexity

In the browser console you should see:
🐍 Python energy online

NOTES

- Python runs fully in the browser using Pyodide
- Rust code is included conceptually to mirror a real Rust → WASM workflow
- Geometry is never rebuilt to ensure long-term visual stability
- All motion is driven by shaders, transforms, and time-based math

CUSTOMIZATION IDEAS

- Increase geometry detail for denser wireframes
- Adjust shader displacement values for more aggressive motion
- Add post-processing effects such as bloom or trails
- Make the motion audio-reactive
- Replace the Rust mirror logic with a real compiled WASM module

SUMMARY

This project is an art piece, a technical experiment, and a stable foundation for pushing real-time 3D visuals further. It is intentionally over-the-top, but carefully architected to remain solid.

Enjoy the hyperobject.


