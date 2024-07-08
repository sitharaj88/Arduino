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
#include <LiquidCrystal.h>

// Initialize the library by specifying the pins for the LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Setup function runs once when you press reset or power the board
void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Print a message to the LCD
  lcd.print("Hello, World!");
}

// Loop function runs over and over again forever
void loop() {
  // Set the cursor to column 0, line 1 (second row)
  lcd.setCursor(0, 1);
  
  // Print the text "Seconds: " followed by the number of seconds since reset
  lcd.print("Seconds: ");
  lcd.print(millis() / 1000);
  
  // Wait for a second before updating the display
  delay(1000);
}
