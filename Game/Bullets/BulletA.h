#pragma once
#include "Bullet.h"
class BulletA :
    public Bullet
{
public:
    virtual void Init(Gameobject* owner);
    virtual void Update();
private:
    int i;
};

