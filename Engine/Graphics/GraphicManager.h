#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
#include "DrawData.h"
#include "../Utility/Coordinate.h"

const unsigned SPRITES_COUNT = 2;
enum Sprites {
	TEST_SPRITE,
	TEST_BULLET
};

const unsigned VIEWS_COUNT = 2;
enum Views {
	BASIC,
	TEST
};

class GraphicManager
{
public:
	static void Init();
	static bool Update();
	static void Exit();

	//static void LoadPack();
	static void Draw(DrawData& data, Views view_id = Views::BASIC);
	static void SetView(DrawData& data, Views view_id);
private:
	static sf::RenderWindow window;

	static std::vector<sf::Texture> textures;
	static std::vector<sf::Sprite> sprites;

	static std::vector<std::list<sf::Sprite>> to_draw;

	static std::vector<View> views;

	static const unsigned LAYER_COUNT;
};

