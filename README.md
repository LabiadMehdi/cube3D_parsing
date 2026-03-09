*This project has been created as part of the 42 curriculum by ipafnuto, ellabiad*

# cub3D

> A 3D maze renderer inspired by Wolfenstein 3D, built from scratch in C using raycasting.

---

## Description

cub3D renders a 3D world from a 2D map using raycasting, the same technique behind Wolfenstein 3D, one of the first ever first-person games. The scene is rendered column by column by casting rays from the player's viewpoint to calculate wall distances and simulate depth.

The project is split into two core parts :
- **Rendering engine** — raycasting, textures and scene display (ipafnuto)
- **Parser** — map file reading, validation, error handling and configuration extraction (ellabiad)

---

## Instructions

**Compile :**
```bash
make
```

**Run :**
```bash
./cub3D path_to_the_file.cub
```

**Map file format :**
- Declare `NO` `SO` `WE` `EA` textures and `F` (floor) `C` (ceiling) colors in any order
- The map must always be **last** in the file
- Colors use RGB format : `F 220,100,0`
- The map must be fully enclosed by walls (`1`)

**Example of a valid `.cub` file :**
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

1111111111111111111111111111
1000000000110000000000000001
1011000001110000000000001111
10010000000000000000E0001
1111111111111111111111111
```

**Controls :**

| Key | Action |
|-----|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Move left |
| `D` | Move right |
| `ESC` | Quit |

---

## Resources

- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) the reference guide used to understand and implement the raycasting engine
- [42 School Subject] official project guidelines
- [AI] AI was used for research purposes and generating tests for map parsing
