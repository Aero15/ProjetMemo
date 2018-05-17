#include "boutons.h"
#include <time.h>

#define STATE1 0
#define STATE2 1
#define STATE3 2
#define STATE4 3

int state, nextState;

bouton melodiePredefinie[4]; // Contient les Boutons/Led/Frequences prédefinis
bouton melodieGenerer[10];   // Contient les B/L/F à saisir
bouton melodieSaisie[10];    // Contient la saisie des B/L/F du joueur 

void setup()
{
    Serial.begin(9600);
    srand(time(NULL));
    
    initMelodies(); // Charge les mélodies prédéfinies

    state = STATE1; // Passe à l'état 1
}

void loop()
{
    switch(state)
    {
        case STATE1:
            reset();
            nextState = STATE2;
            break;
        case STATE2:
            genererMelodie();
            nextState = STATE3;
            break;
        case STATE3:
            ecouteSaisie();
            nextState = STATE4;
            break;
        case STATE4:
            if (verification()) nextState = STATE2;
            else                nextState = STATE1;
            break;
    }
}

void reset() // Vide tout les tableaux pour recommencer à 0
{
    initTableaux();
}

void initMelodies() // Charge les mélodies prédéfinies
{
    melodiePredefinie[0]=setBouton(9,75,12);
    melodiePredefinie[1]=setBouton(1,75,12);
    melodiePredefinie[2]=setBouton(4,75,12);
    melodiePredefinie[3]=setBouton(0,75,12);
}

void initTableaux() // Initialise les tableaux avec des boutons "vides"
{
    for(int i=0; i<10;i++)
    {
        melodieGenerer[i] = setBouton(0,0,0); // On initialise le tableau melodieGenerer avec des melodie vides
        melodieSaisie[i]  = setBouton(0,0,0); // On initialise le tableau melodieSaisie avec des melodie vides
    }
}

void genererMelodie() // Increment la combinaison de mélodies 
{
    int a = rand()%4; 
    for (int i=0; i<10;i++)
    {
        if (melodieGenerer[i].pinLed==0)
        {
            melodieGenerer[i]=melodiePredefinie[a];
            return;
        }
    }
}

void ecouteSaisie() // Ecoute la combinaison des boutons saisie par le joueur
{
    // Tant qu'on a pas tout saisi, on ne sort pas de là, pigé !
}

bool verification() // Vérifie si la combinaison saisie est = à la combinaison générée
{
    for(int i=0; i<10; i++)
    {
        int b1 = melodieGenerer[i].pinButton;
        int b2 = melodieSaisie[i].pinButton;
        
        if(b1 == 0 || b2 == 0) // Si on rencontre un bouton vide
            break;             // On sort de la boucle
        else if(b1 != b2)      // Sinon si on rencontre des boutons différents
            return false;      // On retourne faux
    }

    return true;
}

