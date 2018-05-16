#include "boutons.h"

bouton btn1;

void setup() {
  Serial.begin(9600);
  btn1 = setBouton(2,75,12);
  activate(btn1);
}

void loop()
{
    activate(btn1);
}


