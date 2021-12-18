#ifndef ACTOR_18_12_2021_H
#define ACTOR_18_12_2021_H

#include "vector2d.h"
#include <vector>

class Game;
class Component;

class Actor
{
  public:

    enum State 
    {
      Active,
      Paused,
      Dead
    };

    Actor(Game* game);
    ~Actor();


    void addComponent(Component* component);
    void removeComponent(Component* component);

  private:
    Game* mGame;
    std::vector<Component*> mComponents;

    Vector2d mPosition;
    float mScale;
    float mRotation;

    State mState;

};

#endif