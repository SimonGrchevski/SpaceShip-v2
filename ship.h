#ifndef SHIP_19_12_2021_H
#define SHIP_19_12_2021_H

#include "actor.h"

class Game;

class Ship : public Actor
{
  public:
    Ship(Game* owner);

  private:
    float mRightSpeed;
    float mDownSpeed;
};

#endif