Own project created on Arduino
- 1 DHT11 sensor, 
- 6 DS18B20 sensors, 
- 4 tact switches, 
- flash card reader 
- 16x2 LCD display connected by I2C  bus


Purpose of the project is to control temperature in air pipes, collect data on flash card in purpose to process them. (I'm planning to add 2 servomotors in order to control whole system of air pipes.
Whole project is written in C++. I created own interface Gui for display. Trying to use MVC and Design Patterns (2 classes are singletons). My class - Button is a good objective approach how to use tact switches.

![alt text](https://user-images.githubusercontent.com/19203193/29630675-40d60602-883d-11e7-981a-8096ca585213.png)

Tinkercad do not provide I2C LCD bus compotnent, DTH11 sensor, and card reader in their circuits editor. In order that I could not show it on the scheme. 

Card reader is connected to ICSP and 4 of arduino digital pins.
One-Wire bus is connected to 2 of arduino digital pin.
DTH11 sensor is connected to 3 of arduino digital pin.
