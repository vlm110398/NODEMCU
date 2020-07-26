void setup(){
	Serial.begin(9600);
}
void loop(){
	int potencia = analogRead(A0);
	Serial.println(potencia);
	Serial.println(potencia*5/1024);
	analogWrite(D0,potencia);
}