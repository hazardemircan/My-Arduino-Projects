

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 500
#define SERVOMAX 2400

void setup()
{
  Serial.begin(9600);

  pwm.begin();
  pwm.setPWMFreq(50);
  delay(20);
}
int counter=SERVOMAX;

void loop()
{
    

    counter-=10;

//    pwm.setPWM(0, 500, puls);
    pwm.writeMicroseconds(0,counter);
    Serial.println(counter);

    delay(300);
   
    if(counter<1500)
    {
      counter=0;
    }
  


}
