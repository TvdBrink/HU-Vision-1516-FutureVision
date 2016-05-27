#pragma once

#include <chrono>
#include <cstdint>

class Timer
{
public:
	Timer();
	void Start();
	void Stop();
	void Restart();

	template <std::intmax_t N, std::intmax_t D>
	double GetTimePassed(std::ratio<N, D>)
	{
		if (isCounting) {
			TimePoint now = SystemClock::now();
			return std::chrono::duration<double, std::ratio<N, D>>(now - begin).count();
		}
		else {
			return std::chrono::duration<double, std::ratio<N, D>>(end - begin).count();
		}
	}
private:
	using SystemClock = std::chrono::system_clock;
	using TimePoint = std::chrono::time_point<SystemClock>;

	TimePoint begin;
	TimePoint end;

	bool isCounting;
};