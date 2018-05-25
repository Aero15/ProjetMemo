bouton melodiePredefinie[4]; // Contient les Boutons/Led/Frequences prédefinis
bouton melodieGenerer[10];   // Contient les B/L/F à saisir
bouton melodieSaisie[10];    // Contient la saisie des B/L/F du joueur 

//Ismael
//Input:
//Ouput: effet de bord 
//role: permet d'innitialiser les tableau melodieGenerer et melodieSaisie par des valeurs nulles.
void initTableaux() // Initialise les tableaux avec des boutons "vides"
{
    for(int i=0; i<10;i++)
    {
        melodieGenerer[i] = setBouton(0,0,0); // On initialise le tableau melodieGenerer avec des melodie vides
        melodieSaisie[i]  = setBouton(0,0,0); // On initialise le tableau melodieSaisie avec des melodie vides
    }
}
//Ismael
//Input:
//Ouput: Effet de bord
//role: Genere une mélodie aléatoire et la stocke dans un tableau 
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

//Ismael/Aslam
//Input:
//Ouput:
//Role: Permet de stocker les notes joués par l'utilisateur et de les enregistrer dans un tableau
void ecouteSaisie() // Ecoute la combinaison des boutons saisie par le joueur
{
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
    
            if(b0==1) 
            {
                while(readBouton(melodiePredefinie[0])==1){}
                melodieSaisie[i]=melodiePredefinie[0];
                activate(melodieSaisie[i]);
                break;
            }
            else if(b1==1) 
            {
                while(readBouton(melodiePredefinie[1])==1){}
                melodieSaisie[i]=melodiePredefinie[1];
                activate(melodieSaisie[i]);
                break;
            }
            else if(b2==1) 
            {
                while(readBouton(melodiePredefinie[2])==1){}
                melodieSaisie[i]=melodiePredefinie[2];
                activate(melodieSaisie[i]);
                break;
            }
            else if(b3==1) 
            {
                while(readBouton(melodiePredefinie[3])==1){}
                melodieSaisie[i]=melodiePredefinie[3];
                activate(melodieSaisie[i]);
                break;
            }
           
        }
    }
}
//Aslam
//Input:
//Ouput:
//Role:
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

//Ismael
//Input:
//Ouput:
//Role:Joue la melodie généré aléatoirement
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
//Ismael
//Input:
//Ouput:
//Role: Joue les notes enregistré dans melodiePredefinie
void jouerMelodiePredefini()//Ismael
{
    for(int i=0; i<4; i++)
        if(melodiePredefinie[i].pinButton!=0) activate(melodiePredefinie[i]);
    for(int i=3; i>=0; i--)
        if(melodiePredefinie[i].pinButton!=0) activate(melodiePredefinie[i]);
}

