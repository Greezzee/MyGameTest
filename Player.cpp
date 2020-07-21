#include "Player.h"
#include "Bullet.h"
#include "BulletA.h"
#include "GraphicManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Gamefield.h"

#include <stdio.h>
void Player::Init(Gameobject* owner)
{
	printf("Player created\n");
	SetTag(std::string("Player"));
	_pos = { 50, 450 };
	_speed = { 0, 0 };

	_keys[PlayerKey::Left] = KeyboardKey::L_Left;
	_keys[PlayerKey::Right] = KeyboardKey::L_Right;
	_keys[PlayerKey::Up] = KeyboardKey::L_Up;
	_keys[PlayerKey::Down] = KeyboardKey::L_Down;
	_keys[PlayerKey::ShootA] = KeyboardKey::L_ShootA;
	_keys[PlayerKey::ShootB] = KeyboardKey::L_ShootB;

	_basic_direction = { 1, 0 };
	_type = PlayerType::LeftPlayer;
}

void Player::Init(Gameobject* owner, const std::string& tag)
{
	SetTag(tag);
	if (_tag == "L_Player")
		Init(owner);
	else if (_tag == "R_Player") {
		_pos = { 1550, 450 };
		_speed = { 0, 0 };

		_basic_direction = { -1, 0 };
		_type = PlayerType::RightPlayer;

		_keys[PlayerKey::Left] = KeyboardKey::R_Left;
		_keys[PlayerKey::Right] = KeyboardKey::R_Right;
		_keys[PlayerKey::Up] = KeyboardKey::R_Up;
		_keys[PlayerKey::Down] = KeyboardKey::R_Down;
		_keys[PlayerKey::ShootA] = KeyboardKey::R_ShootA;
		_keys[PlayerKey::ShootB] = KeyboardKey::R_ShootB;
	}
}

void Player::Update()
{
	_speed = { 0, 0 };
	if (InputManager::IsDown(_keys[PlayerKey::Up]))
		_speed.y -= 1.f;
	if (InputManager::IsDown(_keys[PlayerKey::Down]))
		_speed.y += 1.f;
	if (InputManager::IsDown(_keys[PlayerKey::Left]))
		_speed.x -= 1.f;
	if (InputManager::IsDown(_keys[PlayerKey::Right]))
		_speed.x += 1.f;
	_pos += _speed.Normalized() * 0.001f * TimeManager::GetDeltaTime();

	if (InputManager::IsPressed(_keys[PlayerKey::ShootA])) {
		Bullet* b = new Bullet;
		b->Init(this);
		gamefield->SpawnObject({ b, {true, false} });
	}

	if (InputManager::IsPressed(_keys[PlayerKey::ShootB])) {
		BulletA* b = new BulletA;
		b->Init(this);
		gamefield->SpawnObject({ b, {true, false} });
	}
}

void Player::Draw()
{
	DrawData data;
	data.frame = 0;
	data.layer = 0;
	data.origin = { 32, 32 };
	data.position = _pos;
	data.rotation = 0;
	data.scale = 2 * Vector2F(_basic_direction.x, 1);
	data.textID = Sprites::TEST_SPRITE;
	GraphicManager::Draw(data, Views::BASIC);
}

void Player::Destroy()
{
	printf("Player destroyed\n");
}