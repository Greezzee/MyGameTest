#include "BulletC.h"

#include "BulletA.h"
#include "BulletB.h"
#include "TimeManager.h"
#include "Gamefield.h"

void BulletC::Init(Gameobject* owner, float angle)
{
	Bullet::Init(owner);
	_angle = angle;
	_speed = { _basic_direction.x * cosf(angle), sinf(angle) };
	_life_time = 500000;
	i = 0;
}

void BulletC::Update()
{
	_life_time -= TimeManager::GetDeltaTime();
	if (_life_time <= 0.f) {
		_speed = { 0, 0 };
		if (_life_time <= -i * 5000) {
			BulletB* b = new BulletB;
			b->Init(this, 3.1415926f / 8 * i + _angle);
			gamefield->SpawnObject({ b, {true, false} });
			b = new BulletB;
			b->Init(this, -3.1415926f / 8 * i - _angle);
			gamefield->SpawnObject({ b, {true, false} });
			i++;
		}
		if (i == 8)
			gamefield->KillObject(_ID);
	}

	_pos += _speed * 0.00025f * TimeManager::GetDeltaTime();
}