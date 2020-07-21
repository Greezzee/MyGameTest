#pragma once
#include "Coordinate.h"

struct View
{
	Vector2F virtual_size;
	Vector2F real_size;
	Vector2F position;
};

struct DrawData
{
	DrawData();
	DrawData(unsigned id, unsigned lr, Vector2F& pos);
	DrawData(unsigned id, unsigned lr, float x, float y);
	DrawData(unsigned id, unsigned lr, Vector2F& pos, float rot);
	DrawData(unsigned id, unsigned lr, float x, float y, float rot);

	unsigned textID;
	unsigned layer;

	Vector2F position;
	Vector2F origin;
	Vector2F scale;
	float rotation;
	int frame;
};
