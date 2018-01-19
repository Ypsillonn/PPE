const int ledPin = 13;
const int buttonPin = 2;

int buttonState = 0;
float compteur = 0;
int quantite = 0;
float stock = 0;
int temps = 0; 
byte bascule = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
    buttonState = digitalRead(buttonPin);
    Serial.print(temps);
    if(buttonState == HIGH) 
    {
      digitalWrite(ledPin, HIGH);
      compteur = compteur+0.1;
    }
    else digitalWrite(ledPin, LOW);

    while(temps == 3600) 
    {
      quantite = (int)compteur;
      stock = compteur-(int)compteur;
      temps = 0;
      
      if(stock < 0.5) stock = 0;
      else stock = 1;
      
      quantite = quantite + stock;
      Serial.print(quantite);
    } 
    delay(1000);
    temps = temps+1;
}


 
