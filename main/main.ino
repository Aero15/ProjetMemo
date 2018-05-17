#include "boutons.h"

bouton melodiePredefinie[4]; // contient les boutonsMelodie prédefinis
bouton melodieSaisie[10]; //contient la saisie du joueur 

void setup() {
    initMelodie();
    Serial.begin(9600);
}

void loop()
{
    activate(melodiePredefinie[0]);
}

void initMelodie() // Charge les mélodies prédéfinies
{
    melodiePredefinie[0]=setBouton(2,75,12);
    melodiePredefinie[1]=setBouton(2,75,12);
    melodiePredefinie[2]=setBouton(2,75,12);
    melodiePredefinie[3]=setBouton(2,75,12);
}




