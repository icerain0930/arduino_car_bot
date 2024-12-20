const int DR = 2;      
const int DL = 3;  
int count=0;
int t,tt;
const int In1 = 10;
const int In2 = 11;
const int In3 = 12;      
const int In4 = 13;
const int ENA = 6;
const int ENB = 9;
int v = 100;//0~255

void setup(){
  //TRCT5000
  pinMode(DR, INPUT);
  pinMode(DL, INPUT);
  //L298N
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  //random
  randomSeed(analogRead(A0));
}
void carfront(){
  analogWrite(ENA,v);
  analogWrite(ENB,v+20);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}
void carback(){
  analogWrite(ENA,v);
  analogWrite(ENB,v+20);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
}

void carright(){
  analogWrite(ENA,v);
  analogWrite(ENB,v+20);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void carleft(){
  analogWrite(ENA,v);
  analogWrite(ENB,v+20);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
}

void carstop(){
  analogWrite(ENA,v);
  analogWrite(ENB,v+20);
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
}
//black = HIGH , white = LOW
void loop(){
    if(digitalRead(DR)==HIGH && digitalRead(DL)==HIGH){
      carback();
      delay(500);
      t=0;
      tt = rand() % 2 + 1;
      while(t <= tt){
        carright();
        delay(100);
        t++;
      }
    }
    else if(digitalRead(DR)==HIGH && digitalRead(DL)==LOW){
      carback();
      delay(500);
      t=0;
      tt = rand() % 2 + 1;
      while(t <= tt){
        carleft();
        delay(80);
        t++;
      }
    }
    else if(digitalRead(DR)==LOW && digitalRead(DL)==HIGH){
      carback();
      delay(500);
      t=0;
      tt = rand() % 2 + 1;
      while(t <= tt){
        carright();
        delay(80);
        t++;
      }
    }
    else{
      carfront();
      //delay(1);
      count=0;
    }
} 
