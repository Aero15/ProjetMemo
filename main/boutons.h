typedef struct bouton BOUTON;

struct bouton {
    int pinLed;
    int pinButton;
    int frequence;
};

bouton setBouton(int pinLed,int pinButton,int frequence)
{
    bouton b;
    b.pinLed = pinLed;
    b.pinButton = pinButton;
    b.frequence = frequence;
    
    pinMode(b.pinLed,OUTPUT);
    pinMode(b.pinButton,INPUT);

    return b;
}

void activate(bouton b)
{
  digitalWrite(b.pinLed,HIGH);
  delay(1000);
  digitalWrite(b.pinLed,LOW);
}

