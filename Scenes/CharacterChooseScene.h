#pragma once
#include "../../Engine/Scene managment/Scene.h"
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