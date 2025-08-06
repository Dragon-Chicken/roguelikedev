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
int initengine() {
  /* init ncurses and input */
  initscr();

  raw(); // gives complete raw input
  noecho();
  keypad(stdscr, TRUE); // adds arrow key support... D:

  curs_set(0); // disable the cursor

  /* colors */
  if (!has_colors()) {
    printf("Terminal does not support colours");
    return 1;
  }

  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, COLOR_BLACK);

  /* windows and window color inits */
  mainwin = newwin(50, 80, 0, 0);

  bkgd(COLOR_PAIR(2));
  wbkgd(mainwin, COLOR_PAIR(1));

  drawengine(); // have to call to remove that blank start frame

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

  return 0;
}

// end ncurses and other things
void exitengine() {
  isrunning = false;
  endwin();
}
