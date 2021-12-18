#ifndef ACTOR_18_12_2021_H
#define ACTOR_18_12_2021_H
#include <vector>

class Game;
class Component;

class Actor
{
  public:
    Actor(Game* game);
    ~Actor();


    void addComponent(Component* component);
    void removeComponent(Component* component);

  private:
    Game* mGame;
    std::vector<Component*> mComponents;
};

#endif