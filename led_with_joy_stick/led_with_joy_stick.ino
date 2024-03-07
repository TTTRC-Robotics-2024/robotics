int mid = 10;
int z1 = 0;
int z2 = 0;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  z1 = analogRead(A0);
  z2 = analogRead(A1);
}

void loop() {
  int xAxis = analogRead(A0); // Read Joystick's X-axis
  int yAxis = analogRead(A1); // Read Joystick's Y-axis

  // Y-axis used for forward and backward control
  if (yAxis < z2 - mid) {
    digitalWrite(4, HIGH); // Forward
    digitalWrite(5, LOW);
  } else if (yAxis > z2 + mid) {
    digitalWrite(4, LOW); // Backward
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(4, LOW); // Stop
    digitalWrite(5, LOW);
  }

  // X-axis used for left and right control
  if (xAxis < z1 - mid) {
    digitalWrite(6, HIGH); // Left
    digitalWrite(7, LOW);
  } else if (xAxis > z1 + mid) {
    digitalWrite(6, LOW); // Right
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(6, LOW); // Stop
    digitalWrite(7, LOW);
  }
}
