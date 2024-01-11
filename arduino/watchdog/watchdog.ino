#include "src/KnikkerPoort.cpp"

const int BOVEN_POORT_PIN = 7;          // pin van servo die bovenste poort reg
const int KNOP_PIN = 2;


KnikkerPoort poortBoven = KnikkerPoort();

void setup() {
  Serial.begin(9600);
  pinMode(KNOP_PIN, INPUT);
  
  poortBoven.begin(BOVEN_POORT_PIN, 0, 90);

  poortBoven.open();
}


void loop() {
  
  // Als de knop iedere seconde wordt ingedrukt, gaat de poort open.
  // Duurt het langer dan een seconde voordat de knop wordt ingedrukt,
  // dan gaat de knop dicht totdat er weer een keer op de knop wordt gedrukt.
  

}
