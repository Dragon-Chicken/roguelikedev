#ifndef MAP_H
#define MAP_H

#include "engine.h"

typedef struct Tile {
  char ch;
  int color;
  bool walk;
  bool trans;
} Tile;

typedef struct Map {
  int width;
  int height;
  Tile *tiles;
} Map;

void map_init(Map *map, int width, int height);
void map_delete(Map *map);

void map_fill(Map *map, Tile *tile);
void map_draw(Map *map, WINDOW *win);

void tile_init(Tile *tile, char ch, int fg, int bg, bool walk, bool trans);

#endif
