/******************************************************************************
  TestRun.ino
  TB6612FNG H-Bridge Motor Driver Example code
  Michelle @ SparkFun Electronics
  8/20/16
  https://github.com/sparkfun/SparkFun_TB6612FNG_Arduino_Library

  Uses 2 motors to show examples of the functions in the library.  This causes
  a robot to do a little 'jig'.  Each movement has an equal and opposite movement
  so assuming your motors are balanced the bot should end up at the same place it
  started.

  Resources:
  TB6612 SparkFun Library

  Development environment specifics:
  Developed on Arduino 1.6.4
  Developed with ROB-9457
******************************************************************************/

// This is the library for the TB6612 that contains the class Motor and all the
// functions
#include <SparkFun_TB6612.h>

// Pins for all inputs, keep in mind the PWM defines must be on PWM pins
// the default pins listed are the ones used on the Redbot (ROB-12097) with
// the exception of STBY which the Redbot controls with a physical switch
#define enA 5
#define IN2 6
#define IN1 7
#define STBY 8
#define IN3 9
#define IN4 10
#define enB 11

// these constants are used to allow you to make your motor configuration
// line up with function names like forward.  Value can be 1 or -1
const int offsetA = 1;
const int offsetB = 1;

// Initializing motors.  The library will allow you to initialize as many
// motors as you have memory for.  If you are using functions like forward
// that take 2 motors as arguements you can either write new functions or
// call the function more than once.
Motor motor1 = Motor(IN1, IN2,  enA, offsetA, STBY);
Motor motor2 = Motor(IN3, IN4, enB, offsetB, STBY);

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
}


void loop()
{
  forward();
  delay(500);
  stop();
  delay(1000);
  turnright();
  delay(300);
  stop();
  delay(1000);
  turnleft();
  delay(300);
  stop();
  delay(1000);
}

void forward() {
  motor1.drive(100);
  motor2.drive(100-5);
}

void right() {
  motor1.drive(100);
  motor2.drive(100 - 50);
}

void left() {
  motor1.drive(100 - 80);
  motor2.drive(100);
}

void turnright() {
  motor1.drive(100);
  motor2.drive(-100 );
}

void turnleft() {
  motor1.drive(-100);
  motor2.drive(100);
}

void uturn() {
  motor1.drive(100);
  motor2.drive(-100);
}

void stop() {
  motor1.drive(0);
  motor2.drive(0);
}
