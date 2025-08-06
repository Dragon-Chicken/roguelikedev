#include "engine.h"

WINDOW *mainwin;
int input = 0;
bool isrunning = true;

bool checkkey(int key) {
  if (input == key) {
    return true;
  }
  return false;
}

// start ncurses
void initengine() {
  initscr();

  raw(); // gives complete raw input
  noecho();
  keypad(stdscr, TRUE); // adds arrow key support... D:

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);

  curs_set(0); // disable the cursor

  mainwin = newwin(50, 80, 0, 0);

  bkgd(COLOR_PAIR(2));
  wbkgd(mainwin, COLOR_PAIR(1));
  refresh();
  wrefresh(mainwin);

  while (isrunning) {
    // upcate call
    input = getch();
    updateengine();

    // draw call
    clear();
    wclear(mainwin);

    /*attron(COLOR_PAIR(0));
    clear();
    attroff(COLOR_PAIR(0));*/
    
    drawengine();

    refresh();
    wrefresh(mainwin);
  }
}

// end ncurses and other things
void exitengine() {
  isrunning = false;
  endwin();
}
