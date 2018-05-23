int tempsActivation;

typedef struct bouton BOUTON;

struct bouton {
    int pinLed;
    int pinButton;
    int frequence;
    int buzzer;
};

bouton setBouton(int pinLed,int pinButton,int frequence) // Crée un bouton avec une led et sa frequence pour le buzzer
{
    bouton b;
    b.pinLed = pinLed;
    b.pinButton = pinButton;
    b.frequence = frequence;
    b.buzzer=13;
    
    pinMode(b.pinLed,OUTPUT);
    pinMode(b.pinButton,INPUT);

    return b;
}

void activate(bouton b) // Allume une led (et devrait activer le buzzer également)
{
    tone(b.buzzer,b.frequence, tempsActivation);
    digitalWrite(b.pinLed,HIGH);
    delay(tempsActivation);
    digitalWrite(b.pinLed,LOW);
}

bool readBouton(bouton btn)
{ 
  delay(120);
  return digitalRead(btn.pinButton);
}


