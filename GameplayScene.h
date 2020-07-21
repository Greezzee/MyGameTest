#pragma once
#include "Scene.h"
#include "Coordinate.h"
#include "Gamefield.h"
class GameplayScene : public Scene
{
public:
	GameplayScene();
	void Init();
	void Update();
	void Destroy();
private:
	Gamefield gamefield;
};
