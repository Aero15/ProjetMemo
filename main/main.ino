#include "boutons.h"

bouton melodiePredefinie[4]; // contient les boutonsMelodie prédefinis
bouton melodieSaisie[10]; //contient la saisie du joueur 

void setup() {
    initMelodie();
    initTableau();
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
void initTableau()
{
    for(int i=0; i<10;i++)
    {
        melodieGenerer[i]=setBouton(0,0,0);//On initialise le tableau melodieGenerer avec des melodie vides
        melodieSaisie[i]=setBouton(0,0,0);//On initialise le tableau melodieSaisie avec des melodie vides
    }
}
}




