
/*
Реализовать приложение (прошивку) для платы Arduino UNO, осуществляющую генерацию одновременно пяти импульсов со скважностью 50%:

    3 ножка - 10 мс.
    5 ножка - 1 мс.
    6 ножка - 500 мкс.
    9 ножка - 100 мкс.
    +10 ножка - 50 мкс.

*/
unsigned long time;
int ledPin = 9;      // LED connected to digital pin 9
  
    int val = 0;         // variable to store the read value

int pin3flag = 0;
int pin5flag = 0;
int pin6flag = 0;
int pin9flag = 0;
int pin10flag = 0;
unsigned long previousMillis3 = 0;        // will store last time LED was updated
unsigned long previousMillis5 = 0;        // will store last time LED was updated
unsigned long previousMillis6 = 0;        // will store last time LED was updated
unsigned long previousMillis9 = 0;        // will store last time LED was updated
unsigned long previousMillis10 = 0;        // will store last time LED was updated


    void setup() {
      pinMode(3, OUTPUT);  // sets the pin as output
      pinMode(5, OUTPUT);  // sets the pin as output
      pinMode(6, OUTPUT);  // sets the pin as output
      pinMode(9, OUTPUT);  // sets the pin as output
      pinMode(10, OUTPUT);  // sets the pin as output
    }

    void loop() {

      time = micros();
      
     

        if (time - previousMillis3 >= 10000){
        PORTD ^= B00001000;
        previousMillis3 = time;
        }

        if (time - previousMillis5 >= 1000){
        PORTD ^= B00100000;
        previousMillis5 = time;
        }

        if (time - previousMillis6 >= 500){
        PORTD ^= B01000000;
        previousMillis6 = time;
        }

        if (time - previousMillis9 >= 100){
        PORTB ^= B00000010;
        previousMillis9 = time;
        }
        
        if (time - previousMillis10 >= 50 ){
        PORTB ^= B00000100;
        previousMillis10 = time;
        }
      
      //analogWrite(3, 127); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
      //analogWrite(5, 127); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
      //analogWrite(6, 127); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
      //analogWrite(9, 127); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
      //analogWrite(11, 127); // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
    }
