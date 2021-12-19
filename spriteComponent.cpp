#include "spriteComponent.h"
#include "actor.h"
#include "game.h"


SpriteComponent::SpriteComponent(Actor* owner, drawOrder)
  :Component(owner)
  ,mDrawOrder{ drawOrder }
  ,mTexture{ nullptr }
  ,mTexWidth{ 0 }
  ,mTexHeight{ 0 }
{
  mOwner -> getGame() -> addSprite(this);
}