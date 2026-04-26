#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <string.h>
#include <ctype.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(8,9); //  RX, TX

#define REPORTING_PERIOD_MS     1000

PulseOximeter pox;

int flag = 0;

String hbeat= ""; 
int a = 50;
 
float hr = 0;
float sp = 0;

char ch;
String data;
String wdata;
String data1 = "";
char cnct[10] = ",CONNECT";
String apiKey = "GIHMBCPZHK6SBZWC";
int tcount = 0;
int count = 0;

int dsize = data1.length();     // previous length of the String

uint32_t tsLastReport = 0;
 
void setup()
{
    Serial.begin(9600);
    
  pinMode(13,OUTPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
      
  mySerial.begin(115200);
  
    if (!pox.begin()) {
    Serial.println("FAILED");
    while (1);
}
  delay(1000);
  mySerial.println("AT+RST");
  delay(2000);

mySerial.println("AT+CWMODE=1");   // Set WiFi mode
delay(2000);

mySerial.println("AT+CWJAP=\"Bhumija_WiFi\",\"12345678\"");
delay(6000);

  digitalWrite(13,1);
  delay(700);
  digitalWrite(13,0);
  delay(700);
  digitalWrite(13,1);
  delay(700);
  digitalWrite(13,0);

}

void loop()
{
    pox.update();
    hr = pox.getHeartRate();
    sp = pox.getSpO2();
    
    Serial.print("Heart rate:");
    Serial.print(hr);
    Serial.print(" bpm / SpO2:");
    Serial.println(sp);

    if(sp > 90)
        digitalWrite(13,1);
    else
        digitalWrite(13,0);

    tcount++;

    if(tcount > 10)
    {
        tcount = 0;

        String getStr = "GET /update?api_key=" + apiKey;
        getStr += "&field1=" + String(hr);
        getStr += "&field2=" + String(sp);
        getStr += " HTTP/1.1\r\n";
        getStr += "Host: api.thingspeak.com\r\n";
        getStr += "Connection: close\r\n\r\n";

        mySerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
        delay(2000);

        String cmd = "AT+CIPSEND=";
        cmd += getStr.length();
        mySerial.println(cmd);
        delay(2000);

        mySerial.print(getStr);
        delay(2000);

        mySerial.println("AT+CIPCLOSE");

        delay(15000);

        tsLastReport = millis();
    }
}
  
  
  
