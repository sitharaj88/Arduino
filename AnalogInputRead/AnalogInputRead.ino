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

// Define the analog pin for the input
const int ANALOG_PIN = A0;

// Setup function runs once when you press reset or power the board
void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}

// Loop function runs over and over again forever
void loop() {
  // Read the analog value from the defined pin
  int analogValue = analogRead(ANALOG_PIN);

  // Print the analog value to the serial monitor
  Serial.print("Analog Value: ");
  Serial.println(analogValue);

  // Wait for a short period before the next reading
  delay(500);
}
