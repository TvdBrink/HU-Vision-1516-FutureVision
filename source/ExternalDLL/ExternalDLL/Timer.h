#pragma once

#include <chrono>

class Timer
{
public:
	Timer();
	void Start();
	void Stop();
	void Restart();
	double GetTimePassed();
private:
	using SystemClock = std::chrono::system_clock;
	using TimePoint = std::chrono::time_point<SystemClock>;

	TimePoint begin;
	TimePoint end;

	bool isCounting;
};