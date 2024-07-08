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
#include <Keypad.h>
#include <Wire.h>
#include "DFRobot_RGBLCD1602.h"

// Define RGB color values for the LCD backlight
const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

// Define the keypad layout
const byte ROWS = 4;  // Four rows
const byte COLS = 4;  // Four columns
char keys[ROWS][COLS] = {
  { '7', '8', '9', '/' },
  { '4', '5', '6', 'X' },
  { '1', '2', '3', '-' },
  { 'ON/C', '0', '=', '+' }
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };  // Connect to the row pinouts of the keypad
byte colPins[COLS] = { 5, 4, 3, 2 };  // Connect to the column pinouts of the keypad

// Create the Keypad and I2C LCD objects
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
DFRobot_RGBLCD1602 lcd(16, 2);  // Create an LCD object with 16 columns and 2 rows

// Setup function runs once when you press reset or power the board
void setup() {
  // Initialize the I2C LCD
  lcd.init();
  // Set the LCD backlight color
  lcd.setRGB(colorR, colorG, colorB);

  // Print a welcome message to the LCD
  lcd.print("Enter Input:");
}

// Loop function runs over and over again forever
void loop() {
  // Get the key pressed from the keypad
  char key = keypad.getKey();

  // If a key is pressed, display it on the LCD
  if (key) {
    lcd.clear();          // Clear the display before showing new input
    lcd.setCursor(0, 1);  // Set cursor to start of second row
    lcd.print("You pressed: ");
    lcd.print(key);  // Display the pressed key
    delay(1000);     // Wait for 1 second before clearing the display
    lcd.clear();
    lcd.print("Enter Input:");
  }
}
