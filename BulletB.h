#pragma once
#include "Bullet.h"
class BulletB :
    public Bullet
{
public:
    virtual void Init(Gameobject* owner, const float angle);
    virtual void Update();
private:
    Vector2F _accel;
};

