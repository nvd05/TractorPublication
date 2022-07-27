#pragma once

#include "Timer.h"

using Reference = void(*)(long microseconds);

/**
 * @brief Слушатель ШИМ сигнала
 */
class PWMListener
{
private:
	Reference _callback;
	Timer     _timer;
	int       _signal;
	int       _ignore;
	int       _pin;

public:
	void setup(int pin, int ignore, Reference callback);
	void listen();
};
