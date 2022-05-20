/**
 * @file final.ino
 * @author Anirudha Anekal (anirudhaanekal@gmail.com || Wambyat on GitHub)
 * @brief Automated plant watering system built using arduino
 * @version 1.1
*/
#define TemperaturePin A0   //Temperature sensor TMP36
#define GeneralPower 7      //"power" for a few components are managed as they are not required to be on continuously
#define WaterLevel A1       //Water level detector (inside tank)
#define SoilMoisture A2     //Soil moisture sensor (standard model)
#define LightSensor A3      //Light sensor (photosensitive diode on a mini pcb in line with a potetiometer) (can be readily found)
#define pump 8              //water pump
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  pinMode(GeneralPower, OUTPUT);
  pinMode(pump, OUTPUT);
  digitalWrite(GeneralPower, HIGH);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("System Online");
}
void loop() { 
  
  /**
   * @brief This part reads the temperature (FIrst in Celcius then converted to Farenheit)
   * 
   */

  int reading = analogRead(TemperaturePin);.
  float voltage = reading * (5.0 / 1024.0);
  float temperatureC = (voltage - 0.5) * 100;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.print("\xC2\xB0");
  Serial.println("F");
  delay(50);

  /**
   * @brief This part reads the water level
   * We set the power for this because the component does not need to be continously on for ideal functioning.
   */

  digitalWrite(GeneralPower, HIGH);
  delay(10);
  int WaterLevel=analogRead(WaterLevel);
  digitalWrite(GeneralPower, LOW);
  Serial.print("Water WaterLevel: ");
  Serial.println(WaterLevel);
  delay(50);
  
  /**
   * @brief This part reads the soil moisture level
   * We set the power for this because the component does not need to be continously on for ideal functioning.
   */

  digitalWrite(GeneralPower, HIGH);
  int SoilMoisture = analogRead(SoilMoisture);
  Serial.print("Soil: ");
  Serial.println(SoilMoisture);
  delay(50);
  
  digitalWrite(GeneralPower, LOW);
  delay(10);

  /**
   * @brief This part reads the light level
   */
  
  int LightLevel=analogRead(LightSensor);
  Serial.print("Light level: ");
  Serial.println(LightLevel);

/**
 * @brief Here we check the conditions and perform what is nessesary
 * 
 */

  if(SoilMoisture<350 && LightLevel>90)
  {
      if(WaterLevel<550)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Plant is sad");
        lcd.setCursor(0,1);
        lcd.print("Therfore Water");
        
        digitalWrite(pump, HIGH);
        delay(2000);
        digitalWrite(pump,LOW);
        
        lcd.setCursor(0,1);
        lcd.print("Watered ");
        Serial.println("Watered");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Plant is happy");
      }
      else
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Plant is sad");
        lcd.setCursor(0,1);
        lcd.print("Tank is empty");
        delay(2000);
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Plant is sad");
      }
  }
}
