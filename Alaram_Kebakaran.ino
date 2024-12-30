#define dht_apin A0 // Analog Pin sensor is connected to
 
//dht DHT;
int Threshold = 50;
void FireAlaram(int);
int temp_read(void);
void setup()
{ 
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(9,OUTPUT);
  
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);      //Wait before accessing Sensor
 
}//end "setup()"
 
void loop()
{
  //Start of Program 
    int temperature = temp_read(); //reading temperature
    
  while(temperature =  temp_read())
  {
    if(temperature>Threshold)
    {
      if(temperature>=70)
      {
        digitalWrite(2,HIGH);
        digitalWrite(3,LOW);
        digitalWrite(5,LOW);
        digitalWrite(9,HIGH);
        Serial.println("*** FIRE** **FIRE***");
        delay(100);
      }
      else
      {
        digitalWrite(3,HIGH);
        digitalWrite(2,LOW);
        digitalWrite(5,LOW);
        digitalWrite(9,LOW);
        Serial.println("***Caution***");
        
      }
      
      delay(10);
    }
     else
     {
        digitalWrite(5,HIGH);
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(9,LOW);
     }
    delay(1000); 
    //temperature =  temp_read();                      //Wait 5 seconds before accessing sensor again.
   } //end while
                   //Fastest should be once every two seconds.
}// end loop() 
int temp_read()
{
  //int temperature = DHT.read11(dht_apin);
  //int temperature = ( analogRead(A0)-500)/10;
  int temperature = map(((analogRead(A0)-20) * 3.04), 0, 1023, -40, 125);
   Serial.print("temperature = ");
    Serial.print(temperature); 
    Serial.println("C  ");
     Serial.println();
  return temperature;
}