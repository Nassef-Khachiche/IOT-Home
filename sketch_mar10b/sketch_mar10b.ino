#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
float humi;
float tempC;

void setup() {
  dht.begin();
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() {
  // read humidity
  humi  = dht.readHumidity();
  // read temperature as Celsius
  tempC = dht.readTemperature();
  lcd.print(tempC);
  delay(1500);
  lcd.clear();
}
