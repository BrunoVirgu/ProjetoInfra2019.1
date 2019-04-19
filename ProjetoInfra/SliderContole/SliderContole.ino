/*********************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *********************

  This sketch shows how to read values from Virtual Pins

  App project setup:
    Slider widget (0...100) on Virtual Pin V1
 *********************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <jled.h>
//#include <Adafruit_NeoPixel.h>


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "d8fdf6707c3b44b7bcb9c9784d09e106";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "VIVO-C7F9";
char pass[] = "2F8A37C7F9";

JLed led = JLed(D4);


// This function will be called every time Slider Widget
// in Blynk app writes values to the Virtual Pin V1

BLYNK_WRITE(V0)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  led.Breathe(2000).Forever();
}


BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  int forcaBrilho = (pinValue - 1023)* -1;
  analogWrite(D4, forcaBrilho);
  
}

void setup()
{
  // Debug console
  //pinMode(D4, OUTPUT);
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  led.Update();
  Blynk.run();
}
