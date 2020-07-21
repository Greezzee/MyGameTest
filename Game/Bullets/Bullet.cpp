#include "../Bullets/Bullet.h"
#include "../Players/Player.h"
#include "../../Engine/Graphics/GraphicManager.h"
#include "../../Engine/Control/InputManager.h"
#include "../../Engine/Time/TimeManager.h"
#include "../../Engine/Gameplay/Gamefield.h"
#include <cmath>
#include <stdio.h>
void Bullet::Init(Gameobject* owner)
{
	SetTag(std::string("Bullet"));
	_pos = owner->GetPos();
	_speed = 2 * owner->GetDirection();
	_basic_direction = owner->GetDirection();
	_life_time = 5000000;
	_angle = 0;

	gamefield = owner->GetGamefield();
}

void Bullet::Update()
{
	_life_time -= TimeManager::GetDeltaTime();
	if (_life_time <= 0.f)
		gamefield->KillObject(_ID);
	_speed.y = cosf((3000000 - _life_time) * 0.00001);
	_speed.x -= 0.000001 * TimeManager::GetDeltaTime() * _basic_direction.x;
	_pos += _speed * 0.0005f * TimeManager::GetDeltaTime();
	_angle += 0.0015f * TimeManager::GetDeltaTime();
}

void Bullet::Draw()
{
	auto norm = _speed.Normalized();
	float angle = atan2(norm.y, norm.x) * 180 / 3.1415926;
	DrawData data;
	data.frame = 0;
	data.layer = 0;
	data.origin = { 32, 32 };
	data.position = _pos;
	data.rotation = angle;
	data.scale = { 2, 2 };
	data.textID = Sprites::TEST_BULLET;
	GraphicManager::Draw(data, Views::BASIC);
}

void Bullet::Destroy()
{
}