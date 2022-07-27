#pragma once

#include "configs/PinLimitSwitches.h"
#include "VariableList.h"
#include <Arduino.h>

void install_limit_switches()
{
	// Коробка передач
	pinMode(GEARBOX_PIN_THIRD,  INPUT); // Третий
	pinMode(GEARBOX_PIN_SECOND, INPUT); // Второй
	pinMode(GEARBOX_PIN_FIRST,  INPUT); // Первый

	// Сцепление
	pinMode(CLUTCH_PIN_SECOND, INPUT); // Второй
	pinMode(CLUTCH_PIN_FIRST,  INPUT); // Первый

	// Тормоз
	pinMode(BRAKE_PIN_SECOND, INPUT); // Второй
	pinMode(BRAKE_PIN_FIRST,  INPUT); // Первый

	// Руль
	pinMode(RUDDER_PIN, INPUT); // Первый
}

void update_limit_switches()
{
	// Коробка передач
	limit_switches_values.gearbox_third  = digitalRead(GEARBOX_PIN_THIRD);  // Третий
	limit_switches_values.gearbox_second = digitalRead(GEARBOX_PIN_SECOND); // Второй
	limit_switches_values.gearbox_first  = digitalRead(GEARBOX_PIN_FIRST);  // Первый

	// Сцепление
	limit_switches_values.clutch_second = digitalRead(CLUTCH_PIN_SECOND); // Второй
	limit_switches_values.clutch_first  = digitalRead(CLUTCH_PIN_FIRST);  // Первый

	// Тормоз
	limit_switches_values.brake_second = digitalRead(BRAKE_PIN_SECOND); // Второй
	limit_switches_values.brake_first  = digitalRead(BRAKE_PIN_FIRST);  // Первый

	// Руль
	limit_switches_values.rudder = analogRead(RUDDER_PIN); // Первый
}
