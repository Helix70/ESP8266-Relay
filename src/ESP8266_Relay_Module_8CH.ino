// REQUIRES the following Arduino libraries:
// - Lien vidéo: https://youtu.be/Q8P5yrs1a_w
// - Getting Started ESP8266 : https://youtu.be/QRnPRKbtEGU
// Find All "Great Projects" Videos : https://www.youtube.com/c/GreatProjects

#include <FS.h>
#include <LittleFS.h>
#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "index.h"
#include "credentials.h"   // put overrides for ssid, pass, ip, dns, gateway etc here

#define EEPROM_SIZE 9
ESP8266WebServer server(80);
int relay1 = 16, relay2 = 14, relay3 = 12, relay4 = 13;
int relay5 = 15, relay6 = 0, relay7 = 4, relay8 = 5;
int state1 = LOW, state2 = LOW, state3 = LOW, state4 = LOW;
int state5 = LOW, state6 = LOW, state7 = LOW, state8 = LOW;

#define DO_LATCH 1

IPAddress ip(192, 168, 97, 62);
IPAddress dns(192, 168, 97, 1);
IPAddress gateway(192, 168, 97, 1);
IPAddress gatewayap(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

// Master Branch -  Latching Relays

//***************************************************
// Create a credentials.h with the following defined
//const char *Apssid = "ESP8266-Relay-Ant-Protection";
//const char *Appassword = "3tawi-GP";
//char ssid[30] = "";
//char pass[30] = "";
//IPAddress ip(192, 168, 1, 62);
//IPAddress dns(192, 168, 1, 1);
//IPAddress gateway(192, 168, 1, 1);
//IPAddress gatewayap(192, 168, 4, 1);
//IPAddress subnet(255, 255, 255, 0);
//***************************************************

File myfile;
String text;
long savednum = 0, passnum = 0;

#define DELAY_MS 5
#define DELAYS_PER_SECOND (1000 / DELAY_MS)

#ifdef DO_LATCH
#define LATCH_TIMEOUT_SEC 10
#define LATCH_TIMEOUT_COUNT (LATCH_TIMEOUT_SEC * DELAYS_PER_SECOND)

int latchcounter3 = 0;
int latchcounter4 = 0;
#endif

void (*resetFunc)(void) = 0; // declare reset function at address 0

void getWifi()
{
  WiFi.config(ip, dns, gateway, subnet);
  int xc = 0;
  int attempts = 0;
  Serial.println("");
  Serial.println("");
  Serial.print("delaying start ");
  while (xc < 120)
  {
    Serial.print(".");
    delay(500);
    xc++;
  }
  Serial.println("*");
  
  while ((WiFi.status() != WL_CONNECTED) && (attempts <= 5))
  {
    WiFi.disconnect();
    WiFi.begin(ssid, pass);

    xc = 0;
    attempts++;
    Serial.print("attempt ");
    Serial.print(attempts);
    while ((WiFi.status() != WL_CONNECTED) && (xc < 60))
    {
      Serial.print(".");
      delay(500);
      xc++;
    }
    Serial.println("*");
  }

  Serial.println("");
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Status=WL_CONNECTED");
    Serial.print("CONNECTED To: ");
    Serial.println(ssid);
    Serial.print("IP Address: http://");
    Serial.println(WiFi.localIP().toString().c_str());
    WiFi.softAPdisconnect(true);
  }
  else
  {
    WiFi.disconnect();
    Serial.println("Status= NOT WL_CONNECTED");
    WiFi.softAPConfig(ip, gatewayap, subnet);
    WiFi.softAP(Apssid, Appassword);
    Serial.print("CONNECTED To: ");
    Serial.print(Apssid);
    Serial.print(" Password: ");
    Serial.println(Appassword);
    Serial.print("IP Address: http://");
    Serial.println(WiFi.softAPIP().toString().c_str());
  }
}

void handleRoot()
{
  String s = MAIN_page;             // Read HTML contents
  server.send(200, "text/html", s); // Send web page
}

void handleWifi()
{
  handleRoot();
  text = server.arg("usname");
  myfile = LittleFS.open("/Ssid.txt", "w");
  if (myfile)
  {
    myfile.print(text);
  }
  myfile.close();
  int len = text.length() + 1;
  text.toCharArray(ssid, len);
  text = server.arg("pssw");
  myfile = LittleFS.open("/Password.txt", "w");
  if (myfile)
  {
    myfile.print(text);
  }
  myfile.close();
  len = text.length() + 1;
  text.toCharArray(pass, len);
  getWifi();
}

#ifdef DO_LATCH
void setlatch_3()
{
  handleRoot();
  if ((latchcounter3 == 0) && (latchcounter4 == 0))
  {
    latchcounter3 = LATCH_TIMEOUT_COUNT;

    state3 = HIGH;
    digitalWrite(relay3, state3);
    EEPROM.write(3, state3);
    EEPROM.commit();
  }
}

void setlatch_4()
{
  handleRoot();
  if ((latchcounter3 == 0) && (latchcounter4 == 0))
  {
    latchcounter4 = LATCH_TIMEOUT_COUNT;

    state4 = HIGH;
    digitalWrite(relay4, state4);
    EEPROM.write(4, state4);
    EEPROM.commit();
  }
}

void clearlatch_3()
{
  handleRoot();

  state3 = LOW;

  digitalWrite(relay3, state3);
  EEPROM.write(3, state3);
  EEPROM.commit();
}

void clearlatch_4()
{
  handleRoot();

  state4 = LOW;

  digitalWrite(relay4, state4);
  EEPROM.write(4, state4);
  EEPROM.commit();
}
#endif

void handlestate1()
{
  handleRoot();
  state1 = !state1;
  digitalWrite(relay1, state1);
  EEPROM.write(1, state1);
  EEPROM.commit();
}

void handlestate2()
{
  handleRoot();
  state2 = !state2;
  digitalWrite(relay2, state2);
  EEPROM.write(2, state2);
  EEPROM.commit();
}

void handlestate3()
{
  handleRoot();
  state3 = !state3;
  digitalWrite(relay3, state3);
  EEPROM.write(3, state3);
  EEPROM.commit();
}

void handlestate4()
{
  handleRoot();
  state4 = !state4;
  digitalWrite(relay4, state4);
  EEPROM.write(4, state4);
  EEPROM.commit();
}

void handlestate5()
{
  handleRoot();
  state5 = !state5;
  digitalWrite(relay5, state5);
  EEPROM.write(5, state5);
  EEPROM.commit();
}

void handlestate6()
{
  handleRoot();
  state6 = !state6;
  digitalWrite(relay6, state6);
  EEPROM.write(6, state6);
  EEPROM.commit();
}

void handlestate7()
{
  handleRoot();
  state7 = !state7;
  digitalWrite(relay7, state7);
  EEPROM.write(7, state7);
  EEPROM.commit();
}

void handlestate8()
{
  handleRoot();
  state8 = !state8;
  digitalWrite(relay8, state8);
  EEPROM.write(8, state8);
  EEPROM.commit();
}

void handleallon()
{
  handleRoot();
  state1 = HIGH, state2 = HIGH;
  state3 = HIGH, state4 = HIGH;
  state7 = HIGH, state8 = HIGH;
  setrelaystate();
  EEPROM.write(1, state1);
  EEPROM.write(2, state2);
#ifndef DO_LATCH
  EEPROM.write(3, state3);
  EEPROM.write(4, state4);
#endif
  EEPROM.write(5, state5);
  EEPROM.write(6, state6);
  EEPROM.write(7, state7);
  EEPROM.write(8, state8);
  EEPROM.commit();
}

void handlealloff()
{
  handleRoot();
  state1 = LOW, state2 = LOW, state3 = LOW, state4 = LOW;
  state5 = LOW, state6 = LOW, state7 = LOW, state8 = LOW;
  setrelaystate();
  EEPROM.write(1, state1);
  EEPROM.write(2, state2);
  EEPROM.write(3, state3);
  EEPROM.write(4, state4);
  EEPROM.write(5, state5);
  EEPROM.write(6, state6);
  EEPROM.write(7, state7);
  EEPROM.write(8, state8);
  EEPROM.commit();
}

void handlestate()
{
  String content = "<?xml version = \"1.0\" ?>";
  content += "<inputs><analog>";
  content += state1;
  content += "</analog><analog>";
  content += state2;
  content += "</analog><analog>";
  content += state3;
  content += "</analog><analog>";
  content += state4;
  content += "</analog><analog>";
  content += state5;
  content += "</analog><analog>";
  content += state6;
  content += "</analog><analog>";
  content += state7;
  content += "</analog><analog>";
  content += state8;
  content += "</analog></inputs>";
  server.sendHeader("Cache-Control", "no-cache");
  server.send(200, "text/xml", content); // Send web page
}

void handleRestesp()
{
  handleRoot();
  delay(1000);
  resetFunc();
}

void getssid()
{
  myfile = LittleFS.open("/Ssid.txt", "r");
  if (!myfile)
  {
    return;
  }
  int nb = 0;
  while (myfile.available())
  {
    savednum = myfile.read();
    ssid[nb] = (char)savednum;
    nb += 1;
  }
  myfile.close();
}

void getpass()
{
  myfile = LittleFS.open("/Password.txt", "r");
  if (!myfile)
  {
    return;
  }
  int nb = 0;
  while (myfile.available())
  {
    savednum = myfile.read();
    pass[nb] = (char)savednum;
    nb += 1;
  }
  myfile.close();
}

void setup()
{
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  pinMode(relay5, OUTPUT);
  pinMode(relay6, OUTPUT);
  pinMode(relay7, OUTPUT);
  pinMode(relay8, OUTPUT);
  setrelaystate();

  Serial.begin(115200);
  EEPROM.begin(EEPROM_SIZE);
  LittleFS.begin();
  getssid();
  getpass();
  WiFi.mode(WIFI_STA);
  getWifi();
  server.on("/", handleRoot);
  server.on("/Mywifi", handleWifi);
  server.on("/LED1", handlestate1);
  server.on("/LED2", handlestate2);
#if DO_LATCH
  server.on("/LED3", setlatch_3);
  server.on("/LED4", setlatch_4);
#else
  server.on("/LED5", handlestate3);
  server.on("/LED6", handlestate4);
#endif
  server.on("/LED5", handlestate5);
  server.on("/LED6", handlestate6);
  server.on("/LED7", handlestate7);
  server.on("/LED8", handlestate8);
  server.on("/allon", handleallon);
  server.on("/alloff", handlealloff);
  server.on("/redstate", handlestate);
  server.on("/restesp", handleRestesp);
  server.begin();

  EEPROM.write(5, LOW);
  EEPROM.write(6, LOW);
  EEPROM.commit();

  getstate();
}

#ifdef DO_LATCH
void handleCounters(void)
{
  // check if the latch is active
  if (latchcounter3 > 0)
  {
    // decrement the count
    latchcounter3--;
    if (latchcounter3 == 0)
    {
      // if expired, reset the latched relays and update the relay states
      clearlatch_3();
    }
  }
  if (latchcounter4 > 0)
  {
    // decrement the count
    latchcounter4--;
    if (latchcounter4 == 0)
    {
      // if expired, reset the latched relays and update the relay states
      clearlatch_4();
    }
  }
}
#endif

void loop()
{
#if DO_LATCH
  handleCounters();
#endif
  server.handleClient();
  delay(DELAY_MS);
}

void setrelaystate()
{
  digitalWrite(relay1, state1);
  digitalWrite(relay2, state2);
  digitalWrite(relay3, state3);
  digitalWrite(relay4, state4);
  digitalWrite(relay5, state5);
  digitalWrite(relay6, state6);
  digitalWrite(relay7, state7);
  digitalWrite(relay8, state8);
}

void getstate()
{
  state1 = EEPROM.read(1);
  state2 = EEPROM.read(2);
  state3 = EEPROM.read(3);
  state4 = EEPROM.read(4);
  state5 = EEPROM.read(5);
  state6 = EEPROM.read(6);
  state7 = EEPROM.read(7);
  state8 = EEPROM.read(8);
  setrelaystate();
}
