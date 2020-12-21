#include <DHT.h>
#include <DHT_U.h>
DHT dht(A2,11); // Creats a DHT object
int nRainIn = A3;
int nRainDigitalIn = A4;
int nRainVal;
boolean bIsRaining = false;
String strRaining;
const int sensor_pin = A0;
void setup() {
 // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(2,INPUT);
 dht.begin();

}
void loop() {
 delay(2000);
 // Reading temperature or humidity takes about 250 milliseconds!
 // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
 float h = dht.readHumidity();
 // Read temperature as Celsius (the default)
 float t = dht.readTemperature();
 // Read temperature as Fahrenheit (isFahrenheit = true)
 float f = dht.readTemperature(true);
 // Check if any reads failed and exit early (to try again).
 if (isnan(h) || isnan(t) || isnan(f)) {
 Serial.println(F("FailedtoreadfromDHTsensor!"));
 return;
 }
 // Compute heat index in Fahrenheit (the default)
 float hif = dht.computeHeatIndex(f, h);
 // Compute heat index in Celsius (isFahreheit = false)
 float hic = dht.computeHeatIndex(t, h, false);
 Serial.print(F("Humidity:"));
 Serial.print(h);
 Serial.print(F("%Temperature:"));
 Serial.print(t);
 Serial.print(F("°C"));
 Serial.print(f);
 Serial.print(F("°FHeatindex:"));
 Serial.print(hic);
 Serial.print(F("°C"));
 Serial.print(hif);
 Serial.print(F("°F"));
 nRainVal = analogRead(nRainIn);
 bIsRaining = !(digitalRead(nRainDigitalIn));

 if(bIsRaining){
 strRaining = "YES";
 }
 else{
 strRaining = "NO";
 }

 Serial.print("Raining?:");
 Serial.print(strRaining);
 Serial.print("MoistureLevel:");
 Serial.print(nRainVal);
 float moisture_percentage;
 int sensor_analog;
 sensor_analog = analogRead(sensor_pin);
 moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
 Serial.print("MoisturePercentage=");
 Serial.print(moisture_percentage);
}
