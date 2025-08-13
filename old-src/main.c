#include "engine.h"

Entity player;
Entity npc;

Gamemap gamemap;

void initgame(Engine *engine) {
  entityinit(&player, engine->mainwin, 0, 0, '@', COLOR_WHITE, COLOR_BLACK);
  entityinit(&npc, engine->mainwin, 10, 10, 'e', COLOR_YELLOW, COLOR_BLACK);

  setbgcolor(stdscr, COLOR_BLACK, COLOR_RED);

  gamemapinit(&gamemap, 60, 40);
}

void updategame(Engine *engine) {

  switch (engine->input) {
    case 'q':
      exitengine(engine);
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

void drawgame(Engine *engine) {

  gamemapdraw(&gamemap, engine->mainwin);

  entitydraw(&player);
  entitydraw(&npc);
}

int main() {
  Engine engine;
  // sends the flow off to the engine
  int ret = mainengine(&engine);
  exitengine(&engine);

  if (ret != 0) {
    printf("Error: %d", ret);
  }

  return 0;
}
