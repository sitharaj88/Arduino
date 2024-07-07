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

// Define pins for the button and LED
const int BUTTON_PIN = 2;
const int LED_PIN = 13;

// Variable to store the state of the button
int buttonState = 0;

// Setup function runs once when you press reset or power the board
void setup() {
  // Initialize the button pin as an input
  pinMode(BUTTON_PIN, INPUT);
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
}

// Loop function runs over and over again forever
void loop() {
  // Read the state of the button
  buttonState = digitalRead(BUTTON_PIN);

  // Check if the button is pressed
  if (buttonState == HIGH) {
    // Turn the LED on
    digitalWrite(LED_PIN, HIGH);
  } else {
    // Turn the LED off
    digitalWrite(LED_PIN, LOW);
  }
}
