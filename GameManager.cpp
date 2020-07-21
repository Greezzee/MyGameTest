#pragma once
#include "GameManager.h"
#include "GraphicManager.h"
#include "SceneManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include <stdio.h>

bool GameManager::is_exit;
void GameManager::Launch()
{
	is_exit = false;
	GraphicManager::Init();
	TimeManager::Init();
	InputManager::Init();
	//GraphicManager::LoadPack("Menu");
	SceneManager::CreateScene(SceneType::MAIN_MENU);
	int frames = 0;
	unsigned sec = 0;
	while (!is_exit) {
		TimeManager::Update();
		InputManager::Update();
		is_exit = is_exit || SceneManager::UpdateScenes();
		is_exit = is_exit || GraphicManager::Update();
		sec += TimeManager::GetDeltaTime();
		frames++;
		if (sec >= 1000000) {
			sec = 0;
			printf("%d\n", frames);
			frames = 0;
		}
	}

	SceneManager::Destroy();
	GraphicManager::Exit();
	//GlobalTimer::Destroy();
}