#pragma once

const char *Apssid = "ESP8266-Relay-Ant-Protection";
const char *Appassword = "3tawi-GP";

char ssid[] = "";
char pass[] = "";

IPAddress ip(192, 168, 1, 62);
IPAddress dns(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress gatewayap(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
