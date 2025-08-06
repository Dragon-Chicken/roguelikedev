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

  entityinit(&npc, 10, 10, 'e');
  entityinit(&player, 0, 0, '@');

  // sends everything off to the engine
  int ret = initengine();

  exitengine();

  return 0;
}
