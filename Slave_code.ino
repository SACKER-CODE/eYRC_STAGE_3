// defines pins numbers
const int trigPin = 4;
const int echoPin = 3;
const int buzzerPin = 2;  // Buzzer connected to pin 3
const int ledPin = 5;     // LED connected to pin 2

// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT);   // Sets the ledPin as an Output
  Serial.begin(9600);        // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound is 0.034 cm/µs
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Check if the distance is <= 15 cm
  if (distance <= 15) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    tone(buzzerPin, 2000);       // Play a tone at 1000 Hz
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED
    noTone(buzzerPin);           // Stop the tone
  }
  
  delay(100); // Wait for a short duration before the next measurement
}