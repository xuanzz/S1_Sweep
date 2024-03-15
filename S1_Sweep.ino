#include <Servo.h>
int minVal = 70;
int maxVal = 110;
Servo motor1;  // create servo object to control a servo
int pos = 0;   // variable to store the servo position

void setup() {
  Serial.begin(115200);
  motor1.attach(2);  // attaches the motor
  motor1.write(90);
  delay(2000);
  for (pos = 90; pos >= minVal; pos -= 1) {  // goes from 180 degrees to 0 degrees
    motor1.write(pos);                       // tell servo to go to position in variable 'pos'
    delay(100);                              // waits 15 ms for the servo to reach the position
  }
}



void loop() {
  for (pos = minVal; pos <= maxVal; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    motor1.write(pos);  // tell servo to go to position in variable 'pos'
    delay(100);         // waits 15 ms for the servo to reach the position
    Serial.println(pos);
  }
  for (pos = maxVal; pos >= minVal; pos -= 1) {  // goes from 180 degrees to 0 degrees
    motor1.write(pos);                           // tell servo to go to position in variable 'pos'
    delay(100);                                  // waits 15 ms for the servo to reach the position
    Serial.println(pos);
  }
}
