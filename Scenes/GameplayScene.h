#pragma once
#include "../../Engine/Scene managment/Scene.h"
#include "../../Engine/Gameplay/Gamefield.h"
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
