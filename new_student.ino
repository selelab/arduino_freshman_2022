const int BUTTON = 2;

const int C_GR = 3;
const int C_YE = 4;
const int C_RE = 5;

const int P_GR = 6;
const int P_RE = 7;

int state;
void setup()
{
     pinMode(C_GR, OUTPUT);
     pinMode(C_YE, OUTPUT);
     pinMode(C_RE, OUTPUT);
     pinMode(P_GR, OUTPUT);
     pinMode(P_RE, OUTPUT);
     pinMode(BUTTON,INPUT);
     Serial.begin(9600);     
}

void loop()
{
    state = digitalRead(BUTTON);
    digitalWrite(C_GR, HIGH); 
    digitalWrite(P_RE, HIGH); 
    
    if(state == LOW){
      //黄色信号
      delay(2000);
      digitalWrite(C_GR, LOW); 
      digitalWrite(C_YE, HIGH); 
      delay(2500);

      //赤信号
      digitalWrite(C_YE, LOW); 
      digitalWrite(C_RE,HIGH);
      delay(2000);
      digitalWrite(P_RE,LOW);
      digitalWrite(P_GR,HIGH);
      delay(7000);

      //歩行者信号点滅
      for(int i=0;i<9;i++){
        delay(200);
        digitalWrite(P_GR,LOW);
        delay(200);
        digitalWrite(P_GR,HIGH);
      }

      //歩行者信号赤
      digitalWrite(P_GR,LOW);
      digitalWrite(P_RE,HIGH);
      delay(2500);
      //青信号
      digitalWrite(C_RE, LOW); 
      digitalWrite(C_GR,HIGH);
    }
    
}
