# Использование

```cpp
HydraulicActuator actuator(pin_one, pin_two);
HydraulicPiston   piston(actuator);

void setup()
{
	// Нет логики
}

void loop()
{
	piston.update_direction(); // Обновить положение мотора
	piston.update_position();  // Обновить положение поршня
}
```
