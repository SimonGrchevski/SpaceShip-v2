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



    Actor(const Actor&) = delete;
    Actor(Actor&&) = delete;
    Actor& operator=(const Actor&) = delete;
    Actor& operator=(Actor&&) = delete;

  private:
    Game* mGame;
    std::vector<Component*> mComponents;

    Vector2d mPosition;
    float mScale;
    float mRotation;

    State mState;

};

#endif