# Automatic-Plant-Watering-System
An automatic plant watering system created using Arduino.


Connections:


Pin # for soil moisture sensor

Pin # for water level sensor

Pin # for light sensor

Pin # for temperature sensor

Pin # for relay/motor

Pin # for bluetooth module

Pins #### for LCD

Code:


We check the light,soil moisture to determine if the plant needs to be watered.

If it should be then we check if the tank has enough water.

If the tank has enough then we water it.

Else we display a message on the LCD to tell us that the tank need to be refilled.

We can check the status of the plant on the phone by the bluetooth connection (using the standard blueetooth app for arduino).

The temperature and light sensors are used to determine if the plant should be moved or if the climate is unsuitable for the plant.
