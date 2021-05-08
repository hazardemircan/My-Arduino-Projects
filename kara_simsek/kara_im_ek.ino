const int ledDizi[]={2,3,4,5,6};


void setup() {

  for (int i=0; i<=4;i++)
  {
    pinMode(ledDizi[i], OUTPUT);
  }

   
}

void loop() {
  
  for (int i=0;i<=4;i++)
  {
    digitalWrite(ledDizi[i], HIGH);
    delay(50);
    digitalWrite(ledDizi[i], LOW);

    
  }
   for (int j=4; j>=0; j--)
    {
      digitalWrite(ledDizi[j], HIGH); 
      delay(50);
      digitalWrite(ledDizi[j], LOW);
      
    }  
 
  return 0;
}
