#include <Arduino.h>

#include "HydraulicInterface.h"

void HydraulicInterface::normalize()
{
	_currentPosition = constrain(_currentPosition, _minimumPosition, _maximumPosition);
};

long HydraulicInterface::get_current()
{
	return _currentPosition;
};

long HydraulicInterface::get_maximum()
{
	return _maximumPosition;
};

long HydraulicInterface::get_minimum()
{
	return _minimumPosition;
};

HydraulicInterface::HydraulicInterface(long current, long maximum, long minimum)
: _currentPosition(current)
, _maximumPosition(maximum)
, _minimumPosition(minimum)
{
};
