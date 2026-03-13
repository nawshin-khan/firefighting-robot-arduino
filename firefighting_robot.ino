#include <Servo.h>  //include servo.h library
Servo myservo;
 
int pos = 0;    
boolean fire = false;
 
#define Left A2      // left sensor
#define Right 7    // right sensor
#define Forward A3   //front sensor

#define LM1 2       // left motor
#define LM2 3       // left motor
#define RM1 4       // right motor
#define RM2 5       // right motor
#define ENA A0
#define ENB A1
#define pump 6
#define SPEED 150
 
void setup()
{
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  digitalWrite(pump, HIGH);
  myservo.attach(11);
  myservo.write(90); 
}
 
void put_off_fire()
{
    delay (500);
 
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    
   digitalWrite(pump, LOW);
   delay(500);
    
    for (pos = 50; pos <= 130; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 130; pos >= 50; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  
  digitalWrite(pump,HIGH);
  myservo.write(90);
  
  fire=false;
}
 
void loop()
{
   myservo.write(90); //Sweep_Servo();  
   digitalWrite(pump, HIGH);
    if (digitalRead(Left) ==1 && digitalRead(Right)==1 && digitalRead(Forward) ==1) 
    {
    
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    }
    
    else if (digitalRead(Forward) ==0) 
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(ENA, SPEED);

    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(ENB, SPEED);

    fire = true;
    delay(200);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    }
    
    else if (digitalRead(Left) ==0)
    {
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    analogWrite(ENA, 150);

    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
    analogWrite(ENB, 0);

    delay(300);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);

    }
    
    else if (digitalRead(Right) ==0) 
    {
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    analogWrite(ENA, 0);

    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    analogWrite(ENB, 150);

    delay(300);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);

    }
    
delay(300);//change this value to increase the distance
 
     while (fire == true)
     {
      put_off_fire();
     }
}
