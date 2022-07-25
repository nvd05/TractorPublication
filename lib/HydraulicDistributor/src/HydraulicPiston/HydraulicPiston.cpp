#include "HydraulicPiston.h"
#include "Timer.h"

long HydraulicPiston::get_expected()
{
	return _expectedPosition;
};

void HydraulicPiston::update_direction()
{
	long mixing    = _expectedPosition - _currentPosition;
	long direction = constrain(mixing, _handlerInterface.get_minimum(), _handlerInterface.get_maximum());

	// Serial.println("direction: " + String(_currentPosition) + " " + String(_maximumPosition) + " " + String(_minimumPosition));
	// Serial.println("direction: " + String(mixing) + " " + String(direction));

	_handlerInterface.set_position(direction);
};

void HydraulicPiston::update_position()
{
	_currentPosition += _handlerInterface.get_current() * _timer.get_elapsed_time();
	normalize();
};

void HydraulicPiston::set_position(long position)
{
	_expectedPosition = position;
};

HydraulicPiston::HydraulicPiston(HydraulicActuator &handler_interface)
: HydraulicInterface(HYDRAULIC_PISTON_INITIAL_POSITION, HYDRAULIC_PISTON_MAXIMUM_POSITION, HYDRAULIC_PISTON_MINIMUM_POSITION)
, _handlerInterface(handler_interface)
, _timer(Timer())
, _expectedPosition(HYDRAULIC_PISTON_INITIAL_POSITION)
{
};
