#include <dmoto.h>
#include <Servo.h>
RF24 Nrf(9, 10);
dmoto Rodeo;
const byte addresses[][6] = {"00001", "00002"};
int received[6] = {};
Servo servo1;
Servo servo2;

void setup() {
  Rodeo.pinSet();
  Nrf.begin();
  Nrf.openWritingPipe(addresses[0]); // 00001
  Nrf.openReadingPipe(1, addresses[1]); // 00002
  Nrf.setPALevel(RF24_PA_MIN);
  Nrf.startListening();
  digitalWrite(ledPin, LOW);
  Rodeo.Stop();
  servo1.attach(8);
  servo2.attach(4);
  Serial.begin(9600);

}

void loop() {
  Nrf.startListening();
  digitalWrite(ledPin, LOW);
  if (Nrf.available())
  {
    digitalWrite(ledPin, HIGH);
    Nrf.read(&received, sizeof(received));
    //Beep();
  }
  Serial.println(received[0]);
  Serial.println(received[1]);
  Serial.println(received[2]);
  Serial.println(received[3]);
  Serial.println(received[4]);
  Serial.println(received[5]);
  servo2.write(received[4]);
  servo1.write(received[5]);

    if (received[0] == 0 && received[1] == 0 && received[2] == 0 && received[3] == 0 && received[4] == 0 && received[5] == 0 && received[6] == 0 )
  {
    Rodeo.Stop();
  }
  delay(5);

}
