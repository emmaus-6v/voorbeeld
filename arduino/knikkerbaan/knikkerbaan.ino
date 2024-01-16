#include "src/Teller.cpp"
#include "src/WiFiNINA/WiFiNINA.h"
#include "src/Firebase/Firebase_Arduino_WiFiNINA.h"

#define DATABASE_URL "kbaan-3c854-default-rtdb.europe-west1.firebasedatabase.app"  //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
#define DATABASE_SECRET "WiMVzQCOn3Z337zmGjcCjAxsCOEad9VHurWLDje4"
#define WIFI_SSID "knikkerbaan"
#define WIFI_PASSWORD "roodblauwgeelwit"

int status = WL_IDLE_STATUS;

const int TELLER_A_PIN = 5;  // pin waarop IR-sensor voor Teller A is aangesloten

unsigned long laatsteTellerPrintTijd = 0;
const int TELLERPRINTINTERVAL = 1000;  // 1000 milliseconden

FirebaseData fbdo;  // database object
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

  Firebase.begin(DATABASE_URL, DATABASE_SECRET, WIFI_SSID, WIFI_PASSWORD);
  Firebase.reconnectWiFi(true);
}


void loop() {
  // laat de teller detecteren:
  tellerA.update();

  if (millis() > laatsteTellerPrintTijd + TELLERPRINTINTERVAL) {
    // print het getelde aantal knikkers
    Serial.print("Getelde knikkers: ");
    Serial.println(tellerA.getAantal());

    // stuur aantal knikkers naar database:
    if (Firebase.setInt(fbdo, "teams/team everest/aantalKnikkers", tellerA.getAantal())) {
      Serial.println("FB set gelukt!");
    } else {
      Serial.println("FB set niet gelukt!");
      Serial.println(fbdo.errorReason());
    }

    // haal 'supergetal' op van database
    if (Firebase.getInt(fbdo, "teams/team everest/supergetal")) {
      Serial.println("FB get gelukt!");
      int supergetal = fbdo.intData();
      Serial.print("supergetal uit db is: ");
      Serial.println(supergetal);
    } else {
      Serial.println("FB set niet gelukt!");
      Serial.println(fbdo.errorReason());
    }

    // stel de tijd waarop voor het laatst geprint
    // werd in op 'nu'
    laatsteTellerPrintTijd = millis();
  }
}
