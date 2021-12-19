#ifndef SPRITECOMPONENT_19_12_2021_H
#define SPRITECOMPONENT_19_12_2021_H
#include "component.h"

class Actor;

class SpriteComponent : public Component
{
  public:
    SpriteComponent(Actor* owner, int drawOrder);

    int getDrawOrder() const {return mDrawOrder; }
    int getTexWidth() const { return mTexWidth; }
    int getTexHeight() const { return mTexHeight; }



    SpriteComponent(const SpriteComponent&) = delete;
    SpriteComponent(SpriteComponent&&) = delete;
    SpriteComponent& operator=(const SpriteComponent&) = delete;
    SpriteComponent& operator=(SpriteComponent&&) = delete;

  private:
    Actor* mOwner;
    int mDrawOrder;
    SDL_Texture* mTexture;
    int mTexWidth;
    int mTexHeight;
};

#endif