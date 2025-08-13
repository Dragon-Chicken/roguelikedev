#include "engine.h"

void entityinit(Entity *entity, WINDOW *win, int x, int y, char ch, int fg, int bg) {
  entity->x = x;
  entity->y = y;
  entity->ch = ch;
  entity->color = getcolorindex(fg, bg);
  entity->win = win;
}

void entitymove(Entity *entity, int dx, int dy) {
  entity->x += dx;
  entity->y += dy;
}

void entitydraw(Entity *entity) {
  wattron(entity->win, COLOR_PAIR(entity->color));
  mvwprintw(entity->win, entity->y, entity->x, "%c", entity->ch);
  wattroff(entity->win, COLOR_PAIR(entity->color));
}
