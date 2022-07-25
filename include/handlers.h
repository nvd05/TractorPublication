#pragma once

// standard libraries
#include <Arduino.h>

// my libraries
#include "configs/values.h"
#include "configs/servo.h"
#include "configs/pins.h"

#include "handlers.h"
#include "memory.h"

void remote_handler_channel_1(long microseconds)
{
	// Нет логики
};

/**
 * @brief Руль
 */
void remote_handler_channel_2(long microseconds)
{
	// Руль
	wheel_piston.set_position(map(microseconds, MINIMUM_PWM_SIGNAL, MAXIMUM_PWM_SIGNAL, wheel_piston.get_minimum(), wheel_piston.get_maximum()));
};

/**
 * @brief Зажигание
 */
void remote_handler_channel_3(long microseconds)
{
	// Зажигание
	digitalWrite(RELAY_PIN_IGNITION, microseconds > MINIMUM_IGNITION_VALUE ? HIGH : LOW);
};

/**
 * @brief Газ и тормоз
 */
void remote_handler_channel_4(long microseconds)
{
	// Газ
	if (microseconds > MINIMUM_GAS_VALUE)
	{
		servo_gas.write(map(microseconds, MINIMUM_GAS_VALUE, MAXIMUM_GAS_VALUE, SERVO_MINIMUM_VALUE, SERVO_MAXIMUM_VALUE));
		return;
	}

	// Тормоз
	if (microseconds < MAXIMUM_BRAKE_VALUE)
	{
		piston_brake.set_position(map(microseconds, MINIMUM_BRAKE_VALUE, MAXIMUM_BRAKE_VALUE, piston_brake.get_minimum(), piston_brake.get_maximum()));
		return;
	}
};

/**
 * @brief Сцепление и передачи (КПП)
 */
void remote_handler_channel_5(long microseconds)
{
	long gearbox_value = map(microseconds, MINIMUM_PWM_SIGNAL, MAXIMUM_PWM_SIGNAL, HYDRAULIC_ACTUATOR_MINIMUM_POSITION, HYDRAULIC_ACTUATOR_MAXIMUM_POSITION);

	if (gearbox_value == gearbox_back_value)
	{
		return;
	}

	gearbox_back_value = gearbox_value;
	gearbox_active = true;

	// Вышать сцепу
	clutch_actuator.set_position(HYDRAULIC_ACTUATOR_MAXIMUM_POSITION);
	delay(4);

	// Изменить положение КПП
	gearbox_piston.set_position(gearbox_value);

	// Отжатие сцепы в 'void loop()' в 'src/main.cpp'
};

/**
 * @brief Глушение
 */
void remote_handler_channel_6(long microseconds)
{
	servo_jamming.write(microseconds > MINIMUM_JAMMING_VALUE ? SERVO_MAXIMUM_VALUE : SERVO_MINIMUM_VALUE);
};
