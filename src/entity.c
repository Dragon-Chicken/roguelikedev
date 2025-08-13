#include "engine.h"

void entity_init(Entity *entity, char ch, int x, int y, int fg, int bg) {
  entity->ch = ch;
  entity->x = x;
  entity->y = y;
  entity->color = COMBINE_COLORS(fg, bg);
}

void entity_draw(Entity *entity, WINDOW *win) {
  engine_drawch(win, entity->ch, entity->x, entity->y, entity->color);
}
