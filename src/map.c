#include "engine.h"

void tile_init(Tile *tile, char ch, int fg, int bg, bool walk, bool trans) {
  tile->ch = ch;
  tile->color = COMBINE_COLORS(fg, bg);
  tile->walk = walk;
  tile->trans = trans;
}

Tile tile_get(Map *map, int x, int y) {
  // no bounds checking since don't have a return value to use :/
  return map->tiletypes[map->tiles[x + (y * map->width)]];
}

void map_init(Map *map, int width, int height, Tile *tiles, int tilescount) {
  map->width = width;
  map->height = height;
  map->tiles = malloc(sizeof(int) * (map->width * map->height));

  map->tiletypes = malloc(sizeof(Tile) * tilescount);

  for (int i = 0; i < tilescount; i++) {
    map->tiletypes[i] = tiles[i];
  }
}

void map_delete(Map *map) {
  map->width = -1;
  map->height = -1;
  free(map->tiles);
}

void map_fill(Map *map, int tile) {
  for (int x = 0; x < map->width; x++) {
    for (int y = 0; y < map->height; y++) {
      map->tiles[x + (y * map->width)] = tile;
    }
  }
}

void map_draw(Map *map, WINDOW *win) {
  for (int x = 0; x < map->width; x++) {
    for (int y = 0; y < map->height; y++) {
      Tile *tile = &map->tiletypes[map->tiles[x + (y * map->width)]];
      engine_drawch(win, tile->ch, x, y, tile->color);
    }
  }
}
