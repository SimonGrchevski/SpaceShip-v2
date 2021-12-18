#ifndef GAME_18_12_2021_H
#define GAME_18_12_2021_H
#include <vector>

class Actor;

class Game
{
  public:
  Game();
  bool initialize();
  void run();


  private:
  std::vector<Actor*> mActors;
  std::vector<Actor*>mPendingActors;
  bool mIsRuning;
  int mTickCount;
};
#endif