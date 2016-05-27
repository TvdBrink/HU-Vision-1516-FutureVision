#include "Timer.h"

Timer::Timer() :
	isCounting(false)
{
}

void Timer::Start()
{
	begin = SystemClock::now();
	isCounting = true;
}

void Timer::Stop()
{
	end = SystemClock::now();
	isCounting = false;
}

void Timer::Restart()
{
	begin = SystemClock::now();
	isCounting = true;
}