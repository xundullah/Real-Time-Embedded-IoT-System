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

### 🔧 Configuring MQTT Broker in Node-RED

Set up your MQTT Broker using the following settings:

- **Server**: `192.168.137.1`
- **Port**: `1883`
- **Protocol**: MQTT V3.1.1
- **Authentication**: Add username and password under the `Security` tab

![MQTT Broker Config in Node-RED](Cloud Operations\Screenshots\Broker_Connection.png)
