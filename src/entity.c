#include "engine.h"

int entity_add(LLnode *head, Entity *entity) {
  if (head->next == NULL) {
    // this means that we have to loop through the linked list to find the last node
  }

  LLnode *newnode = (LLnode*) malloc(sizeof(LLnode));
  if (newnode == NULL) {
    return 1;
  }
  newnode->data = entity;
  newnode->next = NULL;

  head->next = newnode;

  return 0;
}

void entity_init(Entity *entity, char ch, int x, int y, int fg, int bg) {
  entity->ch = ch;
  entity->x = x;
  entity->y = y;
  entity->color = COMBINE_COLORS(fg, bg);
}

void entity_draw(Entity *entity, WINDOW *win) {
  engine_drawch(win, entity->ch, entity->x, entity->y, entity->color);
}
