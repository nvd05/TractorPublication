#pragma once

#include <Arduino.h>

#include "HydraulicInterface/HydraulicInterface.h"
#include "HydraulicActuator/HydraulicActuator.h"
#include "hydraulic.h"
#include "Timer.h"

/**
 * @brief Гидравлический поршень
 */
class HydraulicPiston final : public HydraulicInterface
{
private:
	HydraulicActuator &_handlerInterface;
	Timer _timer;
	long _expectedPosition;

public:
	void update_direction();
	void update_position();
	void set_position(long position);
	long get_expected();

	HydraulicPiston(HydraulicActuator &handler_interface);
};
