#pragma once
#include "DrawData.h"

DrawData::DrawData() :
	textID(0), position({ 0, 0 }), layer(0), rotation(0) {}
DrawData::DrawData(unsigned id, unsigned lr, Vector2F& pos) :
	textID(id), position(pos), layer(lr), rotation(0) {}
DrawData::DrawData(unsigned id, unsigned lr, float x, float y) :
	textID(id), position({ x, y }), layer(lr), rotation(0) {}

DrawData::DrawData(unsigned id, unsigned lr, Vector2F& pos, float rot) :
	textID(id), position(pos), layer(lr), rotation(rot) {}
DrawData::DrawData(unsigned id, unsigned lr, float x, float y, float rot) :
	textID(id), position({ x, y }), layer(lr), rotation(rot) {}
