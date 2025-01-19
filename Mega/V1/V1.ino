#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial mySerial(52, 50);  // RX, TX
String readString;

int Motor1_EN = 13;
int Motor1_in1 = 12;
int Motor1_in2 = 11;

int Motor2_EN = 10;
int Motor2_in1 = 9;
int Motor2_in2 = 8;

int Sound1 = 35;
int Sound2 = 37;
int Sound3 = 39;
int Sound4 = 41;
int Sound5 = 43;
int Sound6 = 45;
int Sound7 = 47;
int Sound8 = 49;
int Sound9 = 51;

int ServoPin1 = 28;
int ServoPin2 = 18;
int ServoPin3 = 19;
int ServoPin4 = 20;
int ServoPin5 = 21;

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;

int Video1 = 6;
int Video2 = 5;
int Video3 = 16;
int Video4 = 15;

int Relay1 = A0;
int Relay2 = A4;

void setup() {
  pinMode(Motor1_EN, OUTPUT);
  pinMode(Motor1_in1, OUTPUT);
  pinMode(Motor1_in2, OUTPUT);

  pinMode(Motor2_EN, OUTPUT);
  pinMode(Motor2_in1, OUTPUT);
  pinMode(Motor2_in2, OUTPUT);

  pinMode(Sound1, OUTPUT);
  pinMode(Sound2, OUTPUT);
  pinMode(Sound3, OUTPUT);
  pinMode(Sound4, OUTPUT);
  pinMode(Sound5, OUTPUT);
  pinMode(Sound6, OUTPUT);
  pinMode(Sound7, OUTPUT);
  pinMode(Sound8, OUTPUT);
  pinMode(Sound9, OUTPUT);

  pinMode(Video1, OUTPUT);
  pinMode(Video2, OUTPUT);
  pinMode(Video3, OUTPUT);
  pinMode(Video4, OUTPUT);

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);

  digitalWrite(Motor1_in1, LOW);
  digitalWrite(Motor1_in2, HIGH);

  digitalWrite(Motor2_in1, LOW);
  digitalWrite(Motor2_in2, HIGH);
  analogWrite(Motor1_EN, 200);
  analogWrite(Motor2_EN, 100);

  digitalWrite(Sound1, LOW);
  digitalWrite(Sound2, HIGH);
  digitalWrite(Sound3, HIGH);
  digitalWrite(Sound4, HIGH);
  digitalWrite(Sound5, HIGH);
  digitalWrite(Sound6, HIGH);
  digitalWrite(Sound7, HIGH);
  digitalWrite(Sound8, HIGH);
  digitalWrite(Sound9, HIGH);

  Servo1.attach(ServoPin1);
  Servo2.attach(ServoPin2);
  Servo3.attach(ServoPin3);
  Servo4.attach(ServoPin4);
  Servo5.attach(ServoPin5);

  digitalWrite(Video1, HIGH);
  digitalWrite(Video2, HIGH);
  digitalWrite(Video3, HIGH);
  digitalWrite(Video4, HIGH);

  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);

  mySerial.begin(9600);
}

void loop() {
  while (mySerial.available()) {
    delay(1);
    char c = mySerial.read();
    readString += c;
  }

  if (readString.length() > 0) {
    Serial.println(readString);

    if (readString == "9781419739033") {
      digitalWrite(Relay1, LOW);
      digitalWrite(Relay2, HIGH);
    }
    if (readString == "9780142410318") {
      digitalWrite(Relay1, HIGH);
      digitalWrite(Relay2, LOW);
    }
    if (readString == "051111407592") {
      digitalWrite(Video1, LOW);
      delay(500);
      digitalWrite(Video1, HIGH);
    }


    readString = "";
  }
  Servo1.write(map(analogRead(A1), 0, 1023, 0, 180));
  Servo2.write(map(analogRead(A1), 0, 1023, 0, 180));
  Servo3.write(map(analogRead(A1), 0, 1023, 0, 180));
  Servo4.write(map(analogRead(A1), 0, 1023, 0, 180));
  Servo5.write(map(analogRead(A1), 0, 1023, 0, 180));
  delay(15);
}