#include <Arduino.h>

#define RXD2 16
#define TXD2 17

void setup()
{
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(9600);
  // Serial.begin(115200);

  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.println("Goodnight moon!");

  // Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  Serial2.println("serial2test");
  Serial.println("Serial Txd is on pin: " + String(TX));
  Serial.println("Serial Rxd is on pin: " + String(RX));
}

void loop()
{
  Serial2.print("######");
  Serial2.write("hellowrite");
  //Serial.print(Serial2.available());
  if (Serial2.available() > 0)
  {
    Serial.print(char(Serial2.read()));
  }
  delay(200);
}