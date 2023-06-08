# Shnecohod

![photo_2023-04-25_18-36-53](https://github.com/swnirk/Shnecohod/assets/54669541/ca98cea0-6f92-4ffb-b252-6451ad929a09)
![photo_2023-04-18_20-24-33](https://github.com/swnirk/Shnecohod/assets/54669541/019faa91-3777-4dd9-8496-15ed35125651)

Робот на пультеуправления, работающий по принципу шнекохода:

https://github.com/swnirk/Shnecohod/assets/54669541/ef3eb7e0-7d48-4e3a-86e5-9fca51ec2f2a


#### Задача:
- Из имеющихся компонентов построить робота для преодоления полосы препятствий
- Робот не должен приводиться в движение колесами или гусеницами

#### Компоненты:
- x2 аккумулятора 18650
- x2 модуль NRF24L01(+)
- x1 Motor Shield
- x2 Arduino Uno/Leonardo
- x1 холдер для батареек
- x2 dc-мотора с редуктором
- x1 тумблера
- x2 джойстика
- x1 потенциометр
- x1 RGB LED матрица

#### Описание решения:
Робота приводят в движения два винта архимеда, вращающихся во встречном направлении. Такая конструкция обеспечивает беспрецедентную проходимость в вязкой почве, снеге или песке.

- Основа робота вырезается из фанеры толщиной 6 мм углекислотным лазером. На неё крепятся все остальные детали
- Неподвижные детали печатаются на 3D-принтере из PLA
- Шнекороторы печатаются на 3D-принтере из TPU и крепятся на подшипники
- Питание обеспечивает блок из двух аккумуляторов 18650
- В качестве основного микроконтроллера используется Arduino Uno
- Управление осуществляется по радиоканалу. Пульт управленния также используется Arduino, а также 2 джойстика.

#### Тестирование
В ходе тестирования выявлена следующая конструктивная особенность предоставленных двигателей. При движении вперед по гладкой поверхности встречное вращение шнекороторов создает большое напряжение в области пластикового крепления двигателя. Данное крепление быстро выходит из строя. После выхода из строя движение вперед становится невозможно: вал двигателя прокручивается внутри крепления. Необходимо использовать другую конструкцию двигателей.