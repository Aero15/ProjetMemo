#define pinBuzzer 13

int tempsActivation;

typedef struct bouton BOUTON;

struct bouton {
    int pinLed;
    int pinButton;
    int frequence;
};

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

void activate(bouton b) // Allume une led (et devrait activer le buzzer également)
{
    tone(pinBuzzer,b.frequence);
    digitalWrite(b.pinLed,HIGH);
    delay(tempsActivation);
    digitalWrite(b.pinLed,LOW);
    noTone(pinBuzzer);
    //delay(1000);
}

bool readBouton(bouton btn)
{ 
  return digitalRead(btn.pinButton);
}


