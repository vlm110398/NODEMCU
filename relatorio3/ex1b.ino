#include <Servo.h>
Servo s; 

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  pinMode(D2, OUTPUT);
  s.attach(D2);
}

// the loop routine runs over and over again forever:
void loop() {
  int potencia = analogRead(A0);
  Serial.println(potencia);
  int saida = map(potencia, 0, 1023, 0, 180);
  s.write(saida);
  Serial.println(saida);
  delay(10);
  //potencia=map(potencia,0,1023,180);
  //analogWrite(D2,potencia);
}
