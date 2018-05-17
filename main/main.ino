#include "boutons.h"
#include <stdlib.h>
#include <time.h>

bouton melodiePredefinie[4]; // contient les boutonsMelodie prédefinis
bouton melodieSaisie[10]; //contient la saisie du joueur 
bouton melodieGenerer[10];//contient la mélodie générer par le system

void setup() {
  initMelodie();
  Serial.begin(9600);
}

void loop()
{
  activate(melodiePredefinie[0]);

}


void initMelodie(){ // Permet d'initialiser un tableau de note prédéfinis
  melodiePredefinie[0]=setBouton(2,75,12);
  melodiePredefinie[1]=setBouton(2,75,12);
  melodiePredefinie[2]=setBouton(2,75,12);
  melodiePredefinie[3]=setBouton(2,75,12);
}



void genereMelodie(){
  int a =rand()%(10-1)+1;
    
}




