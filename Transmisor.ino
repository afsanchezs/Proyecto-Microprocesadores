#include <Wire.h>
uint16_t m,value,d0=0,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,sd1,sd2,sd3,sd4,p1,p2,p4,p8,p16=0;
byte m1,m2;
int posicion;
char arreglo[20];
void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
   if(Serial.available())
  {
    memset(arreglo, 0,sizeof(arreglo));
    while(Serial.available()>0)
    {
      delay(5);
      arreglo[posicion]=Serial.read();
      posicion++;
    }
    posicion=0;
  }
  value=(uint16_t)(atoi(arreglo));
  d1=(value<<6)>>15;
  d2=(value<<7)>>15;
  d3=(value<<8)>>15;
  d4=(value<<9)>>15;
  d5=(value<<10)>>15;
  d6=(value<<11)>>15;
  d7=(value<<12)>>15;
  d8=(value<<13)>>15;
  d9=(value<<14)>>15;
  d10=(value<<15)>>15;
  sd1=d1+d3+d4+d6+d8+d10;
  sd2=d2+d3+d5+d6+d9+d10;
  sd3=d1+d2+d3+d7+d8+d9+d10;
  sd4=d4+d5+d6+d7+d8+d9+d10;
  if(sd1%2==0)
   {
     p1=0;
   }
  else
  {
    p1=1;
  }
  if(sd2%2==0)
   {
     p2=0;
   }
  else
  {
    p2=1;
  }
  if(sd3%2==0)
   {
     p4=0;
   }
  else
  {
    p4=1;
  }
  if(sd4%2==0)
   {
     p8=0;
   }
  else
  {
    p8=1;
  }
  m=(p1<<15)+(p2<<14)+(p4<<12)+(d1<<11)+(d2<<10)+(d3<<9)+(p8<<8)+(d4<<7)+(d5<<6)+(d6<<5)+(d7<<4)+(d8<<3)+(d9<<2)+(d10<<1);
  m1=(uint8_t)(m>>8);
  m2=(uint8_t)((m<<8)>>8);
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(m1);              // sends one byte
  Wire.write(m2);
  Wire.endTransmission();    // stop transmitting
  Serial.print("\n");
  Serial.print("\n");
  Serial.print("\n");
  Serial.print("PWM para transmitir: ");
  Serial.print(value);
  Serial.print("\n");
  Serial.print("Mensaje: ");
  Serial.print(value,BIN);
  Serial.print("\n");
  Serial.print("Mensaje Codificado: ");
  Serial.print(m,BIN);
  Serial.print("\n");
  Serial.print("Byte 1: ");
  Serial.print(m1,BIN);
  Serial.print("\n");
  Serial.print("Byte 2: ");
  Serial.print(m2,BIN);
  Serial.print("\n");
  Serial.print("\n");
  Serial.print("\n");
  delay(1000);
}
