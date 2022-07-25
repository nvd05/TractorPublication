#include <Arduino.h>

#include "HydraulicActuator.h"

void HydraulicActuator::set_position(long direction)
{
	digitalWrite(_pinOne, direction + 0 == HIGH);
	digitalWrite(_pinTwo, direction + 2 == HIGH);
	_currentPosition = direction;
};

HydraulicActuator::HydraulicActuator(byte pin_one, byte pin_two)
: HydraulicInterface(HYDRAULIC_ACTUATOR_INITIAL_POSITION, HYDRAULIC_ACTUATOR_MAXIMUM_POSITION, HYDRAULIC_ACTUATOR_MINIMUM_POSITION)
, _pinOne(pin_one)
, _pinTwo(pin_two)
{
	pinMode(pin_one, OUTPUT);
	pinMode(pin_two, OUTPUT);
};
