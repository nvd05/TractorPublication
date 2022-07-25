#pragma once

/**
 * @brief Гидравлический интерфейс
 */
class HydraulicInterface
{
protected:
	long _currentPosition;
	long _maximumPosition;
	long _minimumPosition;

	void normalize();

	HydraulicInterface(long current, long maximum, long minimum);

public:
	void set_position(long position);
	long get_current();
	long get_maximum();
	long get_minimum();
};
