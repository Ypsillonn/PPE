#include "Wire.h" // For I2C
#include "LCD.h" // For LCD
#include "LiquidCrystal_I2C.h" // Added library*
//Set the pins on the I2C chip used for LCD connections
//ADDR,EN,R/W,RS,D4,D5,D6,D7
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7); // 0x27 is the default I2C bus address of the backpack-see article

long temp;
long vent;
long pres;
long humi;
long lum;
long prec;

void setup()
{
   Serial.begin(9600);
   lcd.begin(20,4); // 20 x 4 LCD module
   lcd.setBacklight(HIGH);
   lcd.clear();
   lcd.setCursor(5,1);
   lcd.print("Bienvenue."); 
   randomSeed(analogRead(0));  
}
void loop()
{
  vent = random(0, 100);
  humi = random(0, 100);
  pres = random(980, 1040);
  temp = random(-20, 50);
  vent = random(0, 100);
  lum = random(0, 1000);
  prec = random(0, 15);
  Serial.println(vent);
  Serial.println(humi);
  Serial.println(pres);
  Serial.println(temp);
  Serial.println(lum);
  Serial.println(prec);
  
  for (int i=0; i <= 120; i++)
  { 
    delay(10000);
    lcd.clear();
    lcd.setCursor(0,0);
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
    delay(10000);
  
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
    delay(10000);
    
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
  }
}
