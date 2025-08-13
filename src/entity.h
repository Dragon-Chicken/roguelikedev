#ifndef ENTITY_H
#define ENTITY_H

#include "engine.h"

typedef struct Entity {
  char ch;
  int x;
  int y;
  int color;
} Entity;

void entity_init(Entity *entity, char ch, int x, int y, int fg, int bg);
void entity_draw(Entity *entity, WINDOW *win);

#endif
