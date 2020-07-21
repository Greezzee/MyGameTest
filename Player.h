#pragma once
#include "Gameobject.h"
#include "InputManager.h"

enum PlayerType
{
    LeftPlayer, RightPlayer
};

class Player :
    public Gameobject
{
public:
    virtual void Init(Gameobject* owner);
    virtual void Init(Gameobject* owner, const std::string& tag);
    virtual void Update();
    virtual void Draw();
    virtual void Destroy();

private:
    Vector2F _speed;
    KeyboardKey _keys[PlayerKeysCount];

    PlayerType _type;
};

