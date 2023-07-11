#include <SPI.h>
#include <RFM12B.h>

#define RFM_CS_PIN 15

RFM12B rfm;
const int DATA_MAX_LEN = 66; // Az adat maximális hossza (ezt kell beállítanod)


void setup() {
  Serial.begin(115200);
  SPI.begin();
  pinMode(RFM_CS_PIN, OUTPUT);
  rfm.Initialize(868.0, RFM_CS_PIN);
  rfm.Encrypt("0123456789abcdef");
}

void loop() {
  if (rfm.ReceiveComplete()) {
    if (rfm.DATAMAXLEN == sizeof("Hello, World!")) {
      char receivedData[rfm.DATAMAXLEN + 1];
      memcpy(receivedData, rfm.Data, rfm.DATAMAXLEN);
      receivedData[rfm.DATAMAXLEN] = '\0';
      Serial.print("Received: ");
      Serial.println(receivedData);
    }
    
    rfm.ReceiveStart();
  }
}
