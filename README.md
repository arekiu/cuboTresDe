# 🎮 Cub3D

> A simplified 3D game engine using raycasting – inspired by Wolfenstein 3D
> Built from scratch in C using MiniLibX

---


## 🚀 Features

- 🧭 First-person 3D perspective based on raycasting
- 🔲 Wall rendering using DDA (Digital Differential Analysis) algorithm
- 🎨 Texture mapping on walls (North, South, East, West)
- ⬆️ Ceiling and floor color rendering
- 👣 Player movement (WASD) & rotation (← →)
- 🗺️ Map parsing from `.cub` file (custom format)
- 📦 Robust input validation and error handling

---

## 🧰 Technologies & Tools

- **C Language**
- **MiniLibX** (Graphics library provided by 42)
- **Raycasting** for 3D projection
- **Math**: Vectors, trigonometry, and linear interpolation
- **Makefile** for building

---

## Map Format

Each .cub file includes:

- Texture paths for all four directions

- RGB colors for ceiling and floor

- 2D grid map with walls (1), space (0), and player start position (N, S, E, W)

Example:
```
NO ./textures/wall_north.xpm
SO ./textures/wall_south.xpm
WE ./textures/wall_west.xpm
EA ./textures/wall_east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111
```

## 🛠️ Build & Run

### Clone repository
```
git clone https://github.com/arekiu/cub3d.git
cd cub3d
```
### Compile
```
make
```
### Run
```
./cub3D maps/map.cub
```

## Contributors

### JSlusark
### arekiu
