# FdF

## Overview

FdF (Fil de Fer) is a wireframe viewer written in C. It allows users to display 3D representations of landscapes from 2D height maps. The project focuses on graphical representation and rendering techniques.

## Features

- Load and display 3D wireframe models from 2D height maps.
- Rotate, zoom, and pan the models for better visualization.
- Adjustable rendering parameters for better control over the display.
- Lightweight and efficient rendering using C and Makefile.
- Multi-core processing using threads for improved performance and responsiveness, for multi-core systems.

### Prerequisites

- A C compiler (gcc recommended).
- Make utility.
- Libraries: `mlx` (MiniLibX), `X11`, and `Xext`, see https://harm-smits.github.io/42docs/libs/minilibx.

### Clone the Repository

```sh
git clone https://github.com/K0UM0RI/FdF.git
cd FdF
```

### Build the Project

```sh
make
```

## Usage

```sh
./fdf [path_to_height_map_file]
```

### Example

```sh
./fdf maps/42.fdf
```

## Controls

- `Arrow Keys`: Move the model.
- `Scroll`: Zoom in/out.
- `Middle click`: Reset zoom.
- `Mouse hold + Move`: Rotate the model.
- `ESC`: Exit the program.
- `+/-`: Modify Altitude Scale Factor.
- `R` : Reset Modification.
- `P` : Isometric projection.
- `I` : Parallel projection (from the top).
  
## Dependencies

- `MiniLibX`: For graphical rendering.
- `X11`: For handling window and input events.
- `Xext`: For extended X Window System features.

## Project Structure

- `[src]/` - Source code files.
- `maps/` - Example height map files.
- `Makefile` - Build script.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.
