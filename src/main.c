#include "engine.h"

Entity player;
Map mainmap;
Tile floor_tile;
Tile wall_tile;

void player_move(Entity *player, Map *map, int dx, int dy) {
  //printf("x%dy%di%d ", player->x, player->y, player->x + (player->y * map->width));
  if (player->x + dx < 0 || player->x + dx >= map->width) {
    return;
  }
  if (player->y + dy < 0 || player->y + dy >= map->height) {
    return;
  }
  if (map->tiles[player->x + dx + ((player->y + dy) * map->width)].walk == false) {
    return;
  }

  player->x += dx;
  player->y += dy;
}

void init(Engine *engine) {
  entity_init(&player, '@', 0, 0, COLOR_YELLOW, COLOR_BLUE);
  tile_init(&floor_tile, ' ', COLOR_WHITE, COLOR_BLUE, true, true);
  tile_init(&wall_tile, '#', COLOR_RED, COLOR_BLUE, false, false);
  map_init(&mainmap, 80, 45);
  map_fill(&mainmap, &floor_tile);

  mainmap.tiles[30 + 22 * mainmap.width] = wall_tile;
  mainmap.tiles[31 + 22 * mainmap.width] = wall_tile;
  mainmap.tiles[32 + 22 * mainmap.width] = wall_tile;
}

void update(Engine *engine) {
  switch (engine->input) {
    case 'q':
      engine->running = false;
      break;

    case 'h':
      player_move(&player, &mainmap, -1, 0);
      break;
    case 'l':
      player_move(&player, &mainmap, 1, 0);
      break;
    case 'k':
      player_move(&player, &mainmap, 0, -1);
      break;
    case 'j':
      player_move(&player, &mainmap, 0, 1);
      break;
  }
}

void draw(Engine *engine) {
  map_draw(&mainmap, stdscr);
  entity_draw(&player, stdscr);
}

int main() {
  
  engine_main();

  return 0;
}
