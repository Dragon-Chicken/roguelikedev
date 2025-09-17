#include "engine.h"

Entity player;
Entity npc;

Tile floor_tile, wall_tile, random_tile;
Map mainmap;

enum {
  floor,
  wall
};

void player_move(Entity *player, Map *map, int dx, int dy) {
  //printf("x%dy%di%d ", player->x, player->y, player->x + (player->y * map->width));

  // if in bounds x and y
  if (player->x + dx < 0 || player->x + dx >= map->width ||
      player->y + dy < 0 || player->y + dy >= map->height) {
    return;
  }

  // if next tile is not walkable
  if (tile_get(map, player->x + dx, player->y + dy).walk == false) {
    return;
  }

  player->x += dx;
  player->y += dy;
}

void init(Engine *engine) {
  entity_init(&player, '@', 24, 25, COLOR_WHITE, COLOR_BLUE);
  entity_init(&npc, '@', 25, 24, COLOR_YELLOW, COLOR_BLUE);

  tile_init(&floor_tile, ' ', COLOR_WHITE, COLOR_BLUE, true, true);
  tile_init(&wall_tile, '#', COLOR_RED, COLOR_BLACK, false, false);
  tile_init(&random_tile, '?', COLOR_GREEN, COLOR_BLACK, false, false);

  Tile tiletypes[3] = {floor_tile, wall_tile, random_tile};

  map_init(&mainmap, 80, 45, tiletypes, 3);
  map_fill(&mainmap, wall);

  generate_dungeon(&mainmap, floor, wall);
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

  entity_draw(&npc, stdscr);
  entity_draw(&player, stdscr);
}

int main() {
  
  engine_main();

  return 0;
}
