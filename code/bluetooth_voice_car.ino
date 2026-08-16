/*
  Bluetooth & Voice Controlled Car
  --------------------------------
  Hardware:
  - Arduino Nano
  - HC-05 Bluetooth Module
  - L298N Motor Driver
  - 4 x BO Gear Motors

  Commands:
  F -> Forward
  B -> Backward
  L -> Left
  R -> Right
  S -> Stop

  Communication:
  Smartphone -> HC-05 -> Arduino Nano (Hardware Serial)
*/

#define ENA 5
#define IN1 6
#define IN2 7

#define ENB 10
#define IN3 8
#define IN4 9

int motorSpeed = 200;

void setup() {
  // Motor driver pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // HC-05 connected to Arduino Nano hardware RX/TX
  Serial.begin(9600);

  stopCar();
}

void loop() {

  if (Serial.available() > 0) {

    char command = Serial.read();

    // Convert lowercase commands to uppercase
    if (command >= 'a' && command <= 'z') {
      command = command - 'a' + 'A';
    }

    switch (command) {

      case 'F':
        forward();
        break;

      case 'B':
        backward();
        break;

      case 'L':
        left();
        break;

      case 'R':
        right();
        break;

      case 'S':
        stopCar();
        break;
    }
  }
}

// Move forward
void forward() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Move backward
void backward() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Turn left
void left() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Turn right
void right() {

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Stop car
void stopCar() {

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
