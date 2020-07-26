#define LDR1 0
#define LDR2 1
#define LM35 2

void setup() {
    Serial.begin(115200);
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
}

void loop() {
  Serial.print("LDR1 = ");
  Serial.println(ler(LDR1));
  delay(50);
  Serial.print("LDR2 = ");
  Serial.println(ler(LDR2));
  delay(50);
  Serial.print("LM35 = ");
  Serial.println(ler(LM35));
  delay(50);
}

int ler(int component) {
  switch (component) {
     case 0: 
        digitalWrite(D0, LOW);
        digitalWrite(D1, LOW);
        delay(10);
        return analogRead(A0);
        break;
     case 1:
        digitalWrite(D0, HIGH);
        digitalWrite(D1, LOW);
        delay(10);
        return analogRead(A0);
        break;
     default:
        digitalWrite(D0, LOW);
        digitalWrite(D1, HIGH);
        delay(10);
        return analogRead(A0);
        break;
  }
}
