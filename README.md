<img width="1289" height="806" alt="image" src="https://github.com/user-attachments/assets/f93bcd8d-34a2-47c6-adc9-c1f70f049b69" />
A colorful, high-performance 2D physics simulation of bouncing bubbles, built purely in C using [Raylib](https://www.raylib.com/). 

# 🎮 Play the Game

**https://Anjas2005.github.io/Bubble_Animation/**

---

## ✨ Features

* Procedural generation of bubbles (random size, color, velocity)
* 2D physics with elastic boundary collisions
* Cross-platform: Desktop + WebAssembly

---

## 🌐 WebAssembly Build

Requires: `emsdk` + raylib web build

```bash
emcc -o index.html src/main.c -Os -Wall \
./raylib_web/lib/libraylib.a \
-I./raylib_web/include -I./include \
-s USE_GLFW=3 -s ASYNCIFY -DPLATFORM_WEB \
--shell-file minshell.html
```

---

## 💻 Desktop Build

### Linux

```bash
make
./game
```

### Windows (MinGW)

```bash
make
./game.exe
```

### macOS

```bash
make
./game
```

---

## 📜 Credits

* Simulation + WebAssembly setup: Anjas2005
* Based on Raylib Quickstart template (CC0 1.0)
