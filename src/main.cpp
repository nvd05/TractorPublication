#include "configs/PWMConfig.h"
#include "configs/PinConfig.h"
#include "LimitSwitches.h"
#include "VariableList.h"
#include <Arduino.h>

void setup()
{
	// Пульт
	remote_channels.channel_1.setup(REMOTE_PIN_CHANNEL_1, IGNORE_PWM_SIGNAL, [](long microseconds) -> void { remote_values.right_stick_width             = microseconds; });
	remote_channels.channel_2.setup(REMOTE_PIN_CHANNEL_2, IGNORE_PWM_SIGNAL, [](long microseconds) -> void { remote_values.right_stick_height            = microseconds; });
	remote_channels.channel_3.setup(REMOTE_PIN_CHANNEL_3, IGNORE_PWM_SIGNAL, [](long microseconds) -> void { remote_values.left_stick_height             = microseconds; });
	remote_channels.channel_4.setup(REMOTE_PIN_CHANNEL_4, IGNORE_PWM_SIGNAL, [](long microseconds) -> void { remote_values.left_stick_width              = microseconds; });
	remote_channels.channel_5.setup(REMOTE_PIN_CHANNEL_5, IGNORE_PWM_SIGNAL, [](long microseconds) -> void { remote_values.three_position_toggle_switch  = microseconds; });
	remote_channels.channel_6.setup(REMOTE_PIN_CHANNEL_6, IGNORE_PWM_SIGNAL, [](long microseconds) -> void { remote_values.single_position_toggle_switch = microseconds; });

	// Концевики
	install_limit_switches();
}

void loop()
{
	// Пульт
	remote_channels.channel_1.listen();
	remote_channels.channel_2.listen();
	remote_channels.channel_3.listen();
	remote_channels.channel_4.listen();
	remote_channels.channel_5.listen();
	remote_channels.channel_6.listen();

	// Концевики
	update_limit_switches();
}
