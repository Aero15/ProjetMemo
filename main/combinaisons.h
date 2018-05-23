bouton melodiePredefinie[4]; // Contient les Boutons/Led/Frequences prédefinis
bouton melodieGenerer[10];   // Contient les B/L/F à saisir
bouton melodieSaisie[10];    // Contient la saisie des B/L/F du joueur 

void initTableaux() // Initialise les tableaux avec des boutons "vides"
{
    for(int i=0; i<10;i++)
    {
        melodieGenerer[i] = setBouton(0,0,0); // On initialise le tableau melodieGenerer avec des melodie vides
        melodieSaisie[i]  = setBouton(0,0,0); // On initialise le tableau melodieSaisie avec des melodie vides
    }
}

void genererMelodie() // Increment la combinaison de mélodies 
{
    int a = rand()%4; 
    for (int i=0; i<10;i++)
    {
        if (melodieGenerer[i].pinLed==0)
        {
            melodieGenerer[i]=melodiePredefinie[a];
            return;
        }
    }
}

void ecouteSaisie() // Ecoute la combinaison des boutons saisie par le joueur
{
  bool b0,b1,b2,b3;
  int taille=0;

  for (int i=0; i<10;i++)
  {
    if (melodieGenerer[i].pinButton!=0){taille++;}
    else break;
  }
  
  for (int i=0; i<taille;i++)
  {
    while(true)
    {
    int b0 = readBouton(melodiePredefinie[0]);
    int b1 = readBouton(melodiePredefinie[1]);
    int b2 = readBouton(melodiePredefinie[2]);
    int b3 = readBouton(melodiePredefinie[3]);
   if(b0==1 || b1==1 || b2==1 || b3==1)
    {
        Serial.print("step2");
        if(b0==1) melodieSaisie[i]=melodiePredefinie[0];
        else if(b1==1) melodieSaisie[i]=melodiePredefinie[1];
        else if(b2==1) melodieSaisie[i]=melodiePredefinie[2];
        else if(b3==1) melodieSaisie[i]=melodiePredefinie[3];
        activate(melodieSaisie[i]);
        break;
     }
    }
  }
}

bool verification() // Vérifie si la combinaison saisie est = à la combinaison générée
{
    for(int i=0; i<10; i++)
    {
        int b1 = melodieGenerer[i].pinButton;
        int b2 = melodieSaisie[i].pinButton;
        
        if(b1 == 0 || b2 == 0) // Si on rencontre un bouton vide
            break;             // On sort de la boucle
        else if(b1 != b2)      // Sinon si on rencontre des boutons différents
            return false;      // On retourne faux
    }

    return true;
}

void jouerMelodieGenerer()
{
  for(int i=0; i<10; i++)
  {
    if(melodieGenerer[i].pinButton!=0)
    {
      activate(melodieGenerer[i]);
      delay(1000);
    }
  }
}

