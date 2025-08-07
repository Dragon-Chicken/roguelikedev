#include "engine.h"

/* external vars */
WINDOW *mainwin;
int input = 0;

/* internal vars */
bool isrunning = true;

/* internal funcs */
int initcall() {
  // init ncurses and input
  initscr();

  raw(); // gives complete raw input
  noecho();
  keypad(stdscr, TRUE); // adds arrow key support... D:

  curs_set(0); // disable the cursor

  // creates maingame window
  mainwin = newwin(50, 80, 0, 0);

  // colors
  if (!has_colors()) {
    printf("Terminal does not support colours");
    return 1;
  }
  start_color();

  for (int fg = 0; fg <= 7; fg++) {
    for (int bg = 0; bg <= 7; bg++) {
      // yes I know this is not the best way to do this but I don't care.
      init_pair(fg + (bg * 10), fg, bg);
    }
  }

  return 0;
}

int updatecall() {
  // upcate call
  input = getch();
  updateengine();

  return 0;
}

int drawcall() {
  // draw call
  clear();
  wclear(mainwin);
  
  drawengine();

  refresh();
  wrefresh(mainwin);

  return 0;
}


/* external funcs */
bool checkkey(int key) {
  if (input == key) {
    return true;
  }
  return false;
}

int getcolorindex(int fg, int bg) {
  int indexofcolor = fg + (bg * 10);

  return indexofcolor;
}

void setbgcolor(int fg, int bg) {
  bkgd(COLOR_PAIR(getcolorindex(fg, bg)));
  return;
}

// hands off the loop from main() to the engine
int handoffengine() {
  initcall();

  drawcall(); // need to do one draw call at the start

  while (isrunning) {
    updatecall();

    drawcall();
  }

  return 0;
}

// end ncurses and other things
void exitengine() {
  isrunning = false;
  endwin();
}
