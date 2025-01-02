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


  digitalWrite(Motor1_in1, LOW);
  digitalWrite(Motor1_in2, HIGH);

  digitalWrite(Motor2_in1, LOW);
  digitalWrite(Motor2_in2, HIGH);

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

void loop() {

  analogWrite(Motor1_EN, 200);  // Send PWM signal to L298N Enable pin
  analogWrite(Motor2_EN, 100);  // Send PWM signal to L298N Enable pin

  delay(5000);

 // analogWrite(Motor1_EN, 150);  // Send PWM signal to L298N Enable pin
  //analogWrite(Motor2_EN, 150);  // Send PWM signal to L298N Enable pin

  delay(5000);
}