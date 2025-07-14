/*
  Button-Controlled LED – FireBeetle 2 ESP32-E
  --------------------------------------------
  This example reads the built-in push button (D4 / GPIO 27) on the FireBeetle 2 ESP32-E
  and toggles the onboard LED (GPIO 2) on each button press.

  Author: Raihan Bin Mofidul  
  GitHub: https://github.com/xundullah  
  Platform: FireBeetle 2 ESP32-E (32MB Flash / 512KB RAM, Wi-Fi & Bluetooth)  
  Product Link: https://www.dfrobot.com/product-2195.html
*/

#include <Arduino.h>

// Define pin mappings
#define LED_PIN     2     // Onboard LED (GPIO 2)
#define BUTTON_PIN  27    // Built-in push button (D4 / GPIO 27)

// Track LED state and previous button state
bool ledState = false;
bool prevButtonState = HIGH;  // Pull-up enabled, so HIGH means unpressed

void setup() {
  Serial.begin(115200);                 // Initialize serial communication
  pinMode(LED_PIN, OUTPUT);            // Set LED pin as output
  pinMode(BUTTON_PIN, INPUT_PULLUP);   // Set button pin as input with internal pull-up resistor

  digitalWrite(LED_PIN, ledState);     // Initialize LED state
  Serial.println("Press the onboard button (D4) to toggle the LED.");
}

void loop() {
  bool currentButtonState = digitalRead(BUTTON_PIN);  // Read current button state

  // Detect falling edge: button press (HIGH to LOW transition)
  if (prevButtonState == HIGH && currentButtonState == LOW) {
    ledState = !ledState;                   // Toggle LED state
    digitalWrite(LED_PIN, ledState);        // Apply new state to LED

    Serial.print("Button pressed. LED is now ");
    Serial.println(ledState ? "ON" : "OFF");
    delay(200);  // Debounce delay to avoid multiple triggers
  }

  prevButtonState = currentButtonState;  // Update for next loop
}