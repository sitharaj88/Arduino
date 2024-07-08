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
#include <LiquidCrystal.h>

// Define the keypad layout
const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', 'x'},
  {'1', '2', '3', '-'},
  {'ON/C', '0', '=', '+'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; // Connect to the column pinouts of the keypad

// Create the Keypad and LCD objects
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(12, 11, 10, A5, A4, A3); // Connect RS, EN, D4, D5, D6, D7 of the LCD to pins 12, 11, 10, A5, A4, A3 respectively

// Setup function runs once when you press reset or power the board
void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Print a welcome message to the LCD
  lcd.print("Enter Input:");
}

// Loop function runs over and over again forever
void loop() {
  // Get the key pressed from the keypad
  char key = keypad.getKey();

  // If a key is pressed, display it on the LCD
  if (key) {
    lcd.setCursor(0, 1); // Set cursor to start of second row
    lcd.print("You pressed: ");
    lcd.print(key);
    delay(1000); // Wait for 1 second before clearing the display
    lcd.clear();
    lcd.print("Enter Input:");
  }
}
