#include <VirtualWire.h> // Librairie pour récepteur I2C
#include "LiquidCrystal_I2C.h" // Librairie pour LCD
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); // Initialisation du LCD
  
/******Définition des variables******/
 
int temp, vent, pres, humi, lum, prec;

/**************************************************************************/
 
void setup()
{
   Serial.begin(9600); // Configuration de la vitesse de transfert
  
    /*******Configuration du LCD*******/
 
   lcd.begin(20,4); //Taille du LCD
   lcd.setBacklightPin(3,POSITIVE);
   lcd.setBacklight(HIGH); //Intensité d'éclairage
   
    /**********Initialisation**********/
 
   lcd.clear(); //Suppression d'éventuels caractères résiduels
   lcd.setCursor(5,1);
   lcd.print("Bienvenue."); //Message de bienvenue
   
    /**Configuration du récepteur I2C**/
 
   vw_set_rx_pin (8);
   vw_setup(2000);
   vw_rx_start();
}

/**************************************************************************/

void loop()
{  
  /*********Réception valeurs**********/
 
  char message[VW_MAX_MESSAGE_LEN];
  char taille_message = VW_MAX_MESSAGE_LEN;
  
  if (vw_get_message((byte*)message, &taille_message)) {
    // On copie le message, corrompu ou non

    char * pch;
    pch = strtok (message,",");
    temp = atoi(pch);

    pch = strtok (NULL,",");
    pres = atoi(pch);

    pch = strtok (NULL,",");
    vent = atoi(pch);
    
    pch = strtok (NULL,",");
    humi = atoi(pch);
    
    pch = strtok (NULL,",");
    lum = atoi(pch);
    
    pch = strtok (NULL,",");
    prec = atoi(pch);
  }
  
  /**********Affichage tournant**********/
 
  delay(5000);
    lcd.clear();
    lcd.home();
    lcd.print("Vent:        ");
    lcd.print(vent);
    lcd.print("km/h");
    lcd.setCursor(0,1);
    lcd.print("Humidite:    ");
    lcd.print(humi);
    lcd.print("%");
    lcd.setCursor(0,2);
    lcd.print("Pression:    ");
    lcd.print(pres);
    lcd.print("hPa");
    lcd.setCursor(0,3);
    lcd.print("Temperature: ");
    lcd.print(temp);
    lcd.print((char) 223);
    lcd.print("C");
    delay(5000);
  
    lcd.clear();
    lcd.home();
    lcd.print("Humidite:    ");
    lcd.print(humi);
    lcd.print("%");
    lcd.setCursor(0,1);
    lcd.print("Pression:    ");
    lcd.print(pres);
    lcd.print("hPa");
    lcd.setCursor(0,2);
    lcd.print("Temperature: ");
    lcd.print(temp);
    lcd.print((char) 223);
    lcd.print("C");
    lcd.setCursor(0,3);
    lcd.print("Luminosite:  ");
    lcd.print(lum);
    lcd.print("Lx");
    delay(5000);
    
    lcd.clear();
    lcd.home();
    lcd.print("Pression:    ");
    lcd.print(pres);
    lcd.print("hPa");
    lcd.setCursor(0,1);
    lcd.print("Temperature: ");
    lcd.print(temp);
    lcd.print((char) 223);
    lcd.print("C");
    lcd.setCursor(0,2);
    lcd.print("Luminosite:  ");
    lcd.print(lum);
    lcd.print("Lx");
    lcd.setCursor(0,3);
    lcd.print("Precipit.:   ");
    lcd.print(prec);
    lcd.print("mm");
    delay(5000);
  
    lcd.clear();
    lcd.home();
    lcd.print("Pression:    ");
    lcd.print(pres);
    lcd.print("hPa");
    lcd.setCursor(0,1);
    lcd.print("Temperature: ");
    lcd.print(temp);
    lcd.print((char) 223);
    lcd.print("C");
    lcd.setCursor(0,2);
    lcd.print("Luminosite:  ");
    lcd.print(lum);
    lcd.print("Lx");
    lcd.setCursor(0,3);
    lcd.print("Vent:        ");
    lcd.print(vent);
    lcd.print("km/h");
    delay(5000);
  
    lcd.clear();
    lcd.home();
    lcd.print("Temperature: ");
    lcd.print(temp);
    lcd.print((char) 223);
    lcd.print("C");
    lcd.setCursor(0,1);
    lcd.print("Luminosite:  ");
    lcd.print(lum);
    lcd.print("Lx");
    lcd.setCursor(0,2);
    lcd.print("Vent:        ");
    lcd.print(vent);
    lcd.print("km/h");
    lcd.setCursor(0,3);
    lcd.print("Humidite:    ");
    lcd.print(humi);
    lcd.print("%");
    delay(5000);
  
    lcd.clear();
    lcd.home();
    lcd.print("Luminosite:  ");
    lcd.print(lum);
    lcd.print("Lx");
    lcd.setCursor(0,1);
    lcd.print("Vent:        ");
    lcd.print(vent);
    lcd.print("km/h");
    lcd.setCursor(0,2);
    lcd.print("Humidite:    ");
    lcd.print(humi);
    lcd.print("%");
    lcd.setCursor(0,3);
    lcd.print("Pression:    ");
    lcd.print(pres);
    lcd.print("hPa");
}
