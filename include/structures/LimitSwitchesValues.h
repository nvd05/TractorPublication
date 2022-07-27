#pragma once

/**
 * @brief Значения концевиков
 */
struct LimitSwitchesValues
{
	// Коробка передач
	int gearbox_third;  // Третий
	int gearbox_second; // Второй
	int gearbox_first;  // Первый

	// Сцепление
	int clutch_second; // Второй
	int clutch_first;  // Первый

	// Тормоз
	int brake_second; // Второй
	int brake_first;  // Первый

	// Руль
	int rudder; // Первый
};
