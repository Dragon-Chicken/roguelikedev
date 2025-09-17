#include "engine.h"

void engine_drawch(WINDOW *win, int ch, int x, int y, int color) {
  wattron(win, COLOR_PAIR(color));
  mvwprintw(win, y, x, "%c", ch);
  wattroff(win, COLOR_PAIR(color));
}

void engine_main() {

  Engine engine;

  engine_init(&engine);

  while (engine.running) {
    engine_draw(&engine);
    engine_update(&engine);
  }

  engine_exit(&engine);
}

void engine_init(Engine *engine) {
  // ncurses
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);

  start_color();

  for (int fg = 0; fg < 8; fg++) {
    for (int bg = 0; bg < 8; bg++) {
      init_pair(COMBINE_COLORS(fg, bg), fg, bg);
    }
  }

  engine->running = true;
  engine->input = 0;
  engine->head.data = NULL;
  engine->head.next = NULL;

  init(engine);
}

void engine_update(Engine *engine) {
  engine->input = getch();

  update(engine);
}

void engine_draw(Engine *engine) {
  clear();

  draw(engine);

  refresh();
}

void engine_exit(Engine *engine) {
  endwin();
}
