#include<Button.h>

#if ARDUINO >= 100
  #include "Arduino.h"
#else
extern "C" {
    #include "WConstatets.h"
}
#endif

Button::Button() {
  m_pin = -1;
  m_state = false;
  Serial.print("Konst bezparam, adres: ");
  Serial.println((int)this);
}

Button::Button(int pin) {
	pinMode(pin, INPUT);
	m_pin = pin;
	m_state = false;
  Serial.print("Konst param, adres: ");
  Serial.println((int)this);
}

Button::Button(Button& other) {
  m_pin = other.m_pin;
  m_state = other.m_state;
  pinMode(m_pin, INPUT);
  Serial.print("Konst kop, adres: ");
  Serial.println((int)this);
}

Button::~Button() {}

void Button::checkIfPushed() {
	if((m_state == false) and (digitalRead(m_pin) == HIGH)) {
		delay(20);
		m_state = true;
		while(digitalRead(m_pin) == HIGH);
		delay(20);
	}
}

bool Button::isPushed() {
	if(m_state == true) {
		m_state = false;
		return true;
	}
	else {
		return false;
	}
}
