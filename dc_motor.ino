// Pin Definitions
const int enableA = 9;
const int Pin1 = 8;
const int Pin2 = 10;
const int enableB = 11;
const int Pin3 = 12;
const int Pin4 = 13;
const int trigPin = 2;   // Ultrasonic sensor 1 trig pin
const int echoPin = 3;   // Ultrasonic sensor 1 echo pin
const int trigPin2 = 4;  // Ultrasonic sensor 2 trig pin
const int echoPin2 = 5;  // Ultrasonic sensor 2 echo pin
const int trigPin3 = 6;
const int echoPin3 = 7;

// Variables
long duration;
int distance;
long duration2;
int distance2;
long duration3;
int distance3;

void setup() {
  // Set motor pins as output
  pinMode(enableA, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  
  // Set ultrasonic sensor 1 pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Set ultrasonic sensor 2 pins
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Set ultrasonic sensor 3 pins
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Move the DC motors forward
  moveForward();
  
  // Check distance from ultrasonic sensor 1
  distance = getDistance(trigPin, echoPin);
  
  // If obstacle detected within 20cm from sensor 1, stop the car
  if (distance <= 20) {
    stopCar();
    delay(1000); // Brief delay to stop the car completely
  }
  
  // Check distance from ultrasonic sensor 2
  distance2 = getDistance(trigPin2, echoPin2);
  
  // If obstacle detected within 20cm from sensor 2, stop the car
  if (distance2 <= 20) {
    stopCar();
    delay(1000); // Brief delay to stop the car completely
  } // Missing closing curly brace here
  
  // Check distance from ultrasonic sensor 3
  distance3 = getDistance(trigPin3, echoPin3);
  
  // If obstacle detected within 20cm from sensor 3, stop the car
  if (distance3 <= 20) {
    stopCar();
    delay(1000); // Brief delay to stop the car completely
  }
}

// Function to move the car forward
void moveForward() {
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, HIGH);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, HIGH);
  analogWrite(enableA, 200); // Adjust speed
  analogWrite(enableB, 200); // Adjust speed
}

// Function to stop the car
void stopCar() {
  digitalWrite(Pin1, LOW);
  digitalWrite(Pin2, LOW);
  digitalWrite(Pin3, LOW);
  digitalWrite(Pin4, LOW);
}

// Function to measure distance using ultrasonic sensor
int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  // Print distance for debugging (optional)
  Serial.print("Distance: ");
  Serial.println(distance);
  
  return distance;
}
