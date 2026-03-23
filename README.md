<img width="1289" height="806" alt="image" src="https://github.com/user-attachments/assets/f93bcd8d-34a2-47c6-adc9-c1f70f049b69" />
A colorful, high-performance 2D physics simulation of bouncing bubbles, built purely in C using [Raylib](https://www.raylib.com/). 

🎮 **[Play the Live Web Version Here](https://Anjas2005.github.io/Bubble_Animation/)**

## ✨ Features
* **Procedural Generation:** Spawns multiple bubbles with randomized sizes, colors, and initial velocities.
* **2D Physics:** Smooth, perfectly elastic screen-boundary collisions.
* **Cross-Platform:** Compiles natively for Desktop (Windows/Linux/macOS) and the Web (WebAssembly).

## 🌐 WebAssembly Build Instructions
To compile this project for the browser, you need the Emscripten SDK (`emsdk`) and the Raylib WebAssembly library.

```bash
# Compile using Emscripten with the minimal HTML shell
emcc -o index.html src/main.c -Os -Wall ./raylib_web/lib/libraylib.a -I./raylib_web/include -I./include -s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB --shell-file minshell.html
💻 Local Desktop Build Instructions
This project is structured using the Raylib-Quickstart template. Ensure you have a C compiler (GCC/MinGW) installed.

Windows (Using MinGW-W64)
Double click the build-MinGW-W64.bat file to generate the required build files.

Open your terminal (use W64devkit if you don't have GCC in your global path) in the project folder.

Run make.

Run the executable located in ./bin/Debug/.

Linux
Open a terminal in the project root.

Run make.

Run the executable located in ./bin/Debug/.
(Note: If the Makefile isn't generated, run cd build && ./premake5 gmake && cd .. first).

MacOS
Open a terminal and cd into the build folder.

Run ./premake5.osx gmake.

cd back to the root directory.

Run make.

📜 Credits & License
Simulation logic and WebAssembly configuration by Anjas2005.

Built on top of the Raylib-Quickstart template by Jeffery Myers (Licensed under CC0 1.0).
