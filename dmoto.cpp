#include "dmoto.h"
void dmoto::pinSet(void)
{
  pinMode(m1Dir, OUTPUT);
  pinMode(m2Dir, OUTPUT);
  pinMode(m1En , OUTPUT);
  pinMode(m2En, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ldrRight, INPUT);
  pinMode(ldrLeft, INPUT);
  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);

}
float dmoto::distance(void)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return (duration / 2) / 29.1;

}

float dmoto::LdrRightValue(void)
{
  return analogRead(ldrRight);
}

float dmoto::LdrLeftValue(void)
{
  return analogRead(ldrLeft);
}


void dmoto::Forward(int pwm)
{
  digitalWrite(m1Dir, HIGH);
  analogWrite(m1En, pwm);
  digitalWrite(m2Dir, HIGH);
  analogWrite(m2En, pwm);


}

void dmoto::Backward(int pwm)
{
  digitalWrite(m1Dir, LOW);
  analogWrite(m1En, pwm);
  digitalWrite(m2Dir, LOW);
  analogWrite(m2En, pwm);

}

void dmoto::Stop(void)
{
  digitalWrite(m1Dir, LOW);
  analogWrite(m1En, 0);
  digitalWrite(m2Dir, LOW);
  analogWrite(m2En, 0);

}
void dmoto::Right(int pwm1,int pwm2)
{
  digitalWrite(m1Dir, HIGH);
  analogWrite(m1En, pwm1);
  digitalWrite(m2Dir, HIGH);
  analogWrite(m2En, pwm2);

}
void dmoto::Left(int pwm1,int pwm2)
{
  digitalWrite(m1Dir, HIGH);
  analogWrite(m1En, pwm1);
  digitalWrite(m2Dir, HIGH);
  analogWrite(m2En, pwm2);

}
void dmoto::BackRight(int pwm1,int pwm2)
{
  digitalWrite(m1Dir, LOW);
  analogWrite(m1En, pwm1);
  digitalWrite(m2Dir, LOW);
  analogWrite(m2En, pwm2);

}
void dmoto::BackLeft(int pwm1,int pwm2)
{
  digitalWrite(m1Dir, LOW);
  analogWrite(m1En, pwm1);
  digitalWrite(m2Dir, LOW);
  analogWrite(m2En, pwm2);

}


bool dmoto::sensor1(void)
{
  return digitalRead(Sensor1);
}
bool dmoto::sensor2(void)
{
  return digitalRead(Sensor2);
}
bool dmoto::sensor3(void)
{
  return digitalRead(Sensor3);
}



