#ifndef COMPONENT_18_12_2021_H
#define COMPONENT_18_12_2021_H

class Actor;

class Component
{
  public:
    Component(Actor* owner, int updateOrder = 100);
    virtual ~Component();
    virtual void update(float);

    Actor* getOwner() const { return mOwner; }
    int getUpdateOrder() const { return mUpdateOrder;}

    Component(const Component&) = delete;
    Component(Component&&) = delete;
    Component& operator=(const Component&) = delete;
    Component& operator=(Component&&) = delete;

  private:
    Actor* mOwner;
    int mUpdateOrder;
};

#endif