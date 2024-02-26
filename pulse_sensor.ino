// Pin Definitions
const int sensorPin = A0;  // Analog input pin for the sensor
const int ledPin = 13;      // Onboard LED pin
 
// Variablesv
int sensorValue = 0;        // Variable to store the sensor reading
int bpm = 0;                // Variable to store the calculated beats per minute
 
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}
 
void loop() {
  // Read the sensor value
  sensorValue = analogRead(sensorPin);
 
  // Calculate the beats per minute
  bpm = 60000 / (sensorValue * 2);  // Assumes sensor output is proportional to time between heartbeats
 
  // Print the sensor value and BPM to the serial monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("\tBPM: ");
  Serial.println(bpm);
 
  // Blink the LED based on the BPM
  if (bpm > 60) {
    digitalWrite(ledPin, HIGH);
    delay(1000);  // Blink for 1 second
    digitalWrite(ledPin, LOW);
  } else {
   
  }
 
  // Delay for a short period
  delay(100);
}
 
