#include <SoftwareSerial.h>

SoftwareSerial BT(9, 8); //TX, RX respetively
String readvoice;
int ls=3; //left sensor
int rs=5; //right sensor

void setup() 
{
 BT.begin(9600);
 Serial.begin(9600);
 
  pinMode(4, OUTPUT);
  pinMode(ls, INPUT); //left sensor
  pinMode(rs, INPUT);  //right sensor
  pinMode(6, OUTPUT);
  pinMode(10,OUTPUT);//led
   pinMode(11,OUTPUT);//horn
  

}
//-----------------------------------------------------------------------// 
void loop()
{
  boolean flag=true;
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if ((readvoice.length() > 0))
  {
    
    Serial.println(readvoice);
    Serial.println(analogRead(ls));
     Serial.println(analogRead(rs));
    if((readvoice=="automatic") )
    {
      while(flag==true)
      {
      if(digitalRead(ls) || digitalRead(rs))
      {
       digitalWrite(10,HIGH);
    digitalWrite (4, HIGH);
   
    digitalWrite(6,LOW);
    delay(100);
      }
      else if(!digitalRead(ls) && digitalRead(rs)) //turn right
      {
       digitalWrite(10,HIGH);  
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (800);
   
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
      
    delay(100);
      }
    else  if(digitalRead(ls) && !digitalRead(rs)) //turn left
      {
        digitalWrite(10,HIGH);
    digitalWrite (4,LOW);
    
    digitalWrite (6,LOW);
   delay (800);
     
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
     
    delay(100);
      }
      else if (!digitalRead(ls) || !digitalRead(rs)) //turn right
      {
        
   digitalWrite (4, LOW);
   digitalWrite(10,LOW);
   digitalWrite (6, LOW);
     flag=false;
   delay(100);
 
      }
        
      }
    }
     

 else if(readvoice == "accelerate")
  {
    
    digitalWrite (4, HIGH);
   
    digitalWrite(6,LOW);
     Serial.println("THE LOOP EXECUTED?");
    
    delay(100);
  }

  else if(readvoice == "back")
  {
    
    digitalWrite(4, LOW);
    
    digitalWrite(6,HIGH);
    Serial.println("THE LOOP EXECUTED?"); 
    
    delay(100);
  }

  else if (readvoice == "left")
  {
    
    digitalWrite (4,LOW);
   
    digitalWrite (6,LOW);
   delay (800);
      
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
     
    delay(100);
  
  }

 else if ( readvoice == "right")
 {
   
   digitalWrite (4, HIGH);
  
   digitalWrite (6, LOW);
   delay (800);
   
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
      
    delay(100);
 }

 else if (readvoice == "stop")
 {
  
   digitalWrite (4, LOW);
   
   digitalWrite (6, LOW);
   digitalWrite (10, LOW);
   digitalWrite (11, LOW);
  
   delay (100);
 }
 
 else if (readvoice == "spin")
 {
 
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (400);
      
    digitalWrite (4, HIGH);
  
    digitalWrite(6,LOW);
    delay(600);
    
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (500);
   
   digitalWrite (4, LOW);
  
   digitalWrite (6, HIGH);
   delay (500);


   digitalWrite (4, HIGH);
  
   digitalWrite (6, LOW);
   delay (400);
      
    digitalWrite (4, HIGH);
   
    digitalWrite(6,LOW);
    delay(600);
    
   digitalWrite (4, HIGH);
  
   digitalWrite (6, LOW);
   delay (500);
  
   digitalWrite (4, LOW);
  
   digitalWrite (6, HIGH);
   delay (500);
   digitalWrite (4, HIGH);
  
   digitalWrite (6, LOW);
   delay (400);
     
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
    delay(600);
    
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (500);
   
   digitalWrite (4, LOW);
   
   digitalWrite (6, HIGH);
   delay (500);
   digitalWrite (4, HIGH);
  
   digitalWrite (6, LOW);
   delay (400);
     
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
    delay(600);
    
   digitalWrite (4, HIGH);
  
   digitalWrite (6, LOW);
   delay (500);
   
   digitalWrite (4, LOW);
  
   digitalWrite (6, HIGH);
   delay (500);
   digitalWrite (4, HIGH);
  
   digitalWrite (6, LOW);
   delay (400);
     
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
    delay(600);
   
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (500);
   
   digitalWrite (4, LOW);
   
   digitalWrite (6, HIGH);
   delay (500);
   digitalWrite (4, HIGH);
  
   digitalWrite (6, LOW);
   delay (400);
      
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
    delay(600);
    
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (500);
  
   digitalWrite (4, LOW);
   
   digitalWrite (6, HIGH);
   delay (500);
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (400);
      
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
    delay(600);
    
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (500);
   
   digitalWrite (4, LOW);
  
   digitalWrite (6, HIGH);
   delay (500);
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (400);
      
    digitalWrite (4, HIGH);
    
    digitalWrite(6,LOW);
    delay(600);
   
   digitalWrite (4, HIGH);
   
   digitalWrite (6, LOW);
   delay (500);
  
   digitalWrite (4, LOW);
   
   digitalWrite (6, HIGH);
   delay (500);
 }
 else if(readvoice=="headlights")
 {
  digitalWrite(10,HIGH);
  delay(1000); 
 }
else if(readvoice=="sound")
 {
  digitalWrite(11,HIGH);
  delay(2000);
 }
 readvoice="";
  } //Reset the variable
}
