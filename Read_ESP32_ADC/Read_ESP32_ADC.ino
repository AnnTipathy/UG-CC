/*
 *  Read_ESP32_ADC.ino
 *
 *  Designed to run on an ESP32 DEVKIT v1 available from Addicore:
 *  https://www.addicore.com/products/esp32-devkit-v1-compatible-board?variant=51855314583869&oppcref=9f36f44e-acda-4827-9fbe-4201d9bfcaa5
 *
 *  Identifies the ESP32 hardware, identifies the Arduino Sketch,
 *  then repeatedly, turns the blue LED on, reads the ESP32 ADC value,
 *  transmits it to the Arduino IDE's Serial Monitor,
 *  turns the LED off, then waits a bit.  The transmission rate
 *  is about 2 Hz.  The voltage to be measured should be applied
 *  to D34.
 *
 *  Based on uncut-gem.ino from Quantum Village's Uncut Gem
 *  project.  https://quantumvillage.org/uncut-gem.html
 *
 *  November 17, 2026
 *
 */

//#include "Arduino.h"

#define LED_BUILTIN 2 // GPIO2, the blue LED
#define ADC_PIN 34    // ADC1, Channel 6

void setup() {
  // Initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Configure ADC resolution to 12 bits.
  analogReadResolution(12);

  // Configure input attenuation for an effective measurement
  // range of 150 ∼ 2450 mV.
  analogSetPinAttenuation(ADC_PIN, ADC_11db);
  
  Serial.begin(115200) ;
  while(!Serial){};
  delay(250); // give it a sec to warm up

  Serial.println("Setup: Serial port is open.");

  Serial.println("\nESP32 Hardware Identification");
  Serial.println("------------------------------");

  Serial.print("Chip Model: ");
  Serial.println(ESP.getChipModel());

  Serial.print("Chip Revision: ");
  Serial.println(ESP.getChipRevision());

  Serial.print("CPU Cores: ");
  Serial.println(ESP.getChipCores());

  Serial.print("CPU Frequency: ");
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz");

  Serial.print("Flash Size: ");
  Serial.print(ESP.getFlashChipSize() / 1024);
  Serial.println(" kB");

  Serial.print("Arduino ESP32 Version: ");
  Serial.println(ESP.getSdkVersion());

  uint64_t mac = ESP.getEfuseMac();

  char macStr[18];

  snprintf(macStr, sizeof(macStr),
           "%02X:%02X:%02X:%02X:%02X:%02X",
           (uint8_t)(mac >> 40),
           (uint8_t)(mac >> 32),
           (uint8_t)(mac >> 24),
           (uint8_t)(mac >> 16),
           (uint8_t)(mac >> 8),
           (uint8_t)mac);

  Serial.print("ESP32 MAC Address: ");
  Serial.println(macStr);

  Serial.println("\nArduino Sketch Identification");
  Serial.println("------------------------------");

  Serial.println("Sketch: Read_ESP32_ADC.ino, V1.0");
  Serial.println("ADC resolution: 12 bits");
  Serial.println("ADC input attenuation: 11 dB (150 ~ 2450 mV)");

  Serial.println("\nBegin loop");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Indicate the beginning of the ADC read.
  int ADC_out = analogReadMilliVolts(ADC_PIN);
  Serial.print("ADC Value = ");
  Serial.print(ADC_out);
  Serial.println(" mV");
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);   // Indicate the end of the ADC value transmission.
  delay(400);
}
