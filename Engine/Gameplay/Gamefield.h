#pragma once
#include "ObjectsArray.h"
class Gamefield
{
public:
	void Init();
	void Update();
	void Destroy();

	void SpawnObject(const GameobjectSpawnData& new_object);
	void KillObject(const Gameobject* object);
	void KillObject(const unsigned ID);
private:
	void ClearKilledObjects();
	ObjectsArray* _objects;
};

