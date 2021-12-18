#include "game.h"

int main()
{
  Game game;
  if( game.initialize() )
    game.run();
  return 0;
}