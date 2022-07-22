#include <TinyGPS++.h>

#define BaudRate 115200

TinyGPSPlus gps;

void setup() {
  Serial1.begin(BaudRate);

  Serial1.println("Started sending...");
}

void loop() {
  while(Serial1.available() > 0){
    char dat = Serial1.read();
    gps.encode(c);
    Serial1.print(gps.location.lat(), 6);
    Serial1.println(gps.location.lng(), 6);
  }

  delay(1000);
}
