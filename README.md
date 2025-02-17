# cub3D - 3D Raycasting Engine  

## 📜 Overview  
**cub3D** is a **raycasting-based** 3D graphics project inspired by **Wolfenstein 3D**. It is built using **MiniLibX** and written in **C**. The project renders a **first-person perspective** of a maze and allows the player to navigate using keyboard controls.  

## 🎯 Features  
- **Raycasting-based 3D rendering**  
- **MiniLibX integration** for window and graphics handling  
- **Player movement with smooth rotation**  
- **Wall textures based on orientation (N/S/E/W)**  
- **Customizable floor and ceiling colors**  
- **Supports `.cub` map files**  

### ✅ Bonus Features  
- **Minimap implementation** 🗺️  
  - Displays the player's position and surroundings.  
  - Includes **wall collision detection** to prevent movement through walls.  
- **Wall collisions** 🚧  
  - Ensures the player cannot pass through solid objects.  
- **Additional enhancements**  
  - Doors that open and close 🚪  
  - Mouse-controlled view rotation 🎯  
  - Animated sprites for a dynamic environment 🎞️  

## 🏗️ Installation  
To build and run the project, use the provided **Makefile**:  

```bash
make
./cub3D maps/example.cub
```
![Screen2](https://github.com/user-attachments/assets/135a8cf2-6633-491b-8d8a-fc1309be96ec)

## 🎮 Controls  
| Key | Action |
|------|--------|
| `W` | Move forward |
| `S` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `← →` | Rotate view left/right |
| `ESC` | Exit the game |

## 📌 Map Format (`.cub`)  
A `.cub` file defines the game environment, including textures, colors, and the maze layout.  

Example:  
```
NO ./textures/north.xpm  
SO ./textures/south.xpm  
WE ./textures/west.xpm  
EA ./textures/east.xpm  

F 220,100,0  
C 225,30,0  

111111  
1001N1  
101001  
110011  
111111  
```
- `1` → Wall  
- `0` → Empty space  
- `N/S/E/W` → Player spawn point  
