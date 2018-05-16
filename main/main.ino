typedef struct bouton BOUTON;

struct BOUTON {
    int pinLed;
    int pinButton;
    int frequence;
}

bouton btn1;

void setup() {
  
  btn1.pinLed=2;
  btn1.pinButton=76;
  btn1.frequence=12;

}

void loop() {
  
  
}
