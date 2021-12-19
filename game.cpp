#include "game.h"
#include "ship.h"
#include <algorithm>
#include <SDL2/SDL_image.h>

Game::Game()
  :mWindow{ nullptr }
  ,mRenderer{ nullptr }
  ,mActors{}
  ,mPendingActors{}
  ,mIsRuning{true}
  ,mTickCount{0}
  ,mUpdatingActors{ false }
{
}

bool Game::initialize()
{
  return (
    initVideo() && initWindow() && initRenderer() && initImg() && loadData() );
}

bool Game::loadData()
{
  Ship* ship{ new Ship(this) };
  return true;
}

void Game::run()
{
  while(mIsRuning)
  {

  }
}

void Game::addSprite(SpriteComponent* sprite)
{
  const int order{ sprite -> getDrawOrder() };
  auto iter{ mSprites.begin() };
  for(; iter != mSprites.end(); ++iter )
  {
    if(order < (*iter)-> getDrawOrder() )
      break;
  }
  mSprites.insert(iter,sprite);
}

void Game::addActor(Actor* actor)
{
  mUpdatingActors ? mPendingActors.emplace_back(actor) : mActors.emplace_back(actor);
}

void Game::removeActor(Actor* actor)
{
  removeActorFromVector(actor, mActors);
  removeActorFromVector(actor, mPendingActors);
}

void Game::removeActorFromVector(Actor* actor, std::vector<Actor*>& actors)
{
  auto iter{ std::find(actors.begin(), actors.end(), actor ) };
    if(iter != actors.end() )
    {
      std::iter_swap(iter, actors.end() - 1);
      actors.pop_back();
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

