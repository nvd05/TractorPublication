# Краткое содержание
* Класс `HydraulicActuator`  - это мотор
* Класс `HydraulicPiston`    - это поршень
* Класс `HydraulicInterface` - это класс, которые существовать один не может, он должен быть с кем-то в паре.

+ Установить положение мотору - `HydraulicActuator.set_position(1 | 0 | -1);`
+ Установить положение поршню - `HydraulicPiston.set_position(<min> - <max>);`
