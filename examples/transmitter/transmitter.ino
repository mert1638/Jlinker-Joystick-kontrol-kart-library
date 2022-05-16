#include <jlinker.h>
jlinker Joystick;
int transmitted[] = {0, 0, 0, 0, 0, 0};
RF24 Nrf24l01(9, 10); // CE, CSN
const byte address[][6] = {"00001", "00002"};

void setup() {
  Joystick.pinSet();
  Nrf24l01.begin();
  Nrf24l01.openWritingPipe(address[1]); // 00002
  Nrf24l01.openReadingPipe(1, address[0]); // 00001
  Nrf24l01.setPALevel(RF24_PA_MIN);
  Nrf24l01.stopListening();
  Serial.begin(9600);

}

void loop() {
  digitalWrite(User_LED, HIGH);
  Nrf24l01.stopListening();
  transmitted[0] = map(Joystick.POT_1(), 0, 1023, 180, 0);
  Serial.println(transmitted[0]);
  transmitted[1] = map(Joystick.POT_2(), 0, 1023, 180, 0);
  Serial.println(transmitted[1]);
  transmitted[2] = map(Joystick.joyRightY(), 0, 1023, 180, 0);
  Serial.println(transmitted[2]);
  transmitted[3] = map(Joystick.joyRightX(), 0, 1023, 180, 0);
  Serial.println(transmitted[3]);
  transmitted[4] = map(Joystick.joyLeftY(), 0, 1023, 180, 0);
  Serial.println(transmitted[4]);
  transmitted[5] = map(Joystick.joyLeftX(), 0, 1023, 180, 0);
  Serial.println(transmitted[5]);
  Nrf24l01.write(&transmitted, sizeof(transmitted));
  Nrf24l01.startListening();
  if (Nrf24l01.available())
    digitalWrite(User_LED, HIGH);
}
