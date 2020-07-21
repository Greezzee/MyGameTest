#pragma once
#include <string>

#include "../Utility/Coordinate.h"
class Gamefield;

class Gameobject
{
public:
	virtual void Init(Gameobject* owner) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Destroy() = 0;
	Vector2F GetPos();
	Vector2F GetDirection();
	float GetRotation();
	void SetID(unsigned new_id);
	unsigned GetID();

	void SetGamefield(Gamefield* field);
	Gamefield* GetGamefield();

	void SetTag(const std::string& new_tag);
	const std::string& GetTag();

protected:
	unsigned _ID;
	std::string _tag;

	Vector2F _pos, _basic_direction;
	float _angle;

	Gamefield* gamefield;

	friend class Collider;
};

