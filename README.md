# Workshop on: Real-Time-Embedded-IoT-System

This repository provides all required materials to conduct a hands-on **Embedded Systems Workshop** using the **FireBeetle 2 ESP32-E**, MQTT, Node-RED, and cloud-based monitoring.

---

## 📚 Workshop Outline

| Phase | Title                                       | Description                                                                 |
|-------|---------------------------------------------|-----------------------------------------------------------------------------|
| 1️⃣    | LED Control with ESP32                     | Local digital I/O example: read a button, control onboard LED               |
| 2️⃣    | DHT22 Sensor Integration                   | Acquire room temperature and humidity using DHT22 sensor                    |
| 3️⃣    | Timestamped Sensor Data with NTP           | Attach date-time using WiFi and NTP client                                  |
| 4️⃣    | Real-Time MQTT Monitoring & LED Control    | Publish sensor data and control LED via MQTT broker and Node-RED dashboard |
| 🔁    | Broker + Cloud Ops Setup                    | Setup secure Mosquitto broker & run Node-RED dashboard on localhost/cloud  |

---

## 📁 Repository Structure


```

.
├── Broker Setup
│   ├── configured\_files/
│   ├── Instruction on Broker Setup.md
│   └── mosquitto-2.0.22-install-windows.exe
│
├── Cloud Operations
│   ├── Screenshots/
│   ├── Instruction on Cloud Operations.md
│   └── node-v22.17.0-x64.msi
│
├── Embedded System
│   ├── 1__LED_On_or_Off
│   ├── 2__DHT22_Room_Temp_n_Hum
│   ├── 3__WiFi_n_NTP_Timestamp
│   ├── 4__Realtime_Monitoring_n_Control
│   ├── Screenshots/
│   └── Instruction on Embedded System.md
│
├── LICENSE
└── README.md

```

---

## 🚀 Embedded System Examples

These four progressive examples are located in `/Embedded System`. Each sketch introduces a new concept in embedded programming, sensor interfacing, or IoT communication.

| Sketch No. | Description                                       | Key Components                      |
|------------|---------------------------------------------------|-------------------------------------|
| 1️⃣         | LED Toggle using onboard button                   | GPIO control, Serial output         |
| 2️⃣         | Temperature & Humidity Monitoring via DHT22       | DHT22, Sensor interfacing           |
| 3️⃣         | WiFi + NTP Timestamp Addition                     | WiFi config, NTPClient library      |
| 4️⃣         | MQTT-based Real-Time Monitoring & LED Control     | PubSubClient, JSON, MQTT subscribe  |

👉 See `Instruction on Embedded System.md` for detailed setup and wiring.

---

## 🌐 MQTT & Cloud Visualization

Set up local MQTT broker and use Node-RED dashboard to:

- Visualize real-time temperature & humidity
- Control LED using dashboard switch
- Monitor JSON payloads sent over MQTT

### Broker Setup:

📂 `Broker Setup/Instruction on Broker Setup.md`  
Includes Mosquitto install, user-password setup, and testing guidance.

### Node-RED Dashboard:

📂 `Cloud Operations/Instruction on Cloud Operations.md`  
Describes Node.js setup, Node-RED dashboard deployment, and UI creation using these widgets:
- LED Switch (`Dashboard_LED_ON.jpg`)
- Temperature Gauge & Level (`T_gauge.png`, `T_level.png`)
- Humidity Chart & Gauge (`H_chart.png`, `H_gauge.png`)
- Payload Text Grouping (`DT_txt.png`, `DT_T_H_LED_Grouping.png`)

---

## 🔌 Required Arduino Libraries

Install the following via Arduino Library Manager:

📚 **[✓] PubSubClient** by Nick O'Leary  
📚 **[✓] DHT sensor library** by Adafruit  
📚 **[✓] NTPClient** by Fabrice Weinberg  

📦 **[✓] Board Manager: esp32** by Espressif Systems  
➡️ Choose **FireBeetle 2 ESP32-E** from board list  
➡️ Select appropriate **COM port** before uploading

📷 *See screenshots in `Embedded System/Screenshots/` for guidance*

---

## 🖥 Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software)
- [Node.js (v22+)](https://nodejs.org/)
- [Mosquitto MQTT Broker](https://mosquitto.org/)
- [Node-RED](https://nodered.org/)

---

## 📌 Notes

- Test WiFi credentials before uploading
- Broker IP is typically: `192.168.137.1`
- Default MQTT topics:
  - Publish: `Tutor.DHT`
  - Subscribe: `Tutor.LED`
- Run `mosquitto -v -c MQTT-secure.conf` to start broker with user-password authentication

---

## 👨‍🏫 Author

**Raihan Bin Mofidul**  
Embedded Systems & IoT Researcher  
🔗 [Google Scholar](https://scholar.google.com.au/citations?user=RHXWFqIAAAAJ&hl)

For collaboration or technical queries, please feel free to reach out.

---

## 🤝 License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.

---

Happy prototyping! 🌐💡📡
