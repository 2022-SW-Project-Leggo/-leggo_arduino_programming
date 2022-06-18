#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial HC06(2, 3); // RX, TX
int LIGHT_PIN = A0;                          
int LIGHT_THRESHOLD = 600;
int LED_PIN = 8;

void setup() {
  Serial.begin(9600); // pc - arduino
  HC06.begin(9600); //bluetooth - arduino
  dht.begin();
  pinMode(8,OUTPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  String data_t = String(t);
  String data_h = String(h);
  
  HC06.println(data_t);
  HC06.println(data_h);

  Serial.print("HUMID&TEMP : ");
  Serial.print(data_t);
  Serial.print(",");
  Serial.println(data_h);
  
  delay(1000);
  
  int val = analogRead(LIGHT_PIN);
  String data_l = String(val);
   
  HC06.println(data_l);
     
  Serial.print("LIGHT : ");       
  Serial.println(val);

  if (val >= 500) {
    digitalWrite(8,HIGH);
  }
  else {
    digitalWrite(8,LOW);
  }
}
