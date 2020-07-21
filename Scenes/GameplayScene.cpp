#pragma once
#include <stdio.h>
#include "GameplayScene.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Scene managment/SceneManager.h"
#include "../../Engine/Graphics/GraphicManager.h"

GameplayScene::GameplayScene(){}

void GameplayScene::Init()
{
	printf("GameplayScene Created\n");
	gamefield.Init();
}

void GameplayScene::Update()
{
	gamefield.Update();
}

void GameplayScene::Destroy()
{
	gamefield.Destroy();
	printf("GameplayScene Destroyed\n");
}