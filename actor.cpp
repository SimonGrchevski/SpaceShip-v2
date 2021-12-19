#include "actor.h"
#include "game.h"
#include "component.h"
#include <algorithm>

Actor::Actor(Game* game)
  :mGame{game}
  ,mComponents{}
  ,mPosition{}
  ,mScale{0.0f}
  ,mRotation{0.0f}
  ,mState{ Active }
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
  auto iter{ std::find( mComponents.begin(), mComponents.end(), component )};
  if( iter != mComponents.end())
    mComponents.erase(iter);
}