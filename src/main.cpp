/*
 * Author: Philipp Jahn
 * Date:   20.10.2025
 * File:   main.cpp
 * Description: Ein Programm liest fortlaufend ganze Zahlen ein. Die Eingabe endet, wenn der Nutzer die Zahl 0 eingibt. Danach soll die Summe aller eingegebenen Zahlen (ohne den abschließenden 0er) ausgegeben werden.
   Beende automatisch, wenn bereits 20 Zahlen eingegeben wurden, und gib eine Warnung "Maximale Anzahl erreicht" und die Summe aus.
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
    delay(1); // without delay flushing will not work properly
    while(Serial.available()) Serial.read(); // flush serial buffer

    Serial.print("Input number: ");

    while(!Serial.available()) {
      // wait for user input
    }

    number = Serial.parseInt();
    sum = sum + number;

    if (count >= MAX_COUNT) {
      Serial.println("\nMaximum of numbers reached!");
      break; // jump out of the loop
    }   
  } while(number != 0);


  Serial.print("Sum = ");
  Serial.println(sum);

  // wait before strating new calculation
  delay(2000);

}
