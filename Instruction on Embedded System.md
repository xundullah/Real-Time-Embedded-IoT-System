# 🔧 Arduino IDE Setup & FireBeetle 2 ESP32-E Project Guide

This document provides instructions to install the necessary tools and libraries, configure the board, and run 4 step-wise embedded system sketches for the **FireBeetle 2 ESP32-E**.

---

## ⚙️ Arduino IDE Installation (v2.3.6)

➡️ Download the latest [Arduino IDE 2.3.6](https://www.arduino.cc/en/software) for your OS and install it.

---

## 📦 Board and Library Installation

Follow the instructions below to install the required board definitions and libraries.

### ✅ Board Setup: ESP32 by Espressif

![ESP32 Boards Setup](esp32 by Espressif Systems.png)

1. Open the **Boards Manager**.
2. Search: `ESP 32`
3. Install `esp32 by Espressif Systems` (version 3.2.1 recommended).

---

### ✅ Library Installation

Install the following libraries via the **Library Manager** (Ctrl + Shift + I):

| Library | Screenshot |
|--------|------------|
| **PubSubClient by Nick O'Leary** – MQTT messaging | ![PubSubClient](PubSubClient by Nick.png) |
| **DHT sensor library by Adafruit** – Temp & Humidity | ![DHT](DHT by Adafruit.png) |
| **NTPClient by Fabrice Weinberg** – Time sync | ![NTPClient](NTPClient by Fabrice.png) |

---

## 🔌 Board & Port Selection

Make sure your **FireBeetle 2 ESP32-E** is properly connected via USB.

![Board Selection](Select Board and Port.png)

- **Board**: FireBeetle 2 ESP32-E  
- **Port**: COM port as detected (e.g., `COM4`)

---

## 🧪 Embedded System Examples

This section outlines 4 progressively enhanced examples located in `/Embedded System`.

---

## 1️⃣ LED On/Off Control  
📂 `Embedded System/1__LED_On_or_Off/`

🔹 Uses the onboard button to toggle the onboard LED.  
🔹 Ideal as your first I/O test.

🛠 **Features**:
- Button input: GPIO 27
- LED output: GPIO 2
- Serial log for button press events

📄 **Usage**:
- Upload and open Serial Monitor (`115200`)
- Press onboard button (D4) to toggle the LED

---

## 2️⃣ Room Temperature & Humidity Monitoring  
📂 `Embedded System/2__DHT22_Room_Temp_n_Hum/`

🔹 Reads data from the DHT22 sensor and prints to Serial.

📄 **Wiring**:
- Data → GPIO 17  
- VCC → 3.3V  
- GND → GND  

🧪 **Output**:
```

Temperature: 23.1 °C  |  Humidity: 56.5 %

```

---

## 3️⃣ Sensor Reading with Real-Time Timestamp  
📂 `Embedded System/3__WiFi_n_NTP_Timestamp/`

🔹 Connects to Wi-Fi and fetches NTP time from `pool.ntp.org`.

🛠 **Features**:
- Real-time timestamp
- DHT22 readings with time context

🧪 **Sample Output**:
```

✅ WiFi connected.
📡 Timestamp: 2025-07-15 10:42:31 | Temp: 22.6°C | Humidity: 59.3%

````

---

## 4️⃣ Real-Time Monitoring and Control via MQTT  
📂 `Embedded System/4__Realtime_Monitoring_n_Control/`

🔹 Combines all features: sensor read, timestamp, and MQTT communication.

🛠 **Features**:
- Publishes data to topic: `Tutor.DHT`
- Subscribes to topic: `Tutor.LED`
- JSON payload includes DateTime, Temperature, Humidity
- Onboard LED turns ON/OFF based on subscribed command

📡 **MQTT Broker Settings**:
- Host: `192.168.137.1`
- Port: `1883`
- Username: `mqttuser`
- Password: `1234`

🧪 **Sample Payload**:
```json
{
  "DT": "2025-07-15 10:45:30",
  "T": 22.9,
  "H": 58.7
}
````

---

## 📊 Summary Table

| Sketch | Description                           |
| ------ | ------------------------------------- |
| 1️⃣    | LED toggle with onboard button        |
| 2️⃣    | Room temperature and humidity readout |
| 3️⃣    | Adds Wi-Fi & real-time NTP timestamp  |
| 4️⃣    | Full MQTT dashboard integration       |

---

## 🧰 Support

📚 **Required Libraries**:

* `PubSubClient`
* `DHT sensor library`
* `NTPClient`

🧱 **Board**:

* FireBeetle 2 ESP32-E
  🔗 [Product Page](https://www.dfrobot.com/product-2195.html)


