#pragma once
#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include "Coordinate.h"

const unsigned KeysCount = 12;
enum KeyboardKey {
	L_Left, L_Right, L_Up, L_Down, L_ShootA, L_ShootB,
	R_Left, R_Right, R_Up, R_Down, R_ShootA, R_ShootB
};

const unsigned PlayerKeysCount = 6;
enum PlayerKey {
	Left, Right, Up, Down, ShootA, ShootB
};

struct KeyData {
	bool is_pressed;
	bool is_realesed;
	bool is_down;
};

struct InputManager
{
	static void Init();
	static void Update();

	static bool IsPressed(KeyboardKey key);
	static bool IsRealesed(KeyboardKey key);
	static bool IsUp(KeyboardKey key);
	static bool IsDown(KeyboardKey key);

private:
	static KeyData _key_info[KeysCount];
	static sf::Keyboard::Key _control_keys[KeysCount];
};
