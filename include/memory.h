#pragma once

// standard libraries
#include <Servo.h>

// my libraries
#include "HydraulicPiston/HydraulicPiston.h"
#include "PWMListener.h"

// пульт
// PWMListener remote_channel_1;
PWMListener remote_channel_2;
PWMListener remote_channel_3;
PWMListener remote_channel_4;
PWMListener remote_channel_5;
PWMListener remote_channel_6;

// Актуаторы
HydraulicActuator wheel_actuator(ACTUATOR_PIN_WHEEL_1, ACTUATOR_PIN_WHEEL_2); // Руль
HydraulicPiston   wheel_piston(wheel_actuator);                               // Руль

HydraulicActuator actuator_brake(ACTUATOR_PIN_BRAKE_1, ACTUATOR_PIN_BRAKE_2); // Тормоз
HydraulicPiston   piston_brake(actuator_brake);                               // Тормоз

// Тут вышел очень хороший костыль
// Но сцепление мне нужно выжимать на какой-то промешуток времени
// А так как не чего кроме PWMListener, который слушает пин и не работает чисто как время
// То вот такой костыль хороший получился
HydraulicActuator clutch_actuator(ACTUATOR_PIN_CLUTCH_1, ACTUATOR_PIN_CLUTCH_2); // Сцепление

HydraulicActuator gearbox_actuator(ACTUATOR_PIN_GEARBOX_1, ACTUATOR_PIN_GEARBOX_2); // Коробка (КПП)
HydraulicPiston   gearbox_piston(gearbox_actuator);                                 // Коробка (КПП)
long              gearbox_back_value = 0;                                           // Коробка (КПП)
bool              gearbox_active     = false;                                       // Коробка (КПП)
// Конец этого недорозумения

// Серво
Servo servo_jamming; // Глушение
Servo servo_gas;     // Газ
