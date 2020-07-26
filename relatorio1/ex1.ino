float volts;
ADC_MODE(ADC_VCC);
void setup(){
	Serial.begin(9600);
}
void loop(){
	volts = ESP.getVcc();
	Serial.print("Valor Bruto: ");
	Serial.println(volts);
	Serial.print("Valor Convertido: ");
	Serial.println(volts/1024);
	delay(1000);

}