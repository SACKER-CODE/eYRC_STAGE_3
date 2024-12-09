// Define pins for the first set
const int trigPin1 = 4; 
const int echoPin1 = 3;
const int buzzerPin1 = 2;
const int ledPin1 = 5;

// Define pins for the second set
const int trigPin2 = 8;
const int echoPin2 = 7;
const int buzzerPin2 = 6;
const int ledPin2 = 9;

// Define pins for the third set
const int trigPin3 = 12;
const int echoPin3 = 11;
const int buzzerPin3 = 10;
const int ledPin3 = 13;

// Variables for calculating distances
long duration1, duration2, duration3;
int distance1, distance2, distance3;

// Distance thresholds for each sensor
const int threshold1 = 15; // Threshold for sensor 1
const int threshold2 = 15; // Threshold for sensor 2
const int threshold3 = 15; // Threshold for sensor 3

void setup() {
  // Set pins as input/output for all sets
  pinMode(trigPin1, OUTPUT); pinMode(echoPin1, INPUT); pinMode(buzzerPin1, OUTPUT); pinMode(ledPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT); pinMode(echoPin2, INPUT); pinMode(buzzerPin2, OUTPUT); pinMode(ledPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT); pinMode(echoPin3, INPUT); pinMode(buzzerPin3, OUTPUT); pinMode(ledPin3, OUTPUT);

  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  // Measure distance for the first set
  distance1 = measureDistance(trigPin1, echoPin1);
  controlBuzzerAndLED(distance1, buzzerPin1, ledPin1, threshold1);

  // Measure distance for the second set
  distance2 = measureDistance(trigPin2, echoPin2);
  controlBuzzerAndLED(distance2, buzzerPin2, ledPin2, threshold2);

  // Measure distance for the third set
  distance3 = measureDistance(trigPin3, echoPin3);
  controlBuzzerAndLED(distance3, buzzerPin3, ledPin3, threshold3);

  // Debugging: Print distances to Serial Monitor
  Serial.print("Distance1: "); Serial.println(distance1);
  Serial.print("Distance2: "); Serial.println(distance2);
  Serial.print("Distance3: "); Serial.println(distance3);

  delay(50); // Small delay for stability
}

// Function to measure distance using an ultrasonic sensor
int measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  if (duration == 0) {
    return -1; // No valid reading
  }
  return duration * 0.034 / 2; // Convert to centimeters
}

// Function to control the buzzer and LED based on distance
void controlBuzzerAndLED(int distance, int buzzerPin, int ledPin, int threshold) {
  if (distance > 0 && distance < threshold) {
    digitalWrite(ledPin, HIGH);   // Turn on LED
    tone(buzzerPin, 2000);        // Play a tone at 1000 Hz
  } else {
    digitalWrite(ledPin, LOW);    // Turn off LED
    noTone(buzzerPin);            // Stop the tone
  }
}
