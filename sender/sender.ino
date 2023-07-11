#include <SPI.h>
#include <RFM12B.h>

#define RFM_CS_PIN 15

RFM12B rfm;

void setup() {
  Serial.begin(115200);
  SPI.begin();
  pinMode(RFM_CS_PIN, OUTPUT);
  rfm.Initialize(868.0, RFM_CS_PIN);
  rfm.Encrypt("0123456789abcdef");
}

void loop() {
  rfm.Send(2, (byte *)"Hello, World!", sizeof("Hello, World!"), RF12_868MHZ);
  delay(2000);
}
