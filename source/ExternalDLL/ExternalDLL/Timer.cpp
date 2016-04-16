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

double Timer::GetTimePassed()
{
	if (isCounting) {
		TimePoint now = SystemClock::now();
		return std::chrono::duration<double, std::milli>(now - begin).count();
	}
	else {
		return std::chrono::duration<double, std::milli>(end - begin).count();
	}
}