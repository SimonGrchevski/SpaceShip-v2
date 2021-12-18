#include "actor.h"
#include "game.h"

Actor::Actor(Game* game)
  :mGame{game}
{
  mGame -> addActor(this);
}

Actor::~Actor()
{
  mGame -> removeActor(this);
  while(!mComponents.empty())
    delete mComponents.back();
}

void Actor::removeComponent(Component* component)
{
  auto iter{ std::find( mComponents.begin(), mComponents.end(), component )}
  if( iter != mComponents.end())
    mComponent.erase(iter);
}