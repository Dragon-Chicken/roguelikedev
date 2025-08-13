#include "engine.h"

/* internal funcs */
int initcall(Engine *engine) {
  // init ncurses and input
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE); // arrow keys are never used lol
  curs_set(0);

  // engine (the struct)
  engine->isrunning = true;
  engine->mainwin = newwin(50, 80, 0, 0);

  // colors
  if (!has_colors()) {
    printf("Terminal does not support colours");
    return 1;
  }
  start_color();

  for (int fg = 0; fg <= 7; fg++) {
    for (int bg = 0; bg <= 7; bg++) {
      init_pair(fg + (8 * bg), fg, bg);
    }
  }

  initgame(engine);

  return 0;
}

int updatecall(Engine *engine) {
  // upcate call
  engine->input = getch();
  updategame(engine);

  return 0;
}

int drawcall(Engine *engine) {
  // draw call
  clear();
  wclear(engine->mainwin);
  
  drawgame(engine);

  refresh();
  wrefresh(engine->mainwin);

  return 0;
}

int getcolorindex(int fg, int bg) {
  return fg + (8 * bg);
}

void setbgcolor(WINDOW *win, int fg, int bg) {
  wbkgd(win, COLOR_PAIR(getcolorindex(fg, bg)));
}

// hands off the loop from main() to the engine
int mainengine(Engine *engine) {

  initcall(engine);

  drawcall(engine); // need to do one draw call at the start

  while (engine->isrunning) {
    updatecall(engine);

    drawcall(engine);
  }

  return 0;
}

// end ncurses and other things
void exitengine(Engine *engine) {
  engine->isrunning = false;
  endwin();
}
