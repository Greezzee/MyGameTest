#pragma once
#include "Scene.h"

Scene::Scene() :
	type(SceneType::EMPTY), is_paused(false), is_end(false) {}