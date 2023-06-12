# Automatic-Plant-Watering-System

An automatic plant watering system created using Arduino.

### Connections:

(Check Connections_Pic for a visual guide)

| Pin | Use |
| --- | --- |
| Pin A2 | **Soil moisture sensor** |
| Pin A1 | **Water level sensor** |
| Pin A3 | **Light sensor** |
| Pin A0 | **Temperature sensor** |
| Pin 8 | **Relay/pump** |
| Pin \<anything left\> | **Bluetooth** |
| Pins 2,3,4,5,11,12 | **LCD** |

### Code:

We check the light, soil moisture, tank water level to determine the next step.

We display the corresponding message on the LCD.

We can check the status of the plant on the phone by the bluetooth connection (using the standard bluetooth app for arduino).

The temperature and light sensors are used to determine if the plant should be moved or if the climate is unsuitable for the plant.

If you face any difficulties in any of the above steps visit lastminuteengineers.com
