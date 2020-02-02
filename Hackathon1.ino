
int prevfloor = 0;
int futfloor= 0;
int floor_count = 0;

int gofloor = 0;

int diff_floor = 0;
 
//int ENA = 10; //left
int motorInput1 = 6;
int motorInput2 = 7;

int IRsensor = 9; 
int sensorvalue = 2;   
void up();
void down(); 

void setup()
{
  pinMode(IRsensor, INPUT);
  
  
  //pinMode(ENA, OUTPUT);
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  

  Serial.begin(9600); //setting serial monitor at a default baund rate of 9600
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, LOW);
  
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  
}

void loop()
{   
    Serial.println("enter the floor number");
    int futfloor = Serial.parseInt(); // or directly write
    diff_floor = futfloor - prevfloor;

    digitalWrite(motorInput1, HIGH);
    digitalWrite(motorInput2, LOW);   
    
    delay(100);//give a small power to start
    
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);  
    
    if(diff_floor >0)
    {
      gofloor = diff_floor;
      floor_count = 0;
      up();
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    gofloor = 0;
    floor_count = 0;

    digitalWrite(13,HIGH);
    delay(1000);   
    digitalWrite(13,LOW);
      
    }

    else if(diff_floor<0)
    {
      gofloor = - diff_floor;
      floor_count = 0;
      down();
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW);
    gofloor = 0;
    floor_count = 0;

    digitalWrite(13,HIGH);
    delay(1000);   
    digitalWrite(13,LOW);
    }

  prevfloor = futfloor;
  }








    void up()
  {
    
    while(1)
    {

     sensorvalue = digitalRead(IRsensor);
     if(sensorvalue == 0)
     {
     digitalWrite(motorInput1, HIGH);
     digitalWrite(motorInput2, LOW); //keep moving up
     sensorvalue = digitalRead(IRsensor);
     }
     else if(sensorvalue == 1)
     {
     digitalWrite(motorInput1, LOW);
     digitalWrite(motorInput2, LOW); 
     digitalWrite(13,HIGH);
       delay(1000);
       digitalWrite(13,LOW);           
     break;
     }
     delay(3);
   digitalWrite(motorInput1, HIGH);
   digitalWrite(motorInput2, LOW);
   delay(2);
    
  } //end of while

     digitalWrite(motorInput1, HIGH);   //to come out of floor
     digitalWrite(motorInput2, LOW);

floor_count = floor_count + 1;

if(floor_count < gofloor)
      {
        up();
      }

else
      {
        digitalWrite(motorInput1, LOW);
        digitalWrite(motorInput2, LOW);
        digitalWrite(13,HIGH);
        delay(1000);   
        digitalWrite(13,LOW);         
      }
}

  void down()
  {
    
    while(1)
    {

    sensorvalue = digitalRead(IRsensor);
    if(sensorvalue == 0)
    {
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, HIGH); //keep moving up
    sensorvalue = digitalRead(IRsensor);
    }
    else if(sensorvalue == 1)
    {
    digitalWrite(motorInput1, LOW);
    digitalWrite(motorInput2, LOW); 
    digitalWrite(13,HIGH);
       delay(1000);
       digitalWrite(13,LOW);           
    break;
    }
    delay(3);
  digitalWrite(motorInput1, LOW);
  digitalWrite(motorInput2, HIGH);
  delay(2);
    
} //end of while

     digitalWrite(motorInput1, LOW);   //to come out of floor
     digitalWrite(motorInput2, HIGH);

floor_count = floor_count - 1;

if(floor_count > gofloor)
      {
        down();
      }

      else
      {
        digitalWrite(motorInput1, LOW);
        digitalWrite(motorInput2, LOW);
        digitalWrite(13,HIGH);
        delay(1000);   
        digitalWrite(13,LOW);         
      }
  }
  
  
