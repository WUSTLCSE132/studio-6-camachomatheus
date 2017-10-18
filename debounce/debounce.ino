const int buttonPin = 2;
int count=0;
double unit=1000;
int buttonState;
int lastButtonState=LOW;
unsigned long lastDebounceTime=0;
unsigned long lastChangeInButton=0;
unsigned long debounceDelay=50;


void buttonPressed() {
  Serial.println("Interrupt");
  count++;
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  //attachInterrupt(digitalPinToInterrupt(buttonPin), buttonPressed, CHANGE);
  Serial.begin(9600);
}

void loop() {
   
  int reading=digitalRead(buttonPin);
  if(reading!=lastButtonState)
  {
    lastDebounceTime=millis();
  }

  if(millis()-lastDebounceTime>debounceDelay)
  {
    if(reading!=buttonState)
    {
      unsigned long interval=millis()-lastChangeInButton;
      //Serial.println(interval);
      if(interval<0.66*unit &&buttonState==LOW)
      {
        Serial.print("#Too short for a dot! Ignored!#");
      }
      else if(interval>0.66*unit &&interval < 1.33*unit && buttonState==LOW)
      {
        Serial.print("#.#");
      }else if(interval > 1.33*unit && interval <0.66*3*unit && buttonState==LOW)
      {
        Serial.print("Too long for a dot, but too short for a dash! Ignored!#");
      }else if(interval>0.66*3*unit &&interval < 1.33*3*unit && buttonState==LOW)
      {
        Serial.print("#-#");
      }else if(interval > 1.33*3*unit && buttonState==HIGH)
      {
        Serial.print("#Too long for a dash! Ignored!#");
      }else if(interval>0.66*3*unit &&interval < 1.33*3*unit && buttonState==HIGH)
      {
        Serial.print("#LETTER#");
      }else if(interval>0.66*7*unit &&interval < 1.33*7*unit && buttonState==HIGH)
      {
        Serial.print("#SPACE#");
      }
      
      buttonState=reading;
      lastChangeInButton=millis();
   
    }
  }
 
  
  lastButtonState=reading;
}
