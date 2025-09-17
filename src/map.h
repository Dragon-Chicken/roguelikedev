#include "engine.h"
#ifndef MAP_H
#define MAP_H

typedef struct Tile {
  char ch;
  int color;
  bool walk;
  bool trans;
} Tile;

typedef struct Map {
  int width;
  int height;
  int *tiles;
  Tile *tiletypes;

  // might be better to index an array of tile types rather than having an array of tiles
  // int tiles = w * h;
  // Tile tiletypes = Tile floor, Tile wall, etc;
} Map;

void map_init(Map *map, int width, int height, Tile *tiles, int tilescount);
void map_delete(Map *map);

void map_fill(Map *map, int tile);
void map_draw(Map *map, WINDOW *win);

void tile_init(Tile *tile, char ch, int fg, int bg, bool walk, bool trans);

Tile tile_get(Map *map, int x, int y);

#endif
