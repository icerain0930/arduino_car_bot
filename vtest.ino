const int DR = 2;      
const int DL = 3;  

const int Tri = 4;
const int Echo = 5;
int Dur;
int Dis;
int count=0;
int t,tt;
const int In1 = 10;
const int In2 = 11;
const int In3 = 12;      
const int In4 = 13;
const int ENA = 6;
const int ENB = 9;
int v = 150;//0~255

const unsigned int MODE = 2;
int *  mode;

void setup(){
  Serial.begin(9600);
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
  //HC-SR04
  pinMode(Tri, OUTPUT);
  pinMode(Echo, INPUT);
  //random
  randomSeed(analogRead(A0));
  //reset button
  mode =(int *) malloc (sizeof(int));
  if(++(*mode) >= MODE) (*mode) = 0;
  Serial.print("mode:");
  Serial.println((*mode));
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

void Distance(){
    digitalWrite(Tri,LOW);
    delay(1);
    digitalWrite(Tri,HIGH);
    delay(11);
    digitalWrite(Tri,LOW);
    Dur = pulseIn(Echo,HIGH);
    Dis = Dur*0.034/2;
}
//black = HIGH , white = LOW
void loop(){
    digitalWrite(Tri,LOW);
    delay(1);
    digitalWrite(Tri,HIGH);
    delay(11);
    digitalWrite(Tri,LOW);
    Dur = pulseIn(Echo,HIGH);
    Dis = Dur*0.034/2;
    //Serial.println(Dis);
  if(*mode == 1){
    if(digitalRead(DR)==HIGH && digitalRead(DL)==HIGH){
      carfront();
      delay(100);
    }
    else if(digitalRead(DR)==HIGH && digitalRead(DL)==LOW){
      carright()
      delay(100);
    }
    else if(digitalRead(DR)==LOW && digitalRead(DL)==HIGH){
      carleft()
      delay(100);
    }
    else{
      delay(100);
    }
  }
} 
