#include "engine.h"

Vec2 player;

void updateengine() {
  switch (input) {
    case 'q':
      exitengine();
      break;

    case 'k':
      player.y--;
      break;
    case 'j':
      player.y++;
      break;
    case 'h':
      player.x--;
      break;
    case 'l':
      player.x++;
      break;
  }
/*  if (checkkey('q')) {
    exitengine();
  }

  if (checkkey(KEY_UP) || checkkey('k')) {
    player.y -= 1;
  }
  if (checkkey(KEY_DOWN) || checkkey('j')) {
    player.y += 1;
  }
  if (checkkey(KEY_LEFT) || checkkey('h')) {
    player.x -= 1;
  }
  if (checkkey(KEY_RIGHT) || checkkey('l')) {
    player.x += 1;
  } */
}

void drawengine() {
  mvwprintw(mainwin, player.y, player.x, "@");
}

int main() {
  player.x = 0;
  player.y = 0;

  // sends everything off to the engine
  initengine();

  exitengine();

  return 0;
}
