#include <Servo.h>

// Pin configuration
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);  // Start at 0 degrees
}

void loop() {
  long duration;
  int distance;

  // Trigger the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control the servo based on distance
  if (distance > 0 && distance <= 10) {
    myServo.write(90);  // Rotate to 90 degrees
  } else {
    myServo.write(0);   // Return to 0 degrees
  }

  delay(500);  // Small delay for stability
}