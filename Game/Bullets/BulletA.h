#pragma once
#include "Bullet.h"
//!реярнбши хцпнбни назейр
class BulletA :
    public Bullet
{
public:
    virtual void Init(Gameobject* owner);
    virtual void Update();
private:
    int i;
};

