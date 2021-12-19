#ifndef GAME_18_12_2021_H
#define GAME_18_12_2021_H
#include <vector>
#include <SDL2/SDL.h>

class Actor;
class SpriteComponent;

class Game
{
  public:
    Game();
    bool initialize();
    void run();

    void addActor(Actor* actor);
    void removeActor(Actor* actor);

    void addSprite(SpriteComponent* sprite);

    Game(const Game&) = delete;
    Game(Game&&) = delete;
    Game& operator=(const Game&) = delete;
    Game& operator=(Game&&) = delete;

  private:
    SDL_Window* mWindow;
    SDL_Renderer * mRenderer;

    std::vector<Actor*> mActors;
    std::vector<Actor*>mPendingActors;

    std::vector<SpriteComponent*> mSprites;
    

    bool mIsRuning;
    uint32_t mTickCount;
    bool mUpdatingActors;

    void processInput();
    void updateGame();
    void generateOutput();

    void removeActorFromVector(Actor* actor, std::vector<Actor*>& actors);

    bool loadData();
    bool initVideo();
    bool initWindow();
    bool initRenderer();
    bool initImg();
};
#endif