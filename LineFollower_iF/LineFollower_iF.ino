//Motor Pin
const int LF = 10;
const int LR = 11;
const int RF = 8; 
const int RR = 9;
//Sensor Pin
const int SL = 6;
const int SR = 7;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
  pinMode(LF, OUTPUT);
  pinMode(LR, OUTPUT);
  pinMode(RF, OUTPUT);
  pinMode(RR, OUTPUT);
  
  pinMode(SL, INPUT);
  pinMode(SR, INPUT); 
}

void loop() {
  if(digitalRead(SL)){
    if(digitalRead(SR)){    
      //Stop
      digitalWrite(LF,LOW);
      digitalWrite(LR,HIGH);
      digitalWrite(RF,LOW);
      digitalWrite(RR,HIGH);
      yield();
      digitalWrite(LF,LOW);
      digitalWrite(LR,LOW);
      digitalWrite(RF,LOW);
      digitalWrite(RR,LOW);
    }
    else{
      //Left
      digitalWrite(LF,HIGH);
      digitalWrite(LR,LOW);
      digitalWrite(RF,LOW);
      digitalWrite(RR,LOW);
    }
  }
  else 
  {
    if(digitalRead(SR)){
      //Right
      digitalWrite(LF,LOW);
      digitalWrite(LR,LOW);
      digitalWrite(RF,HIGH);
      digitalWrite(RR,LOW);
    }
    else{
    //Forward
    digitalWrite(LF,HIGH);
    digitalWrite(LR,LOW);
    digitalWrite(RF,HIGH);
    digitalWrite(RR,LOW);
    }
  }
 
    
}
