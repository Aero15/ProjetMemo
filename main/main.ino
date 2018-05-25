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

// Aslam
void loop()
{
    Serial.print("Current state : ");
    Serial.println(state);

    tempsActivation = meanData();
  
   // interrupts();
    state = nextState;
    switch(state) // Machine d'état
    {
        case STATE1:
           // noInterrupts();
            reset();
           // interrupts();
            break;
        case STATE2:
            genererMelodie();
            jouerMelodieGenerer();
            nextState = STATE3;
            break;
        case STATE3:
            ecouteSaisie();
            nextState = STATE4;
            break;
        case STATE4:
            delay(1000);
            if (verification()) nextState = STATE2;
            else                nextState = STATE1;
            break;
    }
}

// Aslam
void reset() // Vide tout les tableaux pour recommencer à 0
{
    initTableaux(); // Vide tout

    // Joue tous les sons et allumer tout les LEDs
    jouerMelodiePredefini();
    delay(1000);

    // Passe à l'état suivant
    nextState = STATE2;
}

// Aslam
void initMelodies() // Charge les mélodies prédéfinies
{
    melodiePredefinie[0]=setBouton(9,3,100);
    melodiePredefinie[1]=setBouton(10,4,300);
    melodiePredefinie[2]=setBouton(11,5,500);
    melodiePredefinie[3]=setBouton(12,6,700);
}


// Aslam
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
