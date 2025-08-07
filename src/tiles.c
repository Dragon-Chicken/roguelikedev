#include "tiles.h"

Tile new_tile(bool walkable, bool transparent, char ch, int fg, int bg) {
  Tile tile;

  tile.walkable = true;
  tile.transparent = true;
  tile.dark.ch = ch;
  tile.dark.fg = fg;
  tile.dark.bg = bg;

  return tile;
}
