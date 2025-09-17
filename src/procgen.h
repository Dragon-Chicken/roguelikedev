#include "engine.h"

#ifndef PROCGEN_H
#define PROCGEN_H

typedef struct Room {
  int x1;
  int y1;
  int x2;
  int y2;

  // center of rooms
  int cx;
  int cy;
} Room;

void room_init(Room *room, int x, int y, int width, int height);
void generate_dungeon(Map *map, int floor, int wall);

#endif
