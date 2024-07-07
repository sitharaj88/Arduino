/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Created by Sitharaj Seenivasan on July 7, 2024
 */

// Include necessary libraries
#include <Arduino.h>

// Define the analog pin for the temperature sensor
const int TEMP_SENSOR_PIN = A0;

// Function to read temperature from the sensor
float readTemperature() {
  // Read the analog value from the sensor
  int analogValue = analogRead(TEMP_SENSOR_PIN);
  
  // Convert the analog value to voltage
  // The ADC (Analog to Digital Converter) on the Arduino has a 10-bit resolution,
  // meaning it can represent analog input values from 0 to 1023.
  // The reference voltage for the ADC is 5V (for most Arduino boards).
  // Therefore, the voltage corresponding to the analog value can be calculated as:
  // voltage = (analogValue / 1023.0) * 5.0;
  float voltage = analogValue * (5.0 / 1023.0);

  // Convert the voltage to temperature in Celsius
  // For the LM35 temperature sensor, the output voltage is linearly proportional
  // to the temperature in Celsius. The sensor outputs 10 millivolts (0.01 volts)
  // per degree Celsius. Hence, to convert the voltage to temperature, we use:
  // temperatureC = voltage / 0.01;
  // Simplifying this gives:
  // temperatureC = voltage * 100.0;
  float temperatureC = voltage * 100.0;

  // Return the calculated temperature in Celsius
  return temperatureC;
}

// Setup function runs once when you press reset or power the board
void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}

// Loop function runs over and over again forever
void loop() {
  // Read the temperature in Celsius
  float temperature = readTemperature();
  
  // Print the temperature to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");  // Indicate the unit is Celsius
  
  // Wait for a second before the next reading
  delay(1000);
}
