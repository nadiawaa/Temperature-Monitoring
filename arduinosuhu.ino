/* program to detect temperatures above 35oC. When it happened, the LED turn on and give some sound output.
*Board  : Arduino UNO
*Sensor : DHT11,
*Output : LED, Buzzer
*/ 

#include <DHT.h>             // Library DHT
#define DHTPIN 7             // DHT11 pin D7
#define DHTTYPE DHT11        // type sensor DHT11
DHT dht(DHTPIN,DHTTYPE);     // set sensor + pin

int ledR=2;                 //LED pin D2
int buzzer=6;               //buzzer pin D6

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ledR, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int t = dht.readTemperature();

  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");
  delay(500);

  if(t>35){
    digitalWrite (ledR,HIGH);
    digitalWrite (buzzer,HIGH);
  }else{
    digitalWrite (ledR,LOW);
    digitalWrite (buzzer,LOW);
  }
}
  
