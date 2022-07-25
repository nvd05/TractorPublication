#pragma once

#include "HydraulicInterface/HydraulicInterface.h"
#include "hydraulic.h"

/**
 * @brief Гидравлический привод
 */
class HydraulicActuator final : public HydraulicInterface
{
private:
	byte _pinOne;
	byte _pinTwo;

public:
	void set_position(long direction);

	HydraulicActuator(byte pin_one, byte pin_two);
};
