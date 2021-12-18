#include "actor.h"
#include "game.h"

Actor::Actor(Game* game)
  :mGame{game}
{
  mGame -> addActor(this);
}