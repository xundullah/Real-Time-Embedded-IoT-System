/*
  DHT22 Sensor Reading – FireBeetle 2 ESP32-E
  --------------------------------------------
  This example reads temperature and humidity from a DHT22 sensor
  connected to GPIO 17 (digital input) on the FireBeetle 2 ESP32-E.

  Author: Raihan Bin Mofidul  
  GitHub: https://github.com/xundullah  
  Platform: FireBeetle 2 ESP32-E (32MB Flash / 512KB RAM, Wi-Fi & Bluetooth)  
  Product Link: https://www.dfrobot.com/product-2195.html
*/

#include <Arduino.h>
#include <DHT.h>          // DHT sensor library by Adafruit

// Define pin and DHT sensor type
#define DHTPIN 17         // GPIO 17 for DHT22 data line
#define DHTTYPE DHT22     // DHT22 (AM2302)

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  dht.begin();           // Start DHT sensor

  Serial.println("Reading temperature and humidity from DHT22...");
}

void loop() {
  // Read temperature and humidity values
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();  // Default in Celsius

  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT22 sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C  |  Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(1000);  // Wait 1 second between readings
}