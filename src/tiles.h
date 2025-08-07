// this file needs to be remade once I understand whatever tf is going on in the tutorial (part 2)

#ifndef TILES_H
#define TILES_H

typedef struct Graphic {
  char ch;
  int color;
} Graphic;

typedef struct Tile {
  bool walkable;
  bool transparent;
  Graphic dark;
} Tile;

Tile newtile(bool walkable, bool transparent, char ch, int fg, int bg);

#endif
