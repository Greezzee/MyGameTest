#pragma once
#include "../Utility/Coordinate.h"
#include "../Gameplay/Gameobject.h"
class Collider
{
public:
	void Init();
	void Init(Gameobject* owner);
	void Init(Vector2F pos, float angle, Vector2F size, Gameobject* owner);
	bool IsCollideWith(Collider* that);
protected:
	Gameobject* _my_obj;
	Vector2F _pos, _size;
	float _angle;
};

