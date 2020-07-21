#pragma once
enum class SceneType
{
	EMPTY,
	MAIN_MENU,
	CHARACTER_CHOOSE,
	GAMEPLAY,
	EXIT_MENU,
};

class Scene
{
public:
	SceneType type;
	bool is_end;
	Scene();
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Destroy() = 0;

protected:
	bool is_paused;
};
