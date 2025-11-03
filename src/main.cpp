/*
 * Author:      Philipp Jahn
 * Date:        20.10.2025
 * File:        main.cpp
 * Description: A program continuously reads whole numbers (integers) from the user. Input ends when the user enters
 *              the number 0. After that, the program should output the sum of all entered numbers.
 *              If 20 numbers have already been entered, the program should automatically terminate and display the
 *              warning "Maximum number of inputs reached" along with the sum.
 */

#include <Arduino.h>

#define MAX_COUNT 20    // avoid hard-coded numbers

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sum = 0;
  int count = 0;
  int number;

  Serial.println("\n==== Start new calculation ====");

  do {
    delay(1); // without delay flushing will not work properly - data might not have arrived completely
    while(Serial.available()) Serial.read(); // flush serial buffer

    Serial.print("Input number: ");

    while(!Serial.available()) {
      // wait for user input
    }

    number = Serial.parseInt();
    sum = sum + number;
    count++;

    if (count >= MAX_COUNT) {
      Serial.println("\nMaximum number of inputs reached!");
      break; // jump out of the while loop
    }
  } while(number != 0);


  Serial.print("Sum = ");
  Serial.println(sum);

  // wait before strating new calculation
  delay(2000);

}
