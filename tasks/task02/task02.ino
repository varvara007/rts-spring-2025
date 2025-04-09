#include <TaskManager.h>

void setup() {
    pinMode(3,OUTPUT);
     pinMode(5, OUTPUT);  // sets the pin as output
      pinMode(6, OUTPUT);  // sets the pin as output
      pinMode(9, OUTPUT);  // sets the pin as output
      pinMode(10, OUTPUT);  // sets the pin as output
    Tasks.add([] {
         PORTD ^= B00001000;
    })->startIntervalUsec( 10000);              
    
    Tasks.add([] {
         PORTD ^= B00100000;
    })->startIntervalUsec( 1000);     
      
    Tasks.add([] {
         PORTD ^= B01000000;
    })->startIntervalUsec( 500);   
        
    Tasks.add([] {
         PORTB ^= B00000010;
    })->startIntervalUsec( 100);   
        
    Tasks.add([] {
         PORTB ^= B00000100;
    })->startIntervalUsec( 50);       
}

void loop() {
    Tasks.update(); // automatically execute tasks
}
