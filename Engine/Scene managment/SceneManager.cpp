#pragma once
#include "SceneManager.h"
#include "../../Scenes/MainMenuScene.h"
#include "../../Scenes/CharacterChooseScene.h"
#include "../../Scenes/GameplayScene.h"

std::vector<Scene*> SceneManager::_current_scenes;
void SceneManager::OpenScene(Scene* scene)
{
	_current_scenes.push_back(scene);
}

void SceneManager::CreateScene(SceneType type)
{
	switch (type)
	{
	case SceneType::MAIN_MENU:
		_current_scenes.push_back(new MainMenuScene);
		break;
	case SceneType::CHARACTER_CHOOSE:
		_current_scenes.push_back(new CharacterChooseScene);
		break;
	case SceneType::GAMEPLAY:
		_current_scenes.push_back(new GameplayScene);
		break;
	case SceneType::EXIT_MENU:
		break;
	default:
		break;
	}
	_current_scenes.back()->Init();
	_current_scenes.back()->type = type;
}

void SceneManager::CloseScene(const Scene* scene)
{
	for (int i = 0; i < (int)_current_scenes.size(); i++)
		if (_current_scenes[i] == scene) {
			_current_scenes[i]->Destroy();
			delete _current_scenes[i];
			_current_scenes.erase(_current_scenes.begin() + i);
		}
}

bool SceneManager::UpdateScenes()
{
	if (_current_scenes.empty())
		return true;

	for (int i = 0; i < (int)_current_scenes.size(); i++)
		_current_scenes[i]->Update();

	for (int i = 0; i < (int)_current_scenes.size(); i++)
		if (_current_scenes[i]->is_end) {
			_current_scenes[i]->Destroy();
			delete _current_scenes[i];
			_current_scenes.erase(_current_scenes.begin() + i);
			i--;
		}
	return false;
}

void SceneManager::Destroy()
{
	while (!_current_scenes.empty()) {
		CloseScene(_current_scenes[0]);
	}
}