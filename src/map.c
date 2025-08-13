#include "engine.h"

void tile_init(Tile *tile, char ch, int fg, int bg, bool walk, bool trans) {
  tile->ch = ch;
  tile->color = COMBINE_COLORS(fg, bg);
  tile->walk = walk;
  tile->trans = trans;
}

void map_init(Map *map, int width, int height) {
  map->width = width;
  map->height = height;
  map->tiles = malloc(sizeof(Tile) * (map->width * map->height));
}

void map_delete(Map *map) {
  map->width = -1;
  map->height = -1;
  free(map->tiles);
}

void map_fill(Map *map, Tile *tile) {
  for (int x = 0; x < map->width; x++) {
    for (int y = 0; y < map->height; y++) {
      map->tiles[x + (y * map->width)] = *tile;
    }
  }
}

void map_draw(Map *map, WINDOW *win) {
  for (int x = 0; x < map->width; x++) {
    for (int y = 0; y < map->height; y++) {
      Tile *tile = &map->tiles[x + (y * map->width)];
      engine_drawch(win, tile->ch, x, y, tile->color);
    }
  }
}
