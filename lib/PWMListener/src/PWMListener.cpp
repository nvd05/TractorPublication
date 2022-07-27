#include "PWMListener.h"
#include <Arduino.h>

void PWMListener::setup(int pin, int ignore, Reference callback)
{
	_callback = callback;
	_ignore   = ignore;
	_pin      = pin;

	pinMode(pin, OUTPUT);
};

void PWMListener::listen()
{
	int signal = digitalRead(_pin);

	if (signal == _signal)
	{
		return;
	}

	long elapsed_time = _timer.get_elapsed_time(true);
	_signal = signal;

	if (signal == _ignore)
	{
		return;
	}

	_callback(elapsed_time);
};
