#include "boutons.h"
#include <time.h>

bouton melodiePredefinie[4]; // contient les boutonsMelodie prédefinis
bouton melodieSaisie[10]; //contient la saisie du joueur 
bouton melodieGenerer[10];//contient la melodie générer 

void setup() {
    initMelodie();
    initTableau();
    srand(time(NULL));
    Serial.begin(9600);
}

void loop()
{
  boolean btn1=digitalRead(melodiePredefinie[0].pinButton);
  Serial.println(btn1);
  if (btn1==1){activate(melodiePredefinie[0]);}
  

}

void initMelodie() // Charge les mélodies prédéfinies
{
    melodiePredefinie[0]=setBouton(9,10,300,9);
    melodiePredefinie[1]=setBouton(1,10,300,9);
    melodiePredefinie[2]=setBouton(4,10,300,9);
    melodiePredefinie[3]=setBouton(0,10,300,9);
}

void initTableau()
{
    for(int i=0; i<10;i++)
    {
        melodieGenerer[i]=setBouton(0,0,0,0);//On initialise le tableau melodieGenerer avec des melodie vides
        melodieSaisie[i]=setBouton(0,0,0,0);//On initialise le tableau melodieSaisie avec des melodie vides
    }
}

void genereMelodie()
{
    
    int a =rand()%4; 
    for (int i=0; i<10;i++)
    {
        if (melodieGenerer[i].pinLed==0)
        {
            melodieGenerer[i]=melodiePredefinie[a];
            return;
        }
    }
}




