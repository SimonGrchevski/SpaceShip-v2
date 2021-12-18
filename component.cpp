#include "component.h"
#include "actor.h"

Component::Component(Actor* owner, int UpdateOrder)
 :mOwner{ owner }
 ,mUpdateOrder{ UpdateOrder}
{
  mOwner->addComponent( this );
}

Component::~Component()
{
  mOwner -> removeComponent( this );
}

void Component::update(float)
{
}