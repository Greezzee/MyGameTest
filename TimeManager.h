#pragma once
#include <SFML/System.hpp>
class TimeManager
{
public:
	static void Init();
	static void Update();
	static void Restart();

	static unsigned long long GetTimeFromLastRestart();
	static unsigned long long GetDeltaTime();
private:
	static sf::Clock clock;
	static unsigned long long TimeFromLastRestart;
	static unsigned long long DeltaTime;
};
