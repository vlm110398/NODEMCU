#include <Servo.h>
#include <TM1637Display.h>
#define CLK D5 //can be any digital pin
#define DIO D6 //can be any digital pin
 

const int in = A0;
Servo s;
int value, valueMap;
TM1637Display display(CLK, DIO);




void setup (){
  Serial.begin(115200);
  s.attach(D2);
  pinMode(in, INPUT_PULLUP); 
  display.setBrightness(7);
}

void loop(){
  value = analogRead(in);
  Serial.print("Potenciometro: ");
  Serial.println(value);
  valueMap = map(value, 0, 1023, 0, 180);
  s.write (valueMap); 
  delay (10);
  value = s.read();
  Serial.print("Servo: ");
  Serial.println(value);
  display.showNumberDec(value);
}
