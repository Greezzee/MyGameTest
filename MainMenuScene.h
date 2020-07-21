#pragma once
#include "Scene.h"
class MainMenuScene : public Scene
{
public:
	MainMenuScene();
	void Init();
	void Update();
	void Destroy();
private:
	int counter;
	bool started;
};
