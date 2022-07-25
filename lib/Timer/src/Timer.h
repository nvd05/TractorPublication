#pragma once

/**
 * @brief Таймер
 */
class Timer final
{
private:
	long _lastRunTime;

public:
	long get_last_run_time();
	long get_elapsed_time();
	void update_time();

	Timer();
};
