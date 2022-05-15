#define sensorPin A0
#define sensorPower 7
#define sensorPin1 A1
#define sensorPin2 A2
#define sensorPin3 A3
#define motor 7
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
}
void loop() { 
  int reading = analogRead(sensorPin);
  float voltage = reading * (5.0 / 1024.0);
  float temperatureC = (voltage - 0.5) * 100;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.print("\xC2\xB0");
  Serial.println("F");
  delay(50);
  digitalWrite(sensorPower, HIGH);
  delay(10);
  int level=analogRead(sensorPin1);
  digitalWrite(sensorPower, LOW);
  Serial.print("Water level: ");
  Serial.println(level);
  delay(50);
  int soilm = analogRead(sensorPin2);
  Serial.print("Soil: ");
  Serial.println(soilm);
  delay(50);
  digitalWrite(sensorPower, HIGH);
  delay(10);
  int llvl=analogRead(sensorPin3);
  digitalWrite(sensorPower, LOW);
  Serial.print("Light level: ");
  Serial.println(llvl);
  /*
  digitalWrite(motor,HIGH);
  delay(1000);
  digitalWrite(motor,LOW);
  */
  if(temperatureF<150 && soilm<210 && llvl<100)
  {
      lcd.setCursor(0,1);
      if(level<400)
      {
        lcd.print("Linson Die");
      }
      else
      {
        lcd.print("Linson Live");
      }
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("Sir see");
  }
  delay(500);
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}
