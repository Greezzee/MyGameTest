#pragma once
#include <stdio.h>
#include "SceneManager.h"
#include "GameplayScene.h"
#include "GraphicManager.h"
#include "TimeManager.h"
#include "InputManager.h"

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