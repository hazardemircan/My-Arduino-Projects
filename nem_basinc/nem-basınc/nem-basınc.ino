
const float  OffSet = 0.499;
float V, P,p1,p2,p3,d;
int nempin=A0;
int nem=0;
const int led1=2;
const int led2=3;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  
   pinMode(nempin,INPUT);
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   p1=1;
   p2=1;

}

void loop() {
  
  
  nem=analogRead(A0);
  V = analogRead(A1) * 5.00 / 1024;    
  P = (V - OffSet) * 400;             
  p1=(P+p1)/2;
  p2=(p1+p2)/2;
  p3=(p1+p2+P)/3;
  d=p3/9.81;
  Serial.print("Voltage:");
  Serial.print(V, 3);
  Serial.println("V");

  Serial.print(" Pressure:");
  Serial.print(p3, 1);
  Serial.println(" KPa");
  Serial.println();
  
Serial.print(" Derinlik:");
Serial.print(d);
Serial.println(" metre ");
  Serial.println();

  if(nem<1023)
  {
    digitalWrite(led1,HIGH);
  }
  if(d>1)
  {
    digitalWrite(led2,HIGH);
  }

Serial.print("nem: ");
Serial.println(nem);
delay(500);

}
