#include "engine.h"

void room_init(Room *room, int x, int y, int width, int height) {
  room->x1 = x;
  room->y1 = y;
  room->x2 = x + width;
  room->y2 = y + height;

  room->cx = (room->x1 + room->x2) / 2;
  room->cy = (room->y1 + room->y2) / 2;
}

void generate_room(Map *map, Room *room) {
  for (int x = 0; x < room->x2 - room->x1; x++) {
    for (int y = 0; y < room->y2 - room->y1; y++) {
      map->tiles[(x + room->x1) + ((y + room->y1) * map->width)] = 0;
    }
  }
}

void draw_line(Map *map, int x1, int x2, int y1, int y2) {
  if (x1 > x2) {
    x1 ^= x2;
    x2 ^= x1;
    x1 ^= x2;
  }

  if (y1 > y2) {
    y1 ^= y2;
    y2 ^= y1;
    y1 ^= y2;
  }

  for (int x = x1; x < x2; x++) {
    for (int y = y1; y < y2; y++) {
    }
  }
}

void generate_con(Map *map, Room *rooma, Room *roomb) {
  int x1 = (rooma->x1 + rooma->x2) / 2;
  int y1 = (rooma->y1 + rooma->y2) / 2;

  int x2 = (roomb->x1 + roomb->x2) / 2;
  int y2 = (roomb->y1 + roomb->y2) / 2;

  int cornerx, cornery;
  
  if (false) {
    cornerx = x1;
    cornery = y2;
  } else {
    cornerx = x2;
    cornery = y1;
  }


  // randomly picks between x2 and y2
  // then goes from either x1 to x2, or y1 to y2

  /*
########
#     ##
#x### ##
#xxxx ##
########
   */
}

void generate_dungeon(Map *map, int floor, int wall) {
  Room rooma, roomb;
  room_init(&rooma, 20, 15, 10, 15);
  room_init(&roomb, 35, 10, 10, 15);

  generate_room(map, &rooma);
  generate_room(map, &roomb);

  generate_con(map, &rooma, &roomb);
}
