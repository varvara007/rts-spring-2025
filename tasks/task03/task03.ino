int pin = 13;
volatile int state = LOW;

unsigned long  times[100] ;
int indexer = 0;
unsigned long last_time = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), blink, CHANGE);
}

void loop()
{
  
}

void blink()
{
  //state = !state;
  unsigned long  current_time = micros();
  
  times[indexer] = current_time - last_time;

  last_time = current_time;

  indexer += 1;
  if (indexer == 100){
    indexer = 0;

    float avg = 0;
    
    float std = 0;

    for (int  i = 0; i<100; i++){
        avg += times[i];
      }
    avg = avg/100;

    for (int  i = 0; i<100; i++){
        std += (times[i]-avg)*(times[i]-avg);
      }
     std = std/100;
    Serial.println(avg);
    
    Serial.println(sqrt(std));
    
    Serial.println("----");   
  } 
  digitalWrite(pin, HIGH);
}
