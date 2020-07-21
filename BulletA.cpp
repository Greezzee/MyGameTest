#include "BulletA.h"
#include "BulletB.h"
#include "BulletC.h"
#include "TimeManager.h"
#include "Gamefield.h"

void BulletA::Init(Gameobject* owner)
{
	Bullet::Init(owner);
	_speed = 1 * _basic_direction;
	_life_time = 1500000;
	i = 0;
}

void BulletA::Update()
{
	_life_time -= TimeManager::GetDeltaTime();
	if (_life_time <= 0.f) {
		_speed = { 0, 0 };
		if (_life_time <= -i * 50000) {
			BulletC* b = new BulletC;
			b->Init(this, 3.1415926f / 16 * i);
			gamefield->SpawnObject({ b, {true, false} });
			b = new BulletC;
			b->Init(this, -3.1415926f / 16 * i);
			gamefield->SpawnObject({ b, {true, false} });
			i++;
		}
		if (i == 16)
			gamefield->KillObject(_ID);
	}

	_pos += _speed * 0.0005f * TimeManager::GetDeltaTime();
}