#include <ncurses.h>
#include <stdlib.h>

#ifndef ENGINE_H
#define ENGINE_H

#include "entity.h"
#include "map.h"
#include "procgen.h"

#define COMBINE_COLORS(a, b) (a + (b * 8))

typedef struct Engine {
  bool running;
  int input;
  LLnode head; // entity linked list head
} Engine;

void engine_main();

void engine_init(Engine *engine);
void engine_update(Engine *engine);
void engine_draw(Engine *engine);

void engine_exit(Engine *engine);

void init(Engine *engine);
void update(Engine *engine);
void draw(Engine *engine);

void engine_drawch(WINDOW *win, int ch, int x, int y, int color);

#endif
