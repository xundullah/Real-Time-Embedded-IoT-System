## 🌐 Node-RED Setup for Monitoring, Control, and Cloud Operations

### 🔹 About Node-RED

Node-RED is a powerful **low-code programming tool** for wiring together **hardware devices, APIs, and online services**. It enables users to **collect, transform, and visualize data** through simple, browser-based flows.

Built on **Node.js**, Node-RED is event-driven and lightweight—ideal for real-time control systems, edge computing on devices like Raspberry Pi, or even cloud-based automation.

---

### ✅ Running Node-RED on Windows

This guide explains how to install and run Node-RED in a **Windows 10/11 environment**. PowerShell is recommended over `cmd` for better compatibility with Unix-style commands.

---

### ⚙️ Step-by-Step Instructions

#### 🟢 1. Install Node.js

- Download the latest **LTS (Long-Term Support)** version from:
  👉 [https://nodejs.org/en/download](https://nodejs.org/en/download)

- Run the `.msi` installer with **administrator privileges** and accept all default settings.

- After installation, open **PowerShell** or **Command Prompt** and verify installation:

```powershell
node --version; npm --version
````

Expected output:

```
v18.15.0
9.5.0
```

---

#### 🔴 2. Install Node-RED Globally

Install Node-RED as a global npm module:

```bash
npm install -g --unsafe-perm node-red
```

This command adds the `node-red` command to your system path.

---

#### 🚀 3. Run Node-RED

Once installed, launch Node-RED by running:

```bash
node-red
```

You should see terminal output indicating the server is running, ending with something like:

```
Server now running at http://127.0.0.1:1880/
```

Open a browser and navigate to:
📍 `http://localhost:1880`

This opens the **Node-RED Flow Editor**.

---

### 📊 Use Cases in This Workshop

Node-RED will be used to:

* **Monitor**: Display real-time temperature and humidity readings from ESP32.
* **Control**: Send MQTT messages to ESP32 to turn the LED on/off.
* **Cloud Operations**: Forward sensor data to online platforms or dashboards.

---

### 📁 Next Steps

You can now:

* Create **MQTT input/output nodes**
* Use **dashboard UI nodes** for visualization
* Connect to your **local Mosquitto broker (port 1883)**

Example:

* MQTT Broker: `192.168.137.1`
* Port: `1883`
* Topic: `Group.DHT` (subscribe)
* Topic: `Group.LED` (publish)



---
---

### 🔧 Configuring MQTT Broker in Node-RED

Set up your MQTT Broker using the following settings:

- **Server**: `192.168.137.1`
- **Port**: `1883`
- **Authentication**: I have initially added username as `mqttuser` and password as `1234` under the `Security` tab. You can set yours

#### 📡 MQTT Broker Connection Settings

<img src="Screenshots/Broker_Connection.png" alt="MQTT Broker Config in Node-RED - Connection Tab" width="600">

#### 🔒 MQTT Broker Security Settings

<img src="Screenshots/Broker_Security.png" alt="MQTT Broker Config in Node-RED - Security Tab" width="600">




---
### 🌡️ Receiving Sensor Data via MQTT In Node

To read real-time **Temperature and Humidity** data from the **DHT22 sensor** (connected to ESP32 FireBeetle), configure a **`mqtt in` node** in Node-RED.

This node will **subscribe** to the topic published by the ESP32 device using the Mosquitto broker.


#### 🛠 Configuration Details:

- **Server**: `Mosquitto` (pre-configured in earlier steps)
- **Action**: `Subscribe to single topic`
- **Topic**: `Tutor.DHT`
- **QoS**: `0` (default)
- **Output**: `auto-detect (parsed JSON)`
- **Name**: `Tutor.DHT`

> 📌 This setup allows Node-RED to parse JSON data like:
> ```json
> {
>   "DT": "2025-07-15 10:42:31",
>   "T": 28.54,
>   "H": 65.32
> }
> ```

#### 📷 MQTT In Node Configuration

<img src="Screenshots/MQTT_in_DHT.png" alt="MQTT In Node - DHT22 Sensor" width="600">




---
### 🧩 Installing the Node-RED Dashboard Palette

To visualize sensor readings and implement control elements like buttons and gauges, install the **Node-RED Dashboard** nodes.

These nodes allow you to create interactive web-based dashboards from your Node-RED flows.

#### 🛠 Installation Steps:

1. Open Node-RED in your browser (`http://localhost:1880`)
2. Click the menu (☰) → **Manage palette**
3. Go to the **Install** tab
4. Search for: `dashboard`
5. Find `node-red-dashboard` and click **Install**

> 🔗 This package provides UI elements such as charts, gauges, switches, and text output blocks for building custom dashboards.

#### 📷 Dashboard Palette Installation View

<img src="Screenshots/Dashboard_Palette.png" alt="Install Node-RED Dashboard Palette" width="600">
