/*
  DHT22 Sensor Reading with NTP Timestamp – FireBeetle 2 ESP32-E
  ----------------------------------------------------------------
  This sketch reads temperature and humidity from a DHT22 sensor
  connected to GPIO 17 on the ESP32, and prints the readings
  along with a real-time timestamp fetched from an NTP server.

  Author: Raihan Bin Mofidul  
  GitHub: https://github.com/xundullah  
  Platform: FireBeetle 2 ESP32-E (32MB Flash / 512KB RAM, Wi-Fi & Bluetooth)  
  Product Link: https://www.dfrobot.com/product-2195.html
*/

#include <Arduino.h>
#include <DHT.h>          // Library for DHT sensors (install Adafruit version)
#include <WiFi.h>         // ESP32 Wi-Fi library (install esp32 by Espressif Systems)
#include <WiFiUdp.h>      // For UDP communication with NTP server 
#include <NTPClient.h>    // Lightweight NTP client for time sync (by Fabrice Weinberg)

// ====== Wi-Fi credentials ======
const char* ssid     = "workshop";       // Replace with your Wi-Fi SSID
const char* password = "rbm12345";       // Replace with your Wi-Fi password

// ====== DHT Sensor Configuration ======
#define DHTPIN 17          // Connect DHT22 data pin to GPIO 17
#define DHTTYPE DHT22      // Sensor type is DHT22 (also called AM2302)
DHT dht(DHTPIN, DHTTYPE);  // Initialize the DHT object with defined pin and type

// ====== NTP Client Setup ======
WiFiUDP ntpUDP;                          // Create a UDP object
const long utcOffsetInSeconds  = 36000;  // UTC+10 for Sydney = 10*60*60 = 36000 sec
const long updateIntervalMs    = 60000;  // NTP sync every 60 seconds (60000 ms)
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds, updateIntervalMs);  // Initialize NTP client

void setup() {
  Serial.begin(115200);  // Start serial communication for debugging
  delay(2000);           // Optional startup delay for sensor stability

  // ====== Connect to Wi-Fi ======
  Serial.print("Connecting to Wi-Fi");
  WiFi.begin(ssid, password);         // Begin Wi-Fi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ Wi-Fi connected.");

  // ====== Start Sensors and Time ======
  dht.begin();           // Start communication with DHT sensor
  timeClient.begin();    // Start NTP time client
  timeClient.update();   // Get initial time from the server

  Serial.println("📡 Ready to read temperature, humidity, and timestamp.");
}

void loop() {
  // ====== Update NTP Time ======
  timeClient.update();                          // Refresh current time from NTP server

  // ====== Read Sensor Values ======
  float humidity    = dht.readHumidity();       // Read humidity in %
  float temperature = dht.readTemperature();    // Read temperature in Celsius

  // ====== Validate Readings ======
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("❌ Failed to read from DHT22 sensor!");
  } else {
    // ====== Format Epoch Time into Human-Readable Date-Time ======
    unsigned long epoch = timeClient.getEpochTime();      // Get Unix epoch time
    time_t rawTime = epoch;                               // Convert to time_t format
    struct tm* timeinfo = localtime(&rawTime);            // Convert to local time components

    // Build a timestamp string in "YYYY-MM-DD HH:MM:SS" format
    char dateTimeStr[25];

    sprintf(dateTimeStr, "%04d-%02d-%02d %02d:%02d:%02d",  // Format: "YYYY-MM-DD HH:MM:SS"
        timeinfo->tm_year + 1900,  // tm_year = years since 1900 → add 1900 to get full year (e.g., 2025)
        timeinfo->tm_mon + 1,      // tm_mon = months since January (0–11) → add 1 to get calendar month (1–12)
        timeinfo->tm_mday,         // tm_mday = day of the month (1–31)
        timeinfo->tm_hour,         // tm_hour = hours since midnight (0–23)
        timeinfo->tm_min,          // tm_min = minutes after the hour (0–59)
        timeinfo->tm_sec);         // tm_sec = seconds after the minute (0–59)


    // ====== Print Timestamped Sensor Readings ======
    Serial.print("Timestamp: ");
    Serial.print(dateTimeStr);
    Serial.print(" | Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");
  }

  delay(1000);  // Wait 1 second before next reading
}

