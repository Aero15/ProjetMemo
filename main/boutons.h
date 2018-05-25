#define pinBuzzer 13

int tempsActivation;

typedef struct bouton BOUTON;

struct bouton {
    int pinLed;
    int pinButton;
    int frequence;
};

//Aslam
//Input:pin d'un LED, pin d'un Bouton et une fréquence 
//Ouput: un bouton 
//
bouton setBouton(int pinLed,int pinButton,int frequence) // Crée un bouton avec une led et sa frequence pour le buzzer
{
    bouton b;
    b.pinLed = pinLed;
    b.pinButton = pinButton;
    b.frequence = frequence;
    
    pinMode(b.pinLed,OUTPUT);
    pinMode(b.pinButton,INPUT);

    return b;
}

//Aslam
//Input: un bouton 
//Ouput: effet de bord
//role :Permet d'activer les elements de la structure bouton: C'est à dire le la LED et le buzzer 
void activate(bouton b) // Allume une led (et devrait activer le buzzer également)
{
    tone(pinBuzzer,b.frequence);
    digitalWrite(b.pinLed,HIGH);
    delay(tempsActivation);
    digitalWrite(b.pinLed,LOW);
    noTone(pinBuzzer);
    //delay(1000);
}
//Ismael/Aslam
//Input: un element bouton
//Ouput: un booleen true si le bouton est appuyé, retourne faux sinon
bool readBouton(bouton btn)
{ 
  return digitalRead(btn.pinButton);
}


