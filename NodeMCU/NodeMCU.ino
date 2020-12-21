#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>
#include <ESP8266HTTPClient.h>
// Basic Bluetooth sketch HC-05_02
// Connect the HC-05 module and communicate using the serial monitor
//
// The HC-05 defaults to commincation mode when first powered on.
// The default baud rate for communication mode is 9600
//
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
//
String c = "";
void setup()
{
 Serial.begin(9600);
 Serial.println("Arduino is ready");

 WiFi.begin("ep0wer","power1111"); // add ssid and password here
 while(WiFi.status() !=WL_CONNECTED)
 {
 delay(500);
 Serial.println("Waiting for connection");
 }

 Serial.println("Connected...");
 delay(1000);
 if (WiFi.status() ==WL_CONNECTED)
 {
 Serial.println("Wi-Fi Connected!");
 }
}
void loop()
{
 // Keep reading from HC-05 and send to Arduino Serial Monitor
 while(Serial.available()) {
 c= Serial.readString();// read the incoming data as string
 delay(2000);
 sendmessage(c);
 delay(1000);

 }
}
int sendmessage(String d)
{
 int sres;
 int net;
 if (WiFi.status()==WL_CONNECTED)
 {
 HTTPClient http;
 String url="http://bracuweatherstation.tk/post-data.php?data="+d;
 http.begin(url);
 http.addHeader("Content-Type","text/plain");
 int httpCode=http.GET();
 Serial.println("Data send");
 }
 else
 {
 Serial.println("Internet Problem!");
 }
 return 1;
}
