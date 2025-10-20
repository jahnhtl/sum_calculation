/*
 * Author: Philipp Jahn
 * Date:   20.10.2025
 * File:   main.cpp
 * Description: Ein Programm liest fortlaufend ganze Zahlen ein. Die Eingabe endet, wenn der Nutzer die Zahl 0 eingibt. Danach soll die Summe aller eingegebenen Zahlen (ohne den abschließenden 0er) ausgegeben werden.
   Beende automatisch, wenn bereits 20 Zahlen eingegeben wurden, und gib eine Warnung "Maximale Anzahl erreicht" und die Summe aus.
*/

#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int summe = 0;
  int anzahl;
  int zahl = 1; // set to 1 to avoid loop break during initial iteration

  for(anzahl = 0; anzahl <= 20 || zahl == 0; anzahl++)
  {
    Serial.print("Zahl eingeben: ");
    zahl = Serial.parseInt();
    summe = summe + zahl;
  }

  if (anzahl >= 20)
  {
    Serial.println("Maximal erreicht!");
  }   

  Serial.print("Summe = ");
  Serial.println(summe);

}
