#include <time.h>
#include "boutons.h"
#include "combinaisons.h"

#define STATE1 0
#define STATE2 1
#define STATE3 2
#define STATE4 3

#define pinButtonReset 6

int state, nextState;
int N = 128, Te = 10; // N = Nb de points à récup dans le capteur lum, Te en ms

void setup()
{
    //Serial.begin(9600);
    Serial.begin(115200);  
    srand(time(NULL));
    
    initMelodies(); // Charge les mélodies prédéfinies
    
    pinMode(pinButtonReset, INPUT); // Défini le btnReset en INPUT
    attachInterrupt(digitalPinToInterrupt(pinButtonReset), reset, FALLING); // Lie le btnReset et sa fonction

    nextState = STATE1; // Passe à l'état 1
}

void loop()
{
    Serial.print("Current state : ");
    Serial.println(state);

    tempsActivation = meanData();
  
    interrupts();
    state = nextState;
    switch(state) // Machine d'état
    {
        case STATE1:
            noInterrupts();
            reset();
            interrupts();
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
    initTableaux(); // Vide tout

    // Joue tous les sons et allumer tout les LEDs
    activate(melodiePredefinie[0]);
    activate(melodiePredefinie[1]);
    activate(melodiePredefinie[2]);
    activate(melodiePredefinie[3]);

    // Passe à l'état suivant
    nextState = STATE2;
}

void initMelodies() // Charge les mélodies prédéfinies
{
    melodiePredefinie[0]=setBouton(9,3,264);
    melodiePredefinie[1]=setBouton(1,4,147);
    melodiePredefinie[2]=setBouton(4,5,330);
    melodiePredefinie[3]=setBouton(0,6,700);
}

int meanData()
{ 
    long sumval=0;
    
    for (int i=0; i < N;  i++)
    { 
        sumval+= analogRead(A5);
        delayMicroseconds(Te);                 
    } 
    return (sumval/N)*1.5;  
} 
