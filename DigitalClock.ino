#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char *ssid = "ROMBU_TEST"; //Setting a username
const char *password = "1234567"; //Setting the password

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

String weekDays[7] = {"Sun" , "Mon" , "Tue" , "Wed" , "Thr" , "Fri" , "Sat"};
String months[12] = {"Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" , "Aug" , "Sept" , "Oct" , "Nov" , "Dec"};

const int ledPin = D10;
const int buzzerPin = D9;

const int activateHour = 10;
const int activateMinute = 38;
const int deactivateHour = 10;
const int deactivateMinute = 39;

char intro[] = "GIVE THIS VIDEO A LIKE, IF YOU ENJOYED!, | FROM SUDEEP";
int x, minX;

bool deviceActive = false;

void wifiConnect() {
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.clearDisplay();
  display.setCursor(0, 10);
  display.println("WiFi");
  display.setCursor(0, 30);
  display.println("Connecting");
  display.display();
