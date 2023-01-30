//Alimentar NodeMCU com 3.3v, com 5v a medição fica variando; alimentar modulo hcsr04 com 5v.

//LIBS
#include <LiquidCrystal.h>

//IO
#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define D9 3    //RX
#define D10 1   //TX

//ID pinos
//modulo hcsr04
const int trigPin = D6;
const int echoPin = D7;
//modulo lcd
const int v0 = D3; //contraste
const int rs = D4, en = D5, d4 = D2, d5 = D9, d6 = D10, d7 = D0;

//INIT
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(v0, OUTPUT);
  analogWrite(v0, 96);
  lcd.begin(16, 2); //iniciar depois de pinMode/initPins
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance; //ou float para mais precisao
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(distance);
  lcd.setCursor(4, 0);
  lcd.print("cm");
  delay(500); //intervalo de leituras em ms
}
