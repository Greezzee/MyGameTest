#pragma once
class Gameobject;
#include "Gameobject.h"
const unsigned MAX_OBJECTS = 100000;
const unsigned LAYERS_COUNT = 2;

enum LayerNames {
	BASE
};

struct KilledArray
{
	int obj_id[MAX_OBJECTS];
	unsigned top;
};

struct Layer {
	int obj_id[MAX_OBJECTS];
	unsigned top;
};

struct ObjectData
{
	Gameobject* obj;
	/*
	* ”казывает индекс указател€ на объект в соотвествуеющем слое.
	* -1, если объект отсутствует в соответствующем слое
	*/
	int layer_pos[LAYERS_COUNT];
};

struct ObjectsArray
{
	ObjectData obj[MAX_OBJECTS];
	Layer layers[LAYERS_COUNT];
	KilledArray to_kill;
	unsigned top;
};

struct GameobjectSpawnData
{
	Gameobject* obj;
	bool is_on_layer[LAYERS_COUNT];
};