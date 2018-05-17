typedef struct bouton BOUTON;

struct bouton {
    int pinLed;
    int pinButton;
    int pinBuzzer;
    int frequence;
};

bouton setBouton(int pinLed,int pinButton,int frequence,int pinBuzzer) // Crée un bouton avec une led et sa frequence pour le buzzer
{
    bouton b;
    b.pinLed = pinLed;
    b.pinButton = pinButton;
    b.frequence = frequence;
    b.pinBuzzer=pinBuzzer;
    
    pinMode(b.pinLed,OUTPUT);
    pinMode(b.pinButton,INPUT);
    pinMode(b.pinBuzzer,OUTPUT);

    return b;
}

void activate(bouton b) // Allume une led (et devrait activer le buzzer également)
{
  tone(b.pinBuzzer,b.frequence,400);
  digitalWrite(b.pinLed,HIGH);
  delay(2000);
  digitalWrite(b.pinLed,LOW);
}


