#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include "entity.h"
#include "tiles.h"
#include "gamemap.h"

#ifndef ENGINE_H
#define ENGINE_H

extern WINDOW *mainwin;
extern int input;

typedef struct Vec2 {
  int x;
  int y;
} Vec2;

// hands off main loop to the engine
int handoffengine();

// end ncurses and other things
void exitengine();

// these NOT defined by the engine
// they ARE called by the engine
void initgame();
void updategame();
void drawgame();

bool checkkey(int key);

// color stuff
int getcolorindex(int fg, int bg);
void setbgcolor(WINDOW *win, int fg, int bg);

#endif
