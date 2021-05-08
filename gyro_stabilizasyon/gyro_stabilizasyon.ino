#include <Wire.h>
#include <Servo.h>
#include <MPU6050.h>

MPU6050 mpu;
Servo ESC;
Servo ESC2;

const int motor1=11;
const int motor2=10;

void setup() 
{
  ESC.attach(11, 1500, 2000);
  ESC2.attach(10, 1000, 2000);
  
  Serial.begin(9600);
  
  Serial.println("Initialize MPU6050");

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }
}

void loop()
{
  // Read normalized values 
  Vector normAccel = mpu.readNormalizeAccel();

  // Calculate Pitch & Roll
  int pitch = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
  int roll = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;

  // Output
  Serial.print(" Pitch = ");
  Serial.print(pitch);
  Serial.print(" Roll = ");
  Serial.print(roll);
  
  

  int potsol=map(pitch, 0, -90, 0, 180);
 
  
  if(potsol<=88)
  {
    ESC.write(potsol);
  }

  if (potsol>=95)
  {
    ESC2.write(potsol);
  }
  

  
  Serial.println();
  delay(50);
}
