const int pinBouton = 2;

int etatBouton = 0;
float compteur = 0;
int temps = 0;
int prec;

/**************************************************************************/

void setup() 
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

/**************************************************************************/

void loop()
{
    etatBouton = digitalRead(pinBouton);
    if(etatBouton == HIGH) compteur = compteur+0.1; //Lorsque l'ILS est activé, on incrémente
    
    while(temps == 3600) //La valeur affichée sur le LCD est mise à jour toutes les heures
    {
      prec = (int)compteur;
    } 
    delay(1500);
    temps = temps+1;
}


 
