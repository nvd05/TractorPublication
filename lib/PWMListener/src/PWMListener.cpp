// standard libraries
#include <Arduino.h>

// my libraries
#include "PWMListener.h"

void PWMListener::listen()
{
	int signal = digitalRead(_pin);

	if (signal == _signal)
	{
		return;
	}

	long elapsed_time = _timer.get_elapsed_time();
	_signal = signal;

	if (signal == _ignore)
	{
		return;
	}

	_callback(elapsed_time);
};

void PWMListener::setup(int pin, int ignore, void (&callback)(long))
{
	_callback = callback;
	_ignore   = ignore;
	_pin      = pin;

	pinMode(pin, INPUT);
};
