#pragma once
#include "Bullet.h"
class BulletC :
    public Bullet
{
public:
    virtual void Init(Gameobject* owner, const float angle);
    virtual void Update();
private:
    Vector2F _accel;
    int i;
};



