#include "engine.h"
#ifndef ENTITY_H
#define ENTITY_H

typedef struct Entity {
  char ch;
  int x;
  int y;
  int color;
} Entity;

typedef struct LLnode {
  Entity *data;
  struct LLnode *next;
} LLnode;

int entity_add(LLnode *head, Entity *entity);

void entity_init(Entity *entity, char ch, int x, int y, int fg, int bg);
void entity_draw(Entity *entity, WINDOW *win);

#endif
