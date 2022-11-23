#include <Arduino.h>

#define RXD2 16
#define TXD2 17

byte x;
const byte message[] = {0x05, 0x04, 0x00, 0x49, 0x00, 0x01, 0xE1, 0x98};
float millislast;
float sendinterval = 2000;


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
  millislast = millis();
}

void loop()
{
  //Serial.println("another loop");
if ((millis()-millislast)>sendinterval) {
  Serial2.write(message, sizeof message);
  millislast = millis();
  Serial.println("Message sent");
}


  //Serial.print(Serial2.available());
  while (Serial2.available() > 0)
  {
    x = Serial2.read();
    if (x <= 0x0F) Serial.print("0");
    Serial.print(x, HEX);
  }
//delay(500);
}