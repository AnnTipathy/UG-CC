/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

#define LED_BUILTIN 2 // GPIO2, the blue LED

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

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

  Serial.println("Sketch: Blink.ino, V1.0");

  Serial.println("\nBegin loop");
  }

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // change state of the LED by setting the pin to the HIGH voltage level
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // change state of the LED by setting the pin to the LOW voltage level
  delay(1000);                      // wait for a second
}
