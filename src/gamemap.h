#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "engine.h"

typedef struct Gamemap {
  int width;
  int height;

  Tile *tiles;
} Gamemap;

void gamemapinit(Gamemap *gamemap, int width, int height);
bool inbounds(Gamemap *gamemap, int x, int y);
void gamemapdraw(Gamemap *gamemap, WINDOW *win);

#endif
