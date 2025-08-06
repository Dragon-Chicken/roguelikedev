#include "engine.h"

// ok so this is a really bad idea...
// it firstly allows the engine to add an entity more than once to this array
// next is that if an entity is deleted the pointer will still remain...
// I say just let the user draw the entities
//
// another way is to have an array of entities (not pointers)
// each time entityinit is called it returns a pointer to one of them
// and have a stack with indexes of free entities?
// though... it still needs dynamic allocation
Entity *entities[100]; // << this NEEDS to be allocated dynamically
int entityindex = 0;

void entityinit(Entity *entity, int x, int y, char ch) {
  entity->x = x;
  entity->y = y;
  entity->ch = ch;

  entities[entityindex] = entity;
  entityindex++;

  return;
}

void entitymove(Entity *entity, int dx, int dy) {
  entity->x += dx;
  entity->y += dy;

  return;
}

void entitydraw(Entity *entity, WINDOW *win) {
  mvwprintw(win, entity->y, entity->x, "%c", entity->ch);

  return;
}
