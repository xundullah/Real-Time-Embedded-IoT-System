🧭 Eclipse Mosquitto Broker Setup (Windows 64-bit)
🔹 About Mosquitto
Eclipse Mosquitto is an open-source MQTT message broker that supports versions 5.0, 3.1.1, and 3.1 of the protocol. It’s lightweight and ideal for Internet of Things (IoT) communication on systems ranging from embedded devices to full servers.

It uses the publish/subscribe model, making it highly efficient for real-time data transfer in sensor networks, mobile devices, and embedded systems.

✅ Step-by-Step Installation and Setup
🔽 1. Download Mosquitto Installer
Download the latest stable Windows 64-bit installer:

🔗 mosquitto-2.0.22-install-windows-x64.exe

💾 2. Install Mosquitto
Run the .exe installer.

During installation, make sure to select:

✅ Install service

✅ Add PATH variable (optional but helpful)

🔐 3. Create MQTT Password File
Open Command Prompt as Administrator and run the following:

bash
Copy code
cd "C:\Program Files\mosquitto"
mosquitto_passwd -c passwd.txt mqttuser
Replace mqttuser with your preferred username.

You will be prompted to enter and confirm the password.

📁 This will create a password file named passwd.txt in the Mosquitto directory.

🛡️ 4. Create Secure Mosquitto Config File
Inside the same folder (C:\Program Files\mosquitto), create a file named:

secure_mosquitto.conf

With the following content:

conf
Copy code
listener 1883
allow_anonymous false
password_file passwd.txt
💡 This ensures only authenticated clients can connect.

🔁 5. Restart Mosquitto with New Config
If Mosquitto is already running, stop it first:

bash
Copy code
taskkill /F /IM mosquitto.exe
Then start Mosquitto with the secure config:

bash
Copy code
mosquitto -v -c secure_mosquitto.conf
🟢 You should now see Listening on port 1883 and password authentication enabled.

🔓 6. Allow MQTT Port in Firewall (1883)
To allow external clients to connect, open port 1883 for TCP in both inbound and outbound rules:

Open Windows Defender Firewall → Advanced Settings

Go to Inbound Rules → New Rule

Rule Type: Port

Protocol: TCP

Port: 1883

Allow the connection

Repeat for Outbound Rules

🎉 You're Done!
Your secure MQTT broker is now ready. Clients like ESP32, Node-RED, or mosquitto_sub/pub can connect using:

Host: your PC's IP address

Port: 1883

Username: mqttuser

Password: your chosen password