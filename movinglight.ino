const int analogPin=A0;
const int ledCount=10;
int ledPins[]={2,3,4,5,6,7,8,9,10,11};
void setup() {
  // put your setup code here, to run once:
  for (int thisLed=0;thisLed<ledCount;thisLed++)
  {
    pinMode(ledPins[thisLed],OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorReading=analogRead(analogPin);
  int ledLevel=map(sensorReading,0,1023,0,ledCount);

  /*for(int thisLed=0;thisLed<ledCount;thisLed++)
   {
    if(thisLed<ledLevel)
    {
      digitalWrite(ledPins[thisLed],HIGH);
    }
    else
    {
      digitalWrite(ledPins[thisLed],LOW);
    }
   }*/



   while(ledLevel<511&&ledLevel>=0)
   {
     for(int thisLed=0;thisLed<ledCount;thisLed++)
     {
        int sensorReading=analogRead(analogPin);
        int ledLevel=map(sensorReading,0,1023,0,ledCount);
        int Dt=map(ledLevel,0,10,10,100);
        digitalWrite(ledPins[thisLed],HIGH);
        digitalWrite(ledPins[10-thisLed],HIGH);
        delay(Dt);
        digitalWrite(ledPins[thisLed],LOW);
        digitalWrite(ledPins[10-thisLed],LOW);
        delay(Dt);
     }

    }

   
  


}
