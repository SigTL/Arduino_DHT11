// Example testing sketch for various DHT humidity/temperature sensors
// Blink 2 leds during the read routines to indicate action and both when writing the output
// Written by ladyada, public domain - modified by SigTL

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"
#define DHTPIN 3     // Digital pin connected to the DHT sensor

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// declare led info 
// connect led1 to pin 7 and led2 to pin 6 - use 330 ohm resiter on + before leds
int led1=7;
int led2=6;
int waitTimeOn=900;
int waitTimeOff=100;
int waitShort=20;
int waitLong=5000;
int waitMed=2500;

// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND

// Initialize DHT sensor.

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
//  Serial.println(F("DHT11 Temperature and Humidity test"));

  dht.begin();
  // defines the leds as outputs
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
  }

void loop() {
  // Wait a few seconds between measurements.
  delay(waitLong);
  
  // turn on led1
  digitalWrite(led1,HIGH);
  delay(waitShort);
  digitalWrite(led1,LOW);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  
  delay(waitLong);

  // turn on led2
  digitalWrite(led2,HIGH);
  // turn off led2
  delay(waitShort);
  digitalWrite(led2,LOW);

  
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  delay(waitLong);

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  // turn on leds 1+2
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);

  delay(waitShort);
  
  // turn off leds 1+2
  digitalWrite(led1,LOW); 
  digitalWrite(led2,LOW);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  //  Serial.print(t);
  //  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  //  Serial.print(hic);
  //  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  // turn off led2
  delay(waitTimeOff);
  digitalWrite(led2,LOW);
}
