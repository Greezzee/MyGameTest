#pragma once
#include "../../Engine/Gameplay/Gameobject.h"
//!реярнбши хцпнбни назейр
class Bullet :
    public Gameobject
{
public:
    virtual void Init(Gameobject* owner);
    virtual void Update();
    virtual void Draw();
    virtual void Destroy();

protected:
    Vector2F _speed;
    float _life_time;
};

