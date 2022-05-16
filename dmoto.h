#ifndef dmoto_h
#define dmoto_h
#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>
#define m1Dir 2
#define m1En 5
#define m2Dir 7
#define m2En 6
#define echoPin 4
#define trigPin 8
#define ledPin A5
#define ldrRight A6
#define ldrLeft A7
#define buzzerPin 3
#define Sensor1 A0
#define Sensor2 A1
#define Sensor3 A2
#define Sensor4 A3
#define Sensor5 A4
#define nrfCE 9
#define nrfCSN 10
#define btStatePin 9
#define btEnablePin 10

class dmoto
{
  public:
    void pinSet(void);
    void Forward(int);
    float distance(void);
    void Backward(int);
    void Right(int, int);
    void Left(int, int);
    void BackRight(int, int);
    void BackLeft(int, int);
    void Stop(void);
    float LdrRightValue(void);
    float LdrLeftValue(void);
    bool sensor1(void);
    bool sensor2(void);
    bool sensor3(void);
  private:
};
#endif


