#include "game.h"
#include <SDL2/SDL_image.h>

Game::Game()
  :mWindow{ nullptr }
  ,mRenderer{ nullptr }
  ,mActors{}
  ,mPendingActors{}
  ,mIsRuning{true}
  ,mTickCount{0}
{
}

bool Game::initialize()
{
  return (
    initVideo() && initWindow() && initRenderer() && initImg() && loadData() );
}

bool Game::loadData()
{
  // loading the data
  return true;
}

void Game::run()
{
  while(mIsRuning)
  {

  }
}

bool Game::initVideo()
{
  if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) != 0)
  {
    SDL_Log("Failed to initialze video %s", SDL_GetError() );
    return false;
  }
  return true;
}

bool Game::initWindow()
{
  mWindow = SDL_CreateWindow("spaceShip", 100,100,1024,768,0);
  if(!mWindow)
  {
    SDL_Log("Failed to initialize the window %s", SDL_GetError() );
    return false;
  }
  return true;
}

bool Game::initRenderer()
{
  mRenderer = SDL_CreateRenderer(mWindow,-1,
  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(!mRenderer)
  {
    SDL_Log("Failed to initialize renderer %s", SDL_GetError() );
    return false;
  }
  return true;
}

bool Game::initImg()
{
  if( IMG_Init(IMG_INIT_PNG) == 0 )
  {
    SDL_Log("Failed to initialize image %s", SDL_GetError() );
    return false;
  }
  return true;
}

