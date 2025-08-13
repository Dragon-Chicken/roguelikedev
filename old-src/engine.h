#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include "entity.h"
#include "tiles.h"
#include "gamemap.h"

#ifndef ENGINE_H
#define ENGINE_H

//extern WINDOW *mainwin;
//extern int input;

typedef struct Vec2 { // not used
  int x;
  int y;
} Vec2;

typedef struct Engine {
  WINDOW *mainwin;
  int input;
  bool isrunning;
} Engine;

// hands off main loop to the engine
int mainengine(Engine *engine);

// end ncurses and other things
void exitengine(Engine *engine);

// these NOT defined by the engine
// they ARE called by the engine
void initgame(Engine *engine);
void updategame(Engine *engine);
void drawgame(Engine *engine);

bool checkkey(int key);

// color stuff
int getcolorindex(int fg, int bg);
void setbgcolor(WINDOW *win, int fg, int bg);

#endif
