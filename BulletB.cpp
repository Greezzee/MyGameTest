#include "BulletB.h"
#include "TimeManager.h"
#include "Gamefield.h"
#include <cmath>
void BulletB::Init(Gameobject* owner, float angle)
{
	Bullet::Init(owner);
	_speed = { _basic_direction.x * cosf(angle), sinf(angle) };
	_accel = -_speed.Normalized();
}

void BulletB::Update()
{
	_life_time -= TimeManager::GetDeltaTime();
	if (_life_time <= 0.f)
		gamefield->KillObject(_ID);
	_speed += 0.000001 * _accel * TimeManager::GetDeltaTime();
	_pos += _speed * 0.0005f * TimeManager::GetDeltaTime();
}