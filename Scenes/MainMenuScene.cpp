#pragma once
#include <stdio.h>
#include "MainMenuScene.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Scene managment/SceneManager.h"
#include "../../Engine/Graphics/GraphicManager.h"

MainMenuScene::MainMenuScene() :
	counter(0), started(true) {}

void MainMenuScene::Init()
{
	//printf("MainMenu Created\n");
	counter = 0;
	started = true;
}

void MainMenuScene::Update()
{
	counter += TimeManager::GetDeltaTime();
	if (counter >= 3 * 600000 && started) {
		SceneManager::CreateScene(SceneType::GAMEPLAY);
		started = false;
		SceneManager::CloseScene(this);
	}
}

void MainMenuScene::Destroy()
{
	//printf("MainMenu Destroyed\n");
}