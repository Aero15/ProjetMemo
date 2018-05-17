#include <time.h>
#include "boutons.h"
#include "combinaisons.h"

#define STATE1 0
#define STATE2 1
#define STATE3 2
#define STATE4 3

int state, nextState;

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



