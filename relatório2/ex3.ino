
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int potencia = analogRead(A0);
  Serial.println(potencia);
  potencia=map(potencia,100,900,0,1023);
  analogWrite(D2,potencia);
}
