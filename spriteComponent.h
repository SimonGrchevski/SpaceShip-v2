#ifndef SPRITECOMPONENT_19_12_2021_H
#define SPRITECOMPONENT_19_12_2021_H
#include "component.h"

class Actor;

class SpriteComponent : public Component
{
  public:
    SpriteComponent(Actor* owner, int drawOrder);

    const int getDrawOrder() const {return mDrawOrder; }
    const int getTexWidth() const { return mTexWidth; }
    const int getTexHeight() const { return mTexHeight; }


  private:
    Actor* mOwner;
    int mDrawOrder;
    SDL_Texture* mTexture;
    int mTexWidth;
    int mTexHeight;
}

#endif