bouton melodiePredefinie[4]; // Contient les Boutons/Led/Frequences prédefinis
bouton melodieGenerer[10];   // Contient les B/L/F à saisir
bouton melodieSaisie[10];    // Contient la saisie des B/L/F du joueur 

void initTableaux() // Initialise les tableaux avec des boutons "vides"
{
    for(int i=0; i<10;i++)
    {
        melodieGenerer[i] = setBouton(0,0,0,0); // On initialise le tableau melodieGenerer avec des melodie vides
        melodieSaisie[i]  = setBouton(0,0,0,0); // On initialise le tableau melodieSaisie avec des melodie vides
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
    // Tant qu'on a pas tout saisi, on ne sort pas de là, pigé !
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
