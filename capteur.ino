const int pingPin = 7;
const int pin = 2;
int buttonState = 0;

/**************************************************************************/

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

/**************************************************************************/

void loop() {
  float duration, cm; //Valeurs décimales pour plus de précisions
  
/*****Séquence émission/réception des ultrasons******/

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

      
/************Affichage après activation*************/
 
  buttonState = digitalRead(pin);
  if(buttonState == HIGH) 
    {
      cm = microsecondsToCentimeters(duration);
      Serial.print(cm);
      Serial.print("cm");
      Serial.println();

      delay(10000000);
    }
} 
/*****Conversion de l'écart de temps en distance*****/
  
  float microsecondsToCentimeters(float microseconds) {
  return microseconds / 29 / 2;
  }
