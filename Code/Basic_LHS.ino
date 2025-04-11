#include <SparkFun_TB6612.h>

#define enA 5
#define IN2 6
#define IN1 7
#define STBY 8
#define IN3 9
#define IN4 10
#define enB 11

#define PWM 190

#define FRONT A2
#define LEFT A5
#define RIGHT A0
#define FRONTLEFT A3
#define FRONTRIGHT A1

const int offsetA = 1;
const int offsetB = 1;

double l_speed;
double r_speed;

double Kp = 1.98;
double Ki = 0.76;
double Kd = 0.4;

double error = 0;
double prevError;
double integral;
double derivative;
double output;

Motor motor1 = Motor(IN1, IN2, enA, offsetA, STBY);
Motor motor2 = Motor(IN3, IN4, enB, offsetB, STBY);


void setup() {
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(FRONT, INPUT);
  pinMode(FRONTLEFT, INPUT);
  pinMode(FRONTRIGHT, INPUT);
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, HIGH);
}

void loop() {

  int ls = digitalRead(LEFT);
  int fls = digitalRead(FRONTLEFT);
  int fs = digitalRead(FRONT);
  int frs = digitalRead(FRONTRIGHT);
  int rs = digitalRead(RIGHT);

  Serial.print("LEFT: ");
  Serial.print(ls);
  Serial.print(",FRONTLEFT: ");
  Serial.print(fls);
  Serial.print(",FRONT: ");
  Serial.print(fs);
  Serial.print(",FRONTRIGHT: ");
  Serial.println(frs);
  Serial.print(",RIGHT: ");
  Serial.print(rs);

  if (fs == 1) {
    forward();
    if (rs == 1 && fs == 1) {
      forward();
      right();
      delay(20);
    }
    if (rs == 0 && frs == 0 && fs == 1 && ls == 1) {
      forward();
      left();
      delay(10);
      
    }
  }

  if (fs == 0) {
    if (ls == 1 && fs == 0 && frs == 0 ) {
      stop(200);
      turnleft();
      delay(190);
      stop(100);
       forward();
      delay(0);
    }
    if (fls == 0 && fs == 0 && frs == 0) {
      stop(150);
      uturn();
      delay(380);
      stop(230);
      // delay(300);
      forward();
      delay(0);
    }
  }

  prevError = error;
  integral += error;
  derivative = error - prevError;
  output = Kp * error + Ki * integral + Kd * derivative;
  l_speed = PWM - output;
  r_speed = PWM + output;
  l_speed = constrain(l_speed, 0, 255);
  r_speed = constrain(r_speed, 0, 255);
}

void forward() {
  motor1.drive(200);
  motor2.drive(200 - 7);
}

void left() {
  motor1.drive(l_speed - 50);
  motor2.drive(r_speed);
}

void right() {
 motor1.drive(220);
  motor2.drive(100);
  //left(motor1, motor2, 150);
}

void turnright() {
  motor1.drive(l_speed);
  motor2.drive(-r_speed);
}

void turnleft() {
  motor1.drive(-l_speed);
  motor2.drive(r_speed);
}

void uturn() {
  stop(200);
  delay(100);
  motor1.drive(-l_speed);
  motor2.drive(r_speed);
  delay(260);
}

void stop(int num) {
  //  motor1.drive(0);
  //  motor2.drive(0);
  motor1.standby();
  motor2.standby();
  delay(10);
}
