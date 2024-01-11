#ifndef TELLER
#define TELLER

#include <Arduino.h>

class Teller {
  private:
    int pin;
    bool vorigeKeerOnderbroken;
    unsigned long laatstOnderbrokenMillis = 0;
    const int DEBOUNCE_TIME = 10;

    bool opnieuwOnderbroken() {
      return (vorigeKeerOnderbroken == false && nuOnderbroken() == true);
    }

    int aantal = 0;

  public:
    Teller(int _pin) {
      pinMode(_pin, INPUT_PULLUP);
      pin = _pin;
      vorigeKeerOnderbroken = false;
    }
    
    bool nuOnderbroken() {
      return !digitalRead(pin);
    }

    void update() {
      if (opnieuwOnderbroken()) {
        if (millis() - laatstOnderbrokenMillis > DEBOUNCE_TIME) {
          aantal++;
        } 
      }

      vorigeKeerOnderbroken = nuOnderbroken();
    }

    int getAantal() {
      return aantal;
    }
};

#endif
