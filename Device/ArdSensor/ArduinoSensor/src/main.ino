#include <Arduino.h>
#include <ArduinoJson.h>

void setup() {
  randomSeed(analogRead(0));
  Serial.begin(115200);
}

void loop() {
  delay(random(5,20)*1000);
  sendData();
}

void sendData() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& msg = jsonBuffer.createObject();
  msg["voltage"] = float(random(0,10))*random(0,10);
  msg["current"] = float(random(0,10))*(random(0,2)+0.3);
  msg["temperature"] = random(10,60) + (random(0,10)*0.1);
  String out;
  msg.printTo(out);
  Serial.println(out);
}
