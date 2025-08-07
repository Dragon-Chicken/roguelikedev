#include "engine.h"

void gamemapinit(Gamemap *gamemap, int width, int height) {
  gamemap->width = width;
  gamemap->height = height;

  gamemap->tiles = (Tile *)malloc(sizeof(Tile) * width * height); // THIS SHIT'S NOT GETTING FREED

  Tile floor = newtile(true, true, '.', COLOR_RED, COLOR_GREEN);
  Tile wall = newtile(false, false, '#', COLOR_CYAN, COLOR_YELLOW);

  for (int i = 0; i < width * height; i++) {
    gamemap->tiles[i] = floor;
  }

  gamemap->tiles[31] = wall;
  gamemap->tiles[32] = wall;
  gamemap->tiles[33] = wall;

}

bool inbounds(Gamemap *gamemap, int x, int y) {
  return x >= 0 && x <= gamemap->width && y >= 0 && y <= gamemap->height ? true : false;
}

void gamemapdraw(Gamemap *gamemap, WINDOW *win) {
  for (int y = 0; y <= gamemap->height; y++) {
    for (int x = 0; x <= gamemap->width; x++) {
      Graphic *curdark = &gamemap->tiles[x+(y*gamemap->width)].dark;

      wattron(win, COLOR_PAIR(curdark->color));
      mvwprintw(win, y, x, "%c", curdark->ch);
      wattroff(win, COLOR_PAIR(curdark->color));
    }
  }
}
