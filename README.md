# FRACTOL

This project consists to create a small fractal exploration software.
[What is a Fractal ?](https://en.wikipedia.org/wiki/Fractal)

### Installing

Clone the project

```
git clone https://github.com/BABAK0T0/WOLF3D
```

Then execute Makefile to create an executable

```
make re
```

### Running

Run basic map

```
./wolf3d
```

You could change map directly in code `src/wolf3d.c`, then execute `make` again and run

```
make && ./wolf3d
```

### Events

KEYS | DESCRIPTION
:-- |:-:| --:
<kbd>ESC</kbd>| Exit the program
<kbd>↑</kbd> | Explore map - UP
<kbd>↓</kbd> | Explore map - DOWN
<kbd>←</kbd> | Explore map - LEFT
<kbd>→</kbd> | Explore map - RIGHT
<kbd>R</kbd> | Reset

### Example

![wolf3d](./wolf3d.png "WOLF3D_Raycasting")

### Deployment

Develop for UNIX systems

### Built With

* [Minilibx] - The framework for graphical user interface development

