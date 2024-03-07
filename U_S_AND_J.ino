#include <Servo.h>

const int Y_pin = A0;    // Analog pin connected to Y output
const int servoPin = 7;  // Pin connected to the servo motor
int trigPin = 8;         // Trigger pin of the ultrasonic sensor
int echoPin = 9;         // Echo pin of the ultrasonic sensor
Servo myservo;          

void setup() {
  pinMode(Y_pin, INPUT);    
  pinMode(servoPin, OUTPUT);  
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);   
  myservo.attach(servoPin);   
  Serial.begin(9600);          
}

void loop() {
  int val = analogRead(Y_pin);               // Read the value from the analog pin
  int angle = map(val, 0, 1023, 180, 0);     // Reverse mapping for clockwise movement
  myservo.write(angle);                      // Set the servo position based on the mapped value
  delay(10);                                  // Delay for smooth moveme
  
  // Ultrasonic sensor logic and reading
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Send 10 microsecond pulse to trigger
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Read the echo pin, measure the pulse duration
  distance = duration * 0.034 / 2;    // Calculate distance based on the speed of sound (in cm)
  
  // Output the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100);  // delaying for one second
  
}
