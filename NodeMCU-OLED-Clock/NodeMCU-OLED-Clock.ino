#include <ESP8266WiFi.h>
#include <time.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(115200);

  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.println("Wifi connecting to ");
  display.println( ssid );

  WiFi.begin(ssid, password);

  display.println("\nConnecting");

  display.display();

  while ( WiFi.status() != WL_CONNECTED ) {
    delay(500);
    display.print(".");
    display.display();
  }


  // Clear the buffer.
  display.clearDisplay();
  display.display();
  display.setCursor(0, 0);

  display.println("Wifi Connected!");
  display.print("IP:");
  display.println(WiFi.localIP() );
  display.display(); //
  delay(500);

  configTime(timezone, dst, "pool.ntp.org", "time.nist.gov" );
  //configTime(0, 0, "lk.pool.ntp.org");
  display.println("\nWaiting for NTP...");

  while (!time(nullptr)) {
    Serial.print("*");

    delay(1000);
  }
  display.println("\nTime response....OK");
  display.display();
  delay(1000);

  display.clearDisplay();
  display.display();



}

void loop()
{

}
