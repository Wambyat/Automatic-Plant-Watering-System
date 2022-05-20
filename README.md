# Automatic-Plant-Watering-System
An automatic plant watering system created using Arduino.

**Connections:** (Check Connections_Pic for a visual guide)

Pin A2 for **soil moisture** sensor

Pin A1 for **water level** sensor

Pin A3 for **light** sensor

Pin A0 for **temperature** sensor

Pin 8 for **relay/pump**

Pin <anything left> for **bluetooth** module

Pins 2,3,4,5,11,12 for **LCD**

Code:

We check the light, soil moisture, tank water level to determine the next step.

We display the corresponding message on the LCD.

We can check the status of the plant on the phone by the bluetooth connection (using the standard blueetooth app for arduino).

The temperature and light sensors are used to determine if the plant should be moved or if the climate is unsuitable for the plant.

If you face any dificuities in any of the above steps visit lastminuteengineers.com
