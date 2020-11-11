# WOLF3D

This project consists to create a basic version of Wolfenstein using Raycasting technique

[What is a Raycasting ?](https://en.wikipedia.org/wiki/Ray_casting)

[What is Wolfenstein ?](https://en.wikipedia.org/wiki/Wolfenstein_(2009_video_game))

### Installing

Clone the project

```
git clone https://github.com/BABAK0T0/WOLF3D
```

If you don't have SDL2, run this sript, more details [here](https://wiki.libsdl.org/Installation)

```
./install_sdl2.sh
```

Then execute Makefile to create an executable

```
make
```

### Running

An executable is available in deposit, if you can't `make` the Makefile

```
chmod u+x wolf3d && ./wolf3d
```

You could change map directly in code `src/wolf3d.c`, then execute `make` again and run

```
make && ./wolf3d
```

### Events

| KEYS | DESCRIPTION |
| --- | --- |
| <kbd>ESC</kbd>| Exit the program |
| <kbd>↑</kbd> | Explore map - UP |
| <kbd>↓</kbd> | Explore map - DOWN |
| <kbd>←</kbd> | Explore map - LEFT |
| <kbd>→</kbd> | Explore map - RIGHT |
| <kbd>R</kbd> | Reset |

### Sound

Interstellar Main Theme - Soundtrack by Hans Zimmer

### Example

![wolf3d](./wolf3d.png "WOLF3D_Raycasting")

### Built With

* [SDL 2.0](https://www.libsdl.org/) - The framework for graphical user interface development

