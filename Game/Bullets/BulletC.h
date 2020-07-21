#pragma once
#include "Bullet.h"
//!реярнбши хцпнбни назейр
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



