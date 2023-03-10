#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
#define LED_PIN 10
#define BUTTON_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
float humi;
float tempC;

void setup() {
  dht.begin();
  lcd.init();
  lcd.clear();
  lcd.backlight();
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
    // read humidity
    humi  = dht.readHumidity();
    // read temperature as Celsius
    tempC = dht.readTemperature();

    if (digitalRead(BUTTON_PIN) == LOW) {
      lcd.clear();
      digitalWrite(LED_PIN, HIGH);
      lcd.print(tempC);
    }
    else {
      digitalWrite(LED_PIN, LOW);
    }
}
