#include "game.h"


Game::Game()
  :mActors{}
  ,mPendingActors{}
  ,mIsRuning{true}
  ,mTickCount{0}
{
}

bool Game::initialize()
{
  return true;
}

void Game::run()
{
  while(mIsRuning)
  {
    
  }
}