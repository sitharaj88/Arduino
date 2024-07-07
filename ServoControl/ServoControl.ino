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
#include <Servo.h>

// Define the pin for the servo motor
const int SERVO_PIN = 9;

// Create a Servo object
Servo myServo;

// Setup function runs once when you press reset or power the board
void setup() {
  // Attach the Servo object to the defined pin
  myServo.attach(SERVO_PIN);
}

// Loop function runs over and over again forever
void loop() {
  // Move the servo to 0 degrees
  myServo.write(0);
  delay(1000);  // Wait for a second

  // Move the servo to 90 degrees
  myServo.write(90);
  delay(1000);  // Wait for a second

  // Move the servo to 180 degrees
  myServo.write(180);
  delay(1000);  // Wait for a second
}
