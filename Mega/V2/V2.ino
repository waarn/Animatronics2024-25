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

int ServoPin6 = 34;
int ServoPin7 = 36;
int ServoPin8 = 38;
int ServoPin9 = 40;

int Servo1Mod = 0;
int Servo2Mod = 13;
int Servo3Mod = -1;
int Servo4Mod = 2;
int Servo5Mod = 0;

int Servo6Mod = 0;
int Servo7Mod = 0;
int Servo8Mod = 0;
int Servo9Mod = 0;

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;

Servo Servo6;
Servo Servo7;
Servo Servo8;
Servo Servo9;

int Video1 = 6;
int Video2 = 5;
int Video3 = 16;
int Video4 = 15;

int Relay1 = A0;
int Relay2 = A4;

int pos = 0;

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

  Servo6.attach(ServoPin6);
  Servo7.attach(ServoPin7);
  Servo8.attach(ServoPin8);
  Servo9.attach(ServoPin9);

  Servo1.write(90 + Servo1Mod);
  Servo2.write(90 + Servo2Mod);
  Servo3.write(90 + Servo3Mod);
  Servo4.write(90 + Servo4Mod);
  Servo5.write(90 + Servo5Mod);
  Servo6.write(90 + Servo6Mod);
  Servo7.write(90 + Servo7Mod);
  Servo8.write(90 + Servo8Mod);
  Servo9.write(90 + Servo9Mod);

  digitalWrite(Video1, HIGH);
  digitalWrite(Video2, HIGH);
  digitalWrite(Video3, HIGH);
  digitalWrite(Video4, HIGH);

  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);

  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  while (mySerial.available()) {
    delay(1);
    char c = mySerial.read();
    readString += c;
  }

  if (readString.length() > 0) {
    Serial.println(readString);

    if (readString == "9780060256654") {
	  digitalWrite(Video1, LOW);
      delay(500);
      digitalWrite(Video1, HIGH);
      delay(200);

      digitalWrite(Relay1, LOW);

 digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, LOW);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
      for (int i = 0; i <= 6; i++) {
        for (pos = 100; pos >= 70; pos -= 1) {
          Servo1.write(map(pos, 70, 100, 80, 100) + Servo1Mod);
          delay(15);
          Servo2.write(pos + Servo2Mod);
          delay(15);
          Servo3.write(pos + Servo3Mod);
          delay(15);
          Servo4.write(pos + Servo4Mod);
          delay(15);
          Servo5.write(pos + Servo5Mod);
          delay(15);
          Servo6.write(map(pos + Servo6Mod, 100,70,110,70));
          delay(15);
          Servo7.write(map(pos + Servo7Mod, 100,70,110,70));
          delay(15);
          Servo8.write(map(pos + Servo8Mod, 70,100,140,50));
          Servo9.write(map(pos + Servo9Mod, 70,100,140,50));
        }
        digitalWrite(Relay2, LOW);
        for (pos = 70; pos <= 100; pos += 1) {
          Servo1.write(map(pos, 70, 100, 80, 100) + Servo1Mod);
          delay(15);
          Servo2.write(pos + Servo2Mod);
          delay(15);
          Servo3.write(pos + Servo3Mod);
          delay(15);
          Servo4.write(pos + Servo4Mod);
          delay(15);
          Servo5.write(pos + Servo5Mod);
          delay(15);
          //Servo6.write(map(pos + Servo6Mod, 100,70,110,70));
          Servo6.write(map(pos + Servo6Mod, 100,70,70,110));
          delay(15);
          Servo7.write(map(pos + Servo7Mod, 100,70,110,70));
          delay(15);
          Servo8.write(map(pos + Servo8Mod, 70,100,140,50));
          Servo9.write(map(pos + Servo9Mod, 70,100,140,50));
        }
        digitalWrite(Relay2, HIGH);
      }
          delay(3500);
    
      Servo1.write(90 + Servo1Mod);
      Servo2.write(90 + Servo2Mod);
      Servo3.write(90 + Servo3Mod);
      Servo4.write(90 + Servo4Mod);
      Servo5.write(90 + Servo5Mod);
          Servo6.write(90 + Servo6Mod);
  Servo7.write(90 + Servo7Mod);
  Servo8.write(90 + Servo8Mod);
  Servo9.write(90 + Servo9Mod);

      digitalWrite(Relay1, HIGH);
      digitalWrite(Relay2, HIGH);

      digitalWrite(Sound1, LOW);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }


    if (readString == "051111407106") {
      digitalWrite(Video2, LOW);
      delay(500);
      digitalWrite(Video2, HIGH);
      delay(200);

      digitalWrite(Relay1, LOW);

      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, LOW);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
      for (int i = 0; i <= 6; i++) {
        for (pos = 100; pos >= 70; pos -= 1) {
          Servo1.write(map(pos, 70, 100, 80, 100) + Servo1Mod);
          delay(15);
          Servo2.write(pos + Servo2Mod);
          delay(15);
          Servo3.write(pos + Servo3Mod);
          delay(15);
          Servo4.write(pos + Servo4Mod);
          delay(15);
          Servo5.write(pos + Servo5Mod);
          delay(15);
          Servo6.write(map(pos + Servo6Mod, 100,70,110,70));
          delay(15);
          Servo7.write(map(pos + Servo7Mod, 100,70,110,70));
          delay(15);
          Servo8.write(map(pos + Servo8Mod, 70,100,140,50));
          Servo9.write(map(pos + Servo9Mod, 70,100,140,50));
        }
        digitalWrite(Relay2, LOW);
        for (pos = 70; pos <= 100; pos += 1) {
          Servo1.write(map(pos, 70, 100, 80, 100) + Servo1Mod);
          delay(15);
          Servo2.write(pos + Servo2Mod);
          delay(15);
          Servo3.write(pos + Servo3Mod);
          delay(15);
          Servo4.write(pos + Servo4Mod);
          delay(15);
          Servo5.write(pos + Servo5Mod);
          delay(15);
          //Servo6.write(map(pos + Servo6Mod, 100,70,110,70));
          Servo6.write(map(pos + Servo6Mod, 100,70,70,110));
          delay(15);
          Servo7.write(map(pos + Servo7Mod, 100,70,110,70));
          delay(15);
          Servo8.write(map(pos + Servo8Mod, 70,100,140,50));
          Servo9.write(map(pos + Servo9Mod, 70,100,140,50));
        }
        digitalWrite(Relay2, HIGH);
      }
          delay(3500);
    
      Servo1.write(90 + Servo1Mod);
      Servo2.write(90 + Servo2Mod);
      Servo3.write(90 + Servo3Mod);
      Servo4.write(90 + Servo4Mod);
      Servo5.write(90 + Servo5Mod);
          Servo6.write(90 + Servo6Mod);
  Servo7.write(90 + Servo7Mod);
  Servo8.write(90 + Servo8Mod);
  Servo9.write(90 + Servo9Mod);

      digitalWrite(Relay1, HIGH);
      digitalWrite(Relay2, HIGH);

      digitalWrite(Sound1, LOW);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }


 if (readString == "051111407107") {
      digitalWrite(Video3, LOW);
      delay(500);
      digitalWrite(Video3, HIGH);
      delay(200);

      digitalWrite(Relay1, LOW);

      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, LOW);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
      for (int i = 0; i <= 6; i++) {
        for (pos = 100; pos >= 70; pos -= 1) {
          Servo1.write(map(pos, 70, 100, 80, 100) + Servo1Mod);
          delay(15);
          Servo2.write(pos + Servo2Mod);
          delay(15);
          Servo3.write(pos + Servo3Mod);
          delay(15);
          Servo4.write(pos + Servo4Mod);
          delay(15);
          Servo5.write(pos + Servo5Mod);
          delay(15);
          Servo6.write(map(pos + Servo6Mod, 100,70,110,70));
          delay(15);
          Servo7.write(map(pos + Servo7Mod, 100,70,110,70));
          delay(15);
          Servo8.write(map(pos + Servo8Mod, 70,100,140,50));
          Servo9.write(map(pos + Servo9Mod, 70,100,140,50));
        }
        digitalWrite(Relay2, LOW);
        for (pos = 70; pos <= 100; pos += 1) {
          Servo1.write(map(pos, 70, 100, 80, 100) + Servo1Mod);
          delay(15);
          Servo2.write(pos + Servo2Mod);
          delay(15);
          Servo3.write(pos + Servo3Mod);
          delay(15);
          Servo4.write(pos + Servo4Mod);
          delay(15);
          Servo5.write(pos + Servo5Mod);
          delay(15);
          //Servo6.write(map(pos + Servo6Mod, 100,70,110,70));
          Servo6.write(map(pos + Servo6Mod, 100,70,70,110));
          delay(15);
          Servo7.write(map(pos + Servo7Mod, 100,70,110,70));
          delay(15);
          Servo8.write(map(pos + Servo8Mod, 70,100,140,50));
          Servo9.write(map(pos + Servo9Mod, 70,100,140,50));
        }
        digitalWrite(Relay2, HIGH);
      }
          delay(3500);
    
      Servo1.write(90 + Servo1Mod);
      Servo2.write(90 + Servo2Mod);
      Servo3.write(90 + Servo3Mod);
      Servo4.write(90 + Servo4Mod);
      Servo5.write(90 + Servo5Mod);
          Servo6.write(90 + Servo6Mod);
  Servo7.write(90 + Servo7Mod);
  Servo8.write(90 + Servo8Mod);
  Servo9.write(90 + Servo9Mod);

      digitalWrite(Relay1, HIGH);
      digitalWrite(Relay2, HIGH);

      digitalWrite(Sound1, LOW);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }








    if (readString == "9780394800134") {
      digitalWrite(Video3, LOW);
      delay(500);
      digitalWrite(Video3, HIGH);
      delay(200);

      digitalWrite(Relay1, LOW);

      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, LOW);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
      for (int i = 0; i <= 9; i++) {
        for (pos = 100; pos >= 70; pos -= 1) {
          Servo1.write(map(pos, 70, 100, 80, 100) + Servo1Mod);
          delay(15);
          Servo2.write(pos + Servo2Mod);
          delay(15);
          Servo3.write(pos + Servo3Mod);
          delay(15);
          Servo4.write(pos + Servo4Mod);
          delay(15);
          Servo5.write(pos + Servo5Mod);
          delay(15);
        }
        digitalWrite(Relay2, LOW);
        for (pos = 70; pos <= 100; pos += 1) {
          Servo1.write(map(pos, 70, 100, 80, 100) + Servo1Mod);
          delay(15);
          Servo2.write(pos + Servo2Mod);
          delay(15);
          Servo3.write(pos + Servo3Mod);
          delay(15);
          Servo4.write(pos + Servo4Mod);
          delay(15);
          Servo5.write(pos + Servo5Mod);
          delay(15);
        }
        digitalWrite(Relay2, HIGH);
      }
          delay(2750);
    
      Servo1.write(90 + Servo1Mod);
      Servo2.write(90 + Servo2Mod);
      Servo3.write(90 + Servo3Mod);
      Servo4.write(90 + Servo4Mod);
      Servo5.write(90 + Servo5Mod);

      digitalWrite(Relay1, HIGH);
      digitalWrite(Relay2, HIGH);

      digitalWrite(Sound1, LOW);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }


    if (readString == "051111407111") {
      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }
    if (readString == "051111407596") {
      digitalWrite(Sound1, LOW);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }
    if (readString == "051111407595") {
      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, LOW);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }
    if (readString == "051111407594") {
      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, LOW);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }
    if (readString == "051111407113") {
      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, LOW);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }
    if (readString == "051111407114") {
      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, LOW);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }
    if (readString == "051111407115") {
      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, LOW);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }
    if (readString == "051111407116") {
      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, LOW);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, HIGH);
    }
    if (readString == "051111407117") {
      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, LOW);
      digitalWrite(Sound9, HIGH);
    }
    if (readString == "051111407593") {
      digitalWrite(Sound1, HIGH);
      digitalWrite(Sound2, HIGH);
      digitalWrite(Sound3, HIGH);
      digitalWrite(Sound4, HIGH);
      digitalWrite(Sound5, HIGH);
      digitalWrite(Sound6, HIGH);
      digitalWrite(Sound7, HIGH);
      digitalWrite(Sound8, HIGH);
      digitalWrite(Sound9, LOW);
    }
    if (readString == "051111407108") {
      digitalWrite(Video1, LOW);
      delay(500);
      digitalWrite(Video1, HIGH);
      delay(200);
    }
    if (readString == "051111407109") {
      digitalWrite(Video2, LOW);
      delay(500);
      digitalWrite(Video2, HIGH);
      delay(200);
    }
    if (readString == "051111407112") {
      digitalWrite(Video3, LOW);
      delay(500);
      digitalWrite(Video3, HIGH);
      delay(200);
    }
    if (readString == "051111407103") {
      digitalWrite(Relay1, HIGH);
    }
    if (readString == "051111407102") {
      digitalWrite(Relay1, LOW);
    }
    if (readString == "051111407101") {
      digitalWrite(Relay2, HIGH);
    }
    if (readString == "051111407104") {
      digitalWrite(Relay2, LOW);
    }
    if (readString == "051111407105") {
      for (int i = 0; i <= 35; i++) {
        Servo1.write(80 + Servo1Mod);
        Servo2.write(80 + Servo2Mod);
        Servo3.write(80 + Servo3Mod);
        Servo4.write(80 + Servo4Mod);
        Servo5.write(80 + Servo5Mod);
        delay(500);
        Servo1.write(100 + Servo1Mod);
        Servo2.write(100 + Servo2Mod);
        Servo3.write(100 + Servo3Mod);
        Servo4.write(100 + Servo4Mod);
        Servo5.write(100 + Servo5Mod);
      }
    }/*
    if (readString == "051111407106") {
      int pos = 0;    // variable to store the servo position
      for (pos = 70; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
        Servo6.write(pos + Servo6Mod);
        Servo7.write(pos + Servo7Mod);
        Servo8.write(pos + Servo8Mod);
        Servo9.write(pos + Servo9Mod);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 110; pos >= 70; pos -= 1) { // goes from 180 degrees to 0 degrees
    Servo6.write(pos + Servo6Mod);
        Servo7.write(pos + Servo7Mod);
        Servo8.write(pos + Servo8Mod);
        Servo9.write(pos + Servo9Mod);             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 70; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
        Servo6.write(pos + Servo6Mod);
        Servo7.write(pos + Servo7Mod);
        Servo8.write(pos + Servo8Mod);
        Servo9.write(pos + Servo9Mod);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

        Servo6.write(90 + Servo6Mod);
  Servo7.write(90 + Servo7Mod);
  Servo8.write(90 + Servo8Mod);
  Servo9.write(90 + Servo9Mod);

        for (pos = 70; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
        Servo6.write(map(pos + Servo6Mod, 70,110,110,70));
        Servo7.write(pos + Servo7Mod);
        Servo8.write(pos + Servo8Mod);
        Servo9.write(pos + Servo9Mod);
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 110; pos >= 70; pos -= 1) { // goes from 180 degrees to 0 degrees
    Servo6.write(map(pos + Servo6Mod, 70,110,110,70));
        Servo7.write(pos + Servo7Mod);
        Servo8.write(pos + Servo8Mod);
        Servo9.write(pos + Servo9Mod);             // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 70; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
        Servo6.write(map(pos + Servo6Mod, 70,110,110,70));
        Servo7.write(pos + Servo7Mod);
        Servo8.write(pos + Servo8Mod);
        Servo9.write(pos + Servo9Mod);
    delay(15);                       // waits 15 ms for the servo to reach the position
    Servo6.write(90 + Servo6Mod);
  Servo7.write(90 + Servo7Mod);
  Servo8.write(90 + Servo8Mod);
  Servo9.write(90 + Servo9Mod);
  }
    }
    */
    readString = "";
  }
}