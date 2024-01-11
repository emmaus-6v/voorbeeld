#include "src/Teller.cpp"

const int TELLER_A_PIN = 5;             // pin waarop IR-sensor voor Teller A is aangesloten

unsigned long laatsteTellerPrintTijd = 0;
const int TELLERPRINTINTERVAL = 1000;  // 1000 milliseconden

Teller tellerA = Teller(TELLER_A_PIN);

void setup() {
  Serial.begin(9600);
}


void loop() {
  // laat de teller detecteren:
  tellerA.update();

  if (millis() > laatsteTellerPrintTijd + TELLERPRINTINTERVAL) {
    // print het getelde aantal knikkers
    Serial.print("Getelde knikkers: ");
    Serial.println(tellerA.getAantal());

    // stel de tijd waarop voor het laatst geprint
    // werd in op 'nu'
    laatsteTellerPrintTijd = millis();
  }

}
