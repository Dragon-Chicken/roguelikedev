#ifndef ENTITY_H
#define ENTITY_H

typedef struct Entity {
  int x;
  int y;
  char ch;
  int color;
} Entity;

// maybe a better idea would be to call malloc instead of passing around structs?
// or better yet just use a pointer?
void entityinit(Entity *entity, int x, int y, char symb, int fg, int bg);

void entitymove(Entity *entity, int dx, int dy);

void entitydraw(Entity *entity, WINDOW *win);

#endif
