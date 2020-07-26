void setup(){
	Serial.begin(9600);
}
void loop(){
	int potencia = analogRead(15);
	Serial.println(potencia);
	Serial.println(potencia*5/1024);
}