#pragma once

/**
 * @brief Микросекундный таймер
 */
class Timer
{
private:
	long _microseconds;

public:
	void set_microseconds(long microseconds);
	long get_elapsed_time(bool update_time);
	Timer();
};
