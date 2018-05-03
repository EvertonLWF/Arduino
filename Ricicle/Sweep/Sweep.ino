#include <Servo.h>
#include <HCSR04.h>
 UltraSonicDistanceSensor distanceSensor(13, 12);
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
float resultado=0;
void setup() {
 Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
}
void abertura(){
  for (pos = 10; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(3000);
  
  for (pos = 160; pos >= 10; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void loop() {
  myservo.write(0);
  Serial.println(distanceSensor.measureDistanceCm());
  resultado=(distanceSensor.measureDistanceCm());
  if(resultado>60&&resultado<70){
    abertura();
  }
  delay(100);
}

