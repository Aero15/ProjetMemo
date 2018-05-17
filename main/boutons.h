typedef struct bouton BOUTON;

struct bouton {
    int pinLed;
    int pinButton;
    int frequence;
    int buzzer;
};

bouton setBouton(int pinLed,int pinButton,int frequence,int buzzer) // Crée un bouton avec une led et sa frequence pour le buzzer
{
    bouton b;
    b.pinLed = pinLed;
    b.pinButton = pinButton;
    b.frequence = frequence;
    b.buzzer=buzzer;
    
    pinMode(b.pinLed,OUTPUT);
    pinMode(b.pinButton,INPUT);

    return b;
}

void activate(bouton b) // Allume une led (et devrait activer le buzzer également)
{
  tone(b.buzzer, 1000, 250);
  digitalWrite(b.pinLed,HIGH);
  digitalWrite(b.pinLed,LOW);
}


