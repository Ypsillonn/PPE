const int pinBouton = 2;

int etatBouton = 0;
float compteur = 0;
int quantite = 0;
float stock = 0;
int temps = 0;
int prec;

void setup() 
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop()
{
    etatBouton = digitalRead(pinBouton);
    Serial.print(temps);
    if(etatBouton == HIGH) compteur = compteur+0.1;
    
    while(temps == 3600) 
    {
      quantite = (int)compteur;
      stock = compteur-quantite;
      temps = 0;
      
      if(stock < 0.5) stock = 0;
      else stock = 1;
      
      quantite = quantite + stock;
    } 
    delay(1500);
    prec = quantite
    temps = temps+1;
}


 
