#include <ncurses.h>
#include <stdbool.h>
#include "entity.h"

#ifndef ENGINE_H
#define ENGINE_H

extern WINDOW *mainwin;
extern int input;

typedef struct Vec2 {
  int x;
  int y;
} Vec2;

int initengine();

// hands off main loop to the engine
int handoffengine();

// end ncurses and other things
void exitengine();

// both are NOT defined by the engine
void updateengine();
void drawengine();

bool checkkey(int key);

// color stuff
int getcolorindex(int fg, int bg);
void setbgcolor(WINDOW *win, int fg, int bg);

#endif
