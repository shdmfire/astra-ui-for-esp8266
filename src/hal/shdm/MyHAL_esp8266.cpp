#include "MyHAL.h"

#define KEY1_Pin 14
#define KEY2_Pin 12

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

bool MyHAL::_getKey(key::KEY_INDEX _keyIndex)
{
  pinMode(KEY1_Pin, INPUT_PULLUP);
  pinMode(KEY2_Pin, INPUT_PULLUP);
  if (_keyIndex == key::KEY_0) return !digitalRead(KEY1_Pin);
  if (_keyIndex == key::KEY_1) return !digitalRead(KEY2_Pin);
  return false;
}