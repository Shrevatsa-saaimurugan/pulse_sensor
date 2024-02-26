# pulse_sensor
This Arduino code reads data from a pulse sensor connected to an analog pin, calculates the heartbeats per minute (BPM), prints the sensor value and BPM to the serial monitor, and blinks an LED based on the calculated BPM.

Here's a breakdown of the code:

### 1. Pin Definitions:

```cpp
const int sensorPin = A0;  // Analog input pin for the sensor
const int ledPin = 13;     // Onboard LED pin
```

- **`sensorPin`:** Represents the analog pin to which the pulse sensor is connected.
- **`ledPin`:** Represents the digital pin connected to the onboard LED (pin 13).

### 2. Variables:

```cpp
int sensorValue = 0;  // Variable to store the sensor reading
int bpm = 0;          // Variable to store the calculated beats per minute
```

- **`sensorValue`:** Holds the analog reading from the pulse sensor.
- **`bpm`:** Stores the calculated beats per minute.

### 3. Setup Function:

```cpp
void setup() {
  Serial.begin(9600);    // Initialize serial communication
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
}
```

- **Serial Communication Setup:** Initializes serial communication at a baud rate of 9600.
- **LED Pin Configuration:** Sets the LED pin as an output.

### 4. Loop Function:

```cpp
void loop() {
  sensorValue = analogRead(sensorPin);  // Read the sensor value

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
  }

  // Delay for a short period
  delay(100);
}
```

- **Read Sensor Value:** Reads the analog value from the pulse sensor.
- **Calculate BPM:** Uses a simple formula to estimate beats per minute based on the sensor value. This assumes the sensor output is proportional to the time between heartbeats.
- **Serial Output:** Prints the sensor value and BPM to the serial monitor.
- **LED Blinking:** Blinks the onboard LED based on the calculated BPM. If BPM is above 60, it blinks for 1 second.
- **Delay:** Introduces a short delay of 100 milliseconds between iterations to avoid rapid reading.

### Note:

- Ensure that the pulse sensor is correctly connected to the analog pin (`sensorPin`).
- Adjustments might be needed based on the characteristics of your specific pulse sensor.

This code essentially creates a simple heart rate monitoring system using a pulse sensor and visual feedback through an LED.
