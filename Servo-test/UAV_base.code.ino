#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

//setting up pins and other params.

//servo motors:
int servoPin1 = 9;
int servoPin2 = 10;
int servoPin3 = 11;

//potentiometers:
int potentiometer1 = 0;
int potentiometer2 = 1;
int potentiometer3 = 2;

//creating objects:
Servo Servo1;
Servo Servo2;
Servo Servo3;

void setup() {
  Serial.begin(9600);
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
}

void loop() {
  int sensor_value1 = analogRead(potentiometer1);
  int mapped_sensor_value1 = map(sensor_value1, 0, 1023, 0, 180);

  int sensor_value2 = analogRead(potentiometer2);
  int mapped_sensor_value2 = map(sensor_value2, 0, 1023, 0, 180);

  int sensor_value3= analogRead(potentiometer3);
  int mapped_sensor_value3 = map(sensor_value3, 0, 1023, 0, 180);

  Serial.print("flop(1) at ");
  Serial.print(mapped_sensor_value1);
  Serial.println (" degrees");
  Serial.print("flop(2) at ");
  Serial.print(mapped_sensor_value2);
  Serial.println (" degrees");
  Serial.print("flop(3) at ");
  Serial.print(mapped_sensor_value3);
  Serial.println (" degrees");
  Serial.flush();
  
  Servo1.write(mapped_sensor_value1);
  Servo2.write(mapped_sensor_value2);
  Servo3.write(mapped_sensor_value3);

}

/*

author: Ahmet Yigit AYDENIZ

writing_purpose:

*Making the base code for DIY UAV
*Trying to make a some sort of serial-port interface
*Testing flops for the first flight

*/
