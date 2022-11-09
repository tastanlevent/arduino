#define BLYNK_TEMPLATE_ID "TMPLy-Pic2hK"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "5ruVCBc7ht3tmW4guBbm1exBBqvR-VaH"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "NetworkName";
char pass[] = "NetworkPass";

int sensorPin = A0;
int buzzerPin = 4;
int veri;

BLYNK_WRITE(V4){
  int pinvalue = param.asInt();
  digitalWrite(buzzerPin, pinvalue);
}
void setup() {
 Blynk.begin(auth, ssid, pass);
 pinMode(buzzerPin, OUTPUT);
 pinMode(sensorPin, INPUT);
 Serial.begin(9600);
}

void loop() {
   Blynk.run();
  int okunan = analogRead(sensorPin);
  if(okunan < 750){
    digitalWrite(buzzerPin, HIGH);
    Blynk.logEvent("acil_durum", "Su kaçağı var. Vanayı Kapatın !!");
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }
  Serial.println(okunan);
  delay(100);
}