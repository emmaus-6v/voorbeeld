#include "src/Teller.cpp"
#include "src/WiFiNINA/WiFiNINA.h"

int status = WL_IDLE_STATUS;

const int TELLER_A_PIN = 5;  // pin waarop IR-sensor voor Teller A is aangesloten

unsigned long laatsteTellerPrintTijd = 0;
const int TELLERPRINTINTERVAL = 1000;  // 1000 milliseconden

Teller tellerA = Teller(TELLER_A_PIN);

void setup() {
  Serial.begin(9600);

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true)
      ;
  }

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin("knikkerbaan", "roodblauwgeelwit");

    // wait 5 seconds for connection:
    delay(5000);
  }

  Serial.println("Connected to WiFi");

  
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
