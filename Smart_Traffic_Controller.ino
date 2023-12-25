const int red_1=2;
const int yellow_1=3;
const int green_1=4;

const int red_2=5;
const int yellow_2=6;
const int green_2=7;

const int red_3=8;
const int yellow_3=9;
const int green_3=10;

const int red_4=11;
const int yellow_4=12;
const int green_4=13;


const int sensor1=A0;
const int sensor2=A1;
const int sensor3=A2;
const int sensor4=A3;
const int sensor5=A4;
const int sensor6=A5;
const int sensor7=A6;
const int sensor8=A7;

void setup()
{
  pinMode(red_1,OUTPUT);
  pinMode(yellow_1,OUTPUT);
  pinMode(green_1,OUTPUT);

  pinMode(red_2,OUTPUT);
  pinMode(yellow_2,OUTPUT);
  pinMode(green_2,OUTPUT);
  
  pinMode(red_3,OUTPUT);
  pinMode(yellow_3,OUTPUT);
  pinMode(green_3,OUTPUT);
  
  pinMode(red_4,OUTPUT);
  pinMode(yellow_4,OUTPUT);
  pinMode(green_4,OUTPUT);
  
  
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  pinMode(sensor4,INPUT);
  pinMode(sensor5,INPUT);
  pinMode(sensor6,INPUT);
  pinMode(sensor7,INPUT);
  pinMode(sensor8,INPUT);
}

void loop()
{
  {
  if(digitalRead(sensor1)==HIGH &&(digitalRead(sensor2)==HIGH))
  {
  digitalWrite(2,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
  delay(1);
  digitalWrite(2,LOW);
  delay(1);
  digitalWrite(3,HIGH);
  delay(50);
  digitalWrite(3,LOW);
  delay(1);
  digitalWrite(4,HIGH);
  delay(3000);
  digitalWrite(4,LOW);
  delay(1);
  }
  else if(digitalRead(sensor1)==HIGH &&(digitalRead(sensor2)==LOW))
  {
  digitalWrite(2,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
  delay(1);
  digitalWrite(2,LOW);
  delay(1);
  digitalWrite(3,HIGH);
  delay(50);
  digitalWrite(3,LOW);
  delay(1);
  digitalWrite(4,HIGH);
  delay(2000);
  digitalWrite(4,LOW);
  delay(1);
  }
  else
  {
  digitalWrite(2,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
  delay(1);
  digitalWrite(2,LOW);
  delay(1);
  digitalWrite(3,HIGH);
  delay(50);
  digitalWrite(3,LOW);
  delay(1);
  digitalWrite(4,HIGH);
  delay(100);
  digitalWrite(4,LOW);
  delay(1);
  }
}
{
  if(digitalRead(sensor3)==HIGH &&(digitalRead(sensor4)==HIGH))
  {
  digitalWrite(5,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
  delay(1);
  digitalWrite(5,LOW);
  delay(1);
  digitalWrite(6,HIGH);
  delay(50);
  digitalWrite(6,LOW);
  delay(1);
  digitalWrite(7,HIGH);
  delay(3000);
  digitalWrite(7,LOW);
  delay(1);
  }
  else if(digitalRead(sensor3)==HIGH &&(digitalRead(sensor4)==LOW))
  {
  digitalWrite(5,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
  delay(1);
  digitalWrite(5,LOW);
  delay(1);
  digitalWrite(6,HIGH);
  delay(50);
  digitalWrite(6,LOW);
  delay(1);
  digitalWrite(7,HIGH);
  delay(2000);
  digitalWrite(7,LOW);
  delay(1);
  }
  else
  {
  digitalWrite(5,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(11,HIGH);
  delay(1);
  digitalWrite(5,LOW);
  delay(1);
  digitalWrite(6,HIGH);
  delay(50);
  digitalWrite(6,LOW);
  delay(1);
  digitalWrite(7,HIGH);
  delay(100);
  digitalWrite(7,LOW);
  delay(1);
  }
}
{
  if(digitalRead(sensor5)==HIGH &&(digitalRead(sensor6)==HIGH))
  {
  digitalWrite(8,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(11,HIGH);
  delay(1);
  digitalWrite(8,LOW);
  delay(1);
  digitalWrite(9,HIGH);
  delay(50);
  digitalWrite(9,LOW);
  delay(1);
  digitalWrite(10,HIGH);
  delay(3000);
  digitalWrite(10,LOW);
  delay(1);
  }
  else if(digitalRead(sensor5)==HIGH &&(digitalRead(sensor6)==LOW))
  {
  digitalWrite(8,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(11,HIGH);
  delay(1);
  digitalWrite(8,LOW);
  delay(1);
  digitalWrite(9,HIGH);
  delay(50);
  digitalWrite(9,LOW);
  delay(1);
  digitalWrite(10,HIGH);
  delay(2000);
  digitalWrite(10,LOW);
  delay(1);
  }
  else
  {
  digitalWrite(8,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(11,HIGH);
  delay(1);
  digitalWrite(8,LOW);
  delay(1);
  digitalWrite(9,HIGH);
  delay(50);
  digitalWrite(9,LOW);
  delay(1);
  digitalWrite(10,HIGH);
  delay(100);
  digitalWrite(10,LOW);
  delay(1);
  }
}
{
  if(digitalRead(sensor7)==HIGH &&(digitalRead(sensor8)==HIGH))
  {
  digitalWrite(11,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(2,HIGH);
  delay(1);
  digitalWrite(11,LOW);
  delay(1);
  digitalWrite(12,HIGH);
  delay(50);
  digitalWrite(12,LOW);
  delay(1);
  digitalWrite(13,HIGH);
  delay(3000);
  digitalWrite(13,LOW);
  delay(1);
  }
  else if(digitalRead(sensor7)==HIGH &&(digitalRead(sensor8)==LOW))
  {
  digitalWrite(11,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(2,HIGH);
  delay(1);
  digitalWrite(11,LOW);
  delay(1);
  digitalWrite(12,HIGH);
  delay(50);
  digitalWrite(12,LOW);
  delay(1);
  digitalWrite(13,HIGH);
  delay(2000);
  digitalWrite(13,LOW);
  delay(1);
  }
  else
  {
  digitalWrite(11,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(2,HIGH);
  delay(1);
  digitalWrite(11,LOW);
  delay(1);
  digitalWrite(12,HIGH);
  delay(50);
  digitalWrite(12,LOW);
  delay(1);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1);
  }
}
}
