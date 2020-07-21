#pragma once
#include <vector>
#include "Scene.h"
class SceneManager
{
public:
	static void OpenScene(Scene* scene);
	static void CreateScene(SceneType type);
	static void CloseScene(const Scene* scene);
	static bool UpdateScenes();
	static void Destroy();
private:
	static std::vector<Scene*> _current_scenes;
};