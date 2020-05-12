//SHUKIUR ALAM
#include <SoftwareSerial.h>
SoftwareSerial mSerial(3, 2);     // pin mode GSM( u_tx=3, u_rx=2 , GNG=GND, VCC=5v ), pir(OUT=pin n 6, GND=GND, VCC=5V)
int pir=6,led=13;

void setup()
{
  mSerial.begin(9600);
  Serial.begin(9600);
  pinMode(pir,INPUT);
  pinMode(led,OUTPUT);
}
void loop()
{ 
  if(digitalRead(pir)==HIGH&&HIGH==true){
    digitalWrite(led,HIGH);
    delay(500);
    digitalWrite(led,LOW);
     
   if(mSerial.available()!=0){
    Serial.read();
  }
    mSerial.println("AT");
    delay(100);
    mSerial.println("ATD+ZZxvxxxxxx"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial
    delay(20000);
    mSerial.println("ATH");
    
  }
  else if(digitalRead(pir)==LOW&&LOW==true){
    delay(500);
     mSerial.println("ATH");
     digitalWrite(led,LOW);
  }
}
