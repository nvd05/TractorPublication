#pragma once

// my libraries
#include "Timer.h"

/**
 * @brief Шим слушатель
 */
class PWMListener final
{
private:
	void (*_callback)(long);
	Timer _timer;

	int _signal;
	int _ignore;
	int _pin;

public:
	void listen();
	void setup(int pin, int ignore, void (&callback)(long));
};
