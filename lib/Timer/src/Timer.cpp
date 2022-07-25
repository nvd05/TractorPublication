// standard libraries
#include <Arduino.h>

// my libraries
#include "Timer.h"

long Timer::get_last_run_time()
{
	return _lastRunTime;
};

long Timer::get_elapsed_time()
{
	long current_time = micros();
	long elapsed_time = current_time - _lastRunTime;

	_lastRunTime = current_time;
	return elapsed_time;
};

void Timer::update_time()
{
	_lastRunTime = micros();
};

Timer::Timer() : _lastRunTime(micros())
{
};
