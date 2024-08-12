#include "MyHAL.h"

void MyHAL::_delay(unsigned long _mill) {
  delay(_mill);
}

unsigned long MyHAL::_millis() {
  return millis();
}

unsigned long MyHAL::_getTick() {
  return millis();
}

unsigned long MyHAL::_getRandomSeed() {
  static uint32_t seed = analogRead(0);

  return seed;
}


void MyHAL::_log(const String &s){
    Serial.begin(9600);
    Serial.println(s);
    delay(500);
}