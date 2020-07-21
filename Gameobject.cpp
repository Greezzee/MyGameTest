#pragma once
#include "Gameobject.h"

void Gameobject::SetID(unsigned new_id)
{
	_ID = new_id;
}

unsigned Gameobject::GetID()
{
	return _ID;
}

void Gameobject::SetGamefield(Gamefield* field)
{
	gamefield = field;
}

Gamefield* Gameobject::GetGamefield()
{
	return gamefield;
}

Vector2F Gameobject::GetPos()
{
	return _pos;
}

float Gameobject::GetRotation()
{
	return _angle;
}

void Gameobject::SetTag(const std::string& new_tag)
{
	_tag = new_tag;
}

const std::string& Gameobject::GetTag()
{
	return _tag;
}

Vector2F Gameobject::GetDirection()
{
	return _basic_direction;
}