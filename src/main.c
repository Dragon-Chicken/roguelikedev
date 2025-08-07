#include "engine.h"

Entity player;
Entity npc;

void updateengine() {

  switch (input) {
    case 'q':
      exitengine();
      break;

    case 'k':
      entitymove(&player, 0, -1);
      break;
    case 'j':
      entitymove(&player, 0, 1);
      break;
    case 'h':
      entitymove(&player, -1, 0);
      break;
    case 'l':
      entitymove(&player, 1, 0);
      break;
  }
}

void drawengine() {
  entitydraw(&player, mainwin);
  entitydraw(&npc, mainwin);
}

int main() {
  initengine();

  entityinit(&player, 0, 0, '@', COLOR_WHITE, COLOR_BLACK);
  entityinit(&npc, 10, 10, 'e', COLOR_YELLOW, COLOR_BLACK);

  setbgcolor(stdscr, COLOR_BLACK, COLOR_RED);

  // sends the flow off to the engine
  int ret = handoffengine();
  exitengine();

  if (ret != 0) {
    printf("Error: %d", ret);
  }

  return 0;
}
