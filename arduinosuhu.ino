/* program to detect temperatures above 35oC. When it happened, the LED turn on and give some sound output.
the type of microcontroller used is arduino uno, the sensor used is a dht11 temperature sensor and a buzzer to make sound
*/ 

#include <DHT.h>
#define DHTPIN 7             // DHT11 pin D7
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

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
  
