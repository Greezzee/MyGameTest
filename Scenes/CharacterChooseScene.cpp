#pragma once
#include <stdio.h>
#include "CharacterChooseScene.h"
#include "../../Engine/Scene managment/SceneManager.h"
#include "../../Engine/Graphics/GraphicManager.h"

CharacterChooseScene::CharacterChooseScene() :
	counter(0) {}

void CharacterChooseScene::Init()
{
	//printf("CharacterChooseScene Created\n");
	counter = 0;
}

void CharacterChooseScene::Update()
{
	//printf("%d\n", counter);
	counter++;
	if (counter == 600) {
		SceneManager::CloseScene(this);
	}

	//GraphicManager::Draw(DrawData(1, 2, 100, 50));
}

void CharacterChooseScene::Destroy()
{
	//printf("CharacterChooseScene Destroyed\n");
}
