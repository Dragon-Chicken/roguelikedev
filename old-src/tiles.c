#include "engine.h"

Tile newtile(bool walkable, bool transparent, char ch, int fg, int bg) {
  Tile tile;

  tile.walkable = true;
  tile.transparent = true;
  tile.dark.ch = ch;
  tile.dark.color = getcolorindex(fg, bg);

  return tile;
}
