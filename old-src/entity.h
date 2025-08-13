#ifndef ENTITY_H
#define ENTITY_H

#include "engine.h"

typedef struct Entity {
  int x;
  int y;
  char ch;
  int color;
  WINDOW *win;
} Entity;

// maybe a better idea would be to call malloc instead of passing around structs?
// or better yet just use a pointer?
void entityinit(Entity *entity, WINDOW *win, int x, int y, char symb, int fg, int bg);

void entitymove(Entity *entity, int dx, int dy);

void entitydraw(Entity *entity);

#endif
