// standard libraries
#include <Arduino.h>

// my libraries
#include "configs/pins.h"
#include "configs/pwm.h"

#include "handlers.h"
#include "memory.h"

void setup()
{
	// Пульт
	// remote_channel_1.setup(REMOTE_PIN_CHANNEL_1, IGNORE_PWM_SIGNAL, remote_handler_channel_1);
	remote_channel_2.setup(REMOTE_PIN_CHANNEL_2, IGNORE_PWM_SIGNAL, remote_handler_channel_2);
	remote_channel_3.setup(REMOTE_PIN_CHANNEL_3, IGNORE_PWM_SIGNAL, remote_handler_channel_3);
	remote_channel_4.setup(REMOTE_PIN_CHANNEL_4, IGNORE_PWM_SIGNAL, remote_handler_channel_4);
	remote_channel_5.setup(REMOTE_PIN_CHANNEL_5, IGNORE_PWM_SIGNAL, remote_handler_channel_5);
	remote_channel_6.setup(REMOTE_PIN_CHANNEL_6, IGNORE_PWM_SIGNAL, remote_handler_channel_6);

	// Актуаторы не вынес из конструктора
	// Позже вынесу, а то получается очень большой костыль
	// Пока что в файле memory.h

	// Серво
	servo_jamming.attach(SERVO_PIN_JAMMING);
	servo_gas.attach(SERVO_PIN_GAS);

	// Реле
	pinMode(RELAY_PIN_IGNITION, OUTPUT);
}

void loop()
{
	// remote_channel_1.listen();
	remote_channel_2.listen();
	remote_channel_3.listen();
	remote_channel_4.listen();
	remote_channel_5.listen();
	remote_channel_6.listen();

	wheel_piston.update_direction();   // Руль
	piston_brake.update_direction();   // Тормоз
	gearbox_piston.update_direction(); // Коробка (КПП)

	wheel_piston.update_position();   // Руль
	piston_brake.update_position();   // Тормоз
	gearbox_piston.update_position(); // Коробка (КПП)

	// Костыль
	// Отжать сцепу, если КПП дошло до нужной точки
	if (gearbox_active && gearbox_piston.get_current() == gearbox_piston.get_expected())
	{
		clutch_actuator.set_position(HYDRAULIC_ACTUATOR_MINIMUM_POSITION);
		delay(4);

		clutch_actuator.set_position(HYDRAULIC_ACTUATOR_INITIAL_POSITION);
		gearbox_active = false;
	}
}
