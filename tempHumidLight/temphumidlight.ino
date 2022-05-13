#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
SoftwareSerial HC06(2, 3); // RX, TX
int LIGHT_PIN = A0;                          
int LIGHT_THRESHOLD = 600;

void setup() {
  Serial.begin(9600); // pc - arduino
  HC06.begin(9600); //bluetooth - arduino
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  String data1 = String(h) + "," + String(t);
  HC06.print("T&H :");
  HC06.println(data1);
    
  Serial.print(h);
  Serial.print(",");
  Serial.println(t);
  
  delay(1000);
    // 조도 센서
  int val = analogRead(LIGHT_PIN);
   //VAL값이 크면 빛이 적음
   String data2 = String(val);
   HC06.print("L :");
   HC06.println(data2);
     
   Serial.print("ON : ");       
   Serial.println(val);
}
