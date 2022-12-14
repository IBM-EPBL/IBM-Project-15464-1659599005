// C++ code
int PEIZO = 3;
int PIR = 2;
int tmp = 1;
int TmpVal;
int pirLed = 4;
int TempLed = 5;

void setup()
{
  pinMode(PEIZO,OUTPUT);
  pinMode(tmp, INPUT);
  pinMode(PIR, INPUT);
  pinMode(pirLed, OUTPUT);
  pinMode(TempLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  TmpVal = analogRead(tmp);
  Serial.write(TmpVal);
  if(TmpVal>246){
    digitalWrite(TempLed,HIGH);
    for(int i=255;i>0;i--){
      delay(1);	
      analogWrite(PEIZO,i);
    }
    analogWrite(PEIZO,0);
    digitalWrite(TempLed,LOW);
    delay(100);
  }
  if(digitalRead(PIR) == HIGH){
    digitalWrite(pirLed,HIGH);
    for(int i=0;i<255;i++){
        delay(1);
        int x = (i*i*i)%255;
      	analogWrite(PEIZO,x);
    }
    analogWrite(PEIZO,0);
    digitalWrite(pirLed,LOW);
    delay(100);
  }
}