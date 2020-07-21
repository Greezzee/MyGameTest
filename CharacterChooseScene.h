#pragma once
#include "Scene.h"
class CharacterChooseScene : public Scene
{
public:
	CharacterChooseScene();
	void Init();
	void Update();
	void Destroy();
private:
	int counter;
};