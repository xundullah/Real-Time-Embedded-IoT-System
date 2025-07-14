// ====== Import Libraries ======
#include <Arduino.h>
#include <DHT.h>          // Library for DHT sensors (install Adafruit version)
#include <WiFi.h>         // ESP32 Wi-Fi library (install esp32 by Espressif Systems)
#include <WiFiUdp.h>      // For UDP communication with NTP server 
#include <NTPClient.h>    // Lightweight NTP client for time sync (by Fabrice Weinberg)
#include <PubSubClient.h> // A Client Library for MQTT messages (by Nick O'Leary)

// ==== Pin Config ====
#define DHTPIN       17
#define DHTTYPE      DHT22
#define LED_PIN      2     // Onboard LED
#define BUTTON_PIN   27    // Optional button
DHT dht(DHTPIN, DHTTYPE);

// ==== WiFi ====
const char* ssid = "workshop";
const char* password = "rbm12345";

// ==== MQTT ====
const char* mqtt_server     = "192.168.137.1";
const int mqtt_port         = 1883;
const char* mqtt_username   = "mqttuser";
const char* mqtt_password   = "1234";
const char* mqtt_client     = "ESP32.Tutor";   //Alpha, Beta, Gamma, Eta, Lamda During Handson Training
const char* mqtt_pub_topic  = "Tutor.DHT";     //
const char* mqtt_sub_topic  = "Tutor.LED";

// ==== MQTT JSON keys ====
const char* MQTT_pubObj01 = "DT";
const char* MQTT_pubObj02 = "T";
const char* MQTT_pubObj03 = "H";

// ==== NTP ====
WiFiUDP ntpUDP;
const long utcOffsetInSeconds = 36000;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

// ==== MQTT Setup ====
WiFiClient espClient;
PubSubClient client(espClient);

// ==== State ====
bool ledState = false;
bool prevButtonState = HIGH; // Optional for button use

// ==== WiFi Connect ====
void setupWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\n✅ WiFi connected.");
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

// ==== MQTT Callback ====
void mqttCallback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';  // Null-terminate payload
  String message = String((char*)payload);
  Serial.print("📩 MQTT msg on topic ["); Serial.print(topic); Serial.print("]: "); Serial.println(message);

  if (String(topic) == mqtt_sub_topic) {
    if (message == "On" || message == "ON") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("💡 LED turned ON via MQTT.");
    } else if (message == "Off" || message == "OFF") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("💡 LED turned OFF via MQTT.");
    } else {
      Serial.println("⚠️ Unknown LED command.");
    }
  }
}

// ==== MQTT Reconnect ====
void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT... ");
    Serial.print("📡 Subscribing to topic: ");
    Serial.println(mqtt_sub_topic);
    client.subscribe(mqtt_sub_topic);
    if (client.connect(mqtt_client, mqtt_username, mqtt_password)) {
      Serial.println("✅ Connected.");
      client.subscribe(mqtt_sub_topic);
    } else {
      Serial.print("❌ Failed (rc="); Serial.print(client.state()); Serial.println("). Retry...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Start OFF
  // pinMode(BUTTON_PIN, INPUT_PULLUP); // Optional

  dht.begin();
  setupWiFi();
  timeClient.begin();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(mqttCallback);
}

void loop() {
  if (!client.connected()) reconnectMQTT();
  client.loop();
  timeClient.update();

  float temperature = dht.readTemperature();
  float humidity    = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("❌ Sensor read failed.");
    delay(2000);
    return;
  }

  // Format time
  time_t rawTime = timeClient.getEpochTime();
  struct tm* timeinfo = localtime(&rawTime);
  char formattedDate[25];
  sprintf(formattedDate, "%04d-%02d-%02d %02d:%02d:%02d",
          timeinfo->tm_year + 1900,
          timeinfo->tm_mon + 1,
          timeinfo->tm_mday,
          timeinfo->tm_hour,
          timeinfo->tm_min,
          timeinfo->tm_sec);

  // Create JSON
  String msg;
  msg  = "{\"";
  msg += MQTT_pubObj01;
  msg += "\":\"";
  msg += formattedDate;
  msg += "\",\"";
  msg += MQTT_pubObj02;
  msg += "\":";
  msg += String(temperature, 2);
  msg += ",\"";
  msg += MQTT_pubObj03;
  msg += "\":";
  msg += String(humidity, 2);
  msg += "}";

  // Publish
  client.publish(mqtt_pub_topic, msg.c_str());
  Serial.print("📤 Out: "); Serial.println(msg);

  
  delay(1000);
}
