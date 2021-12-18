#ifndef VECTOR2D_18_12_2021_H
#define VECTOR2D_18_12_2021_H

class Vector2d
{
  public:
    Vector2d(float x = 0.0, float y = 0.0)
      :mX{ x }
      ,mY{ y }
    {}

    float mX;
    float mY;
};

#endif