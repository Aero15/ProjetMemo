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
  digitalWrite(b.pinLed,HIGH);
  delay(1000);
  digitalWrite(b.pinLed,LOW);
}


