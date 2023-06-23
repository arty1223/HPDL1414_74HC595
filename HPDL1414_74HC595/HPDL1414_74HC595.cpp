#include <Arduino.h>
#include "HPDL1414_74HC595.h"
HPDL1414::HPDL1414(uint8_t data, uint8_t latch, uint8_t clock, uint8_t write, uint8_t DIG0, uint8_t DIG1){ 
  datapin = data;
  latchpin = latch;
  clockpin = clock;
  writepin = write;
  digpin0 = DIG0;
  digpin1 = DIG1;  
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(write, OUTPUT);
  pinMode(DIG0, OUTPUT);
  pinMode(DIG1, OUTPUT);  
  update(3,' ');
  update(2,' ');
  update(1,' ');
  update(0,' ');
}
void HPDL1414::update(byte digit, byte sprite){ //вывод на регистр
  switch (digit)
  {
  case 0:
    digitalWrite(digpin0,0);
    digitalWrite(digpin1,0);
    break;
  case 1:
    digitalWrite(digpin0,1);
    digitalWrite(digpin1,0);
    break;
  case 2:
    digitalWrite(digpin0,0);
    digitalWrite(digpin1,1);
    break;
  case 3:
    digitalWrite(digpin0,1);
    digitalWrite(digpin1,1);
    break;
  default:
    break;
  }  
  digitalWrite(latchpin, LOW);    
  shiftOut(datapin, clockpin, MSBFIRST, sprite); 
  digitalWrite(latchpin, HIGH);
  digitalWrite(writepin, LOW);
  delayMicroseconds(1);
  digitalWrite(writepin, HIGH);
}

void HPDL1414::string(char str[]){   
  update(3,str[0]);
  update(2,str[1]);
  update(1,str[2]);
  update(0,str[3]);  
}
void HPDL1414::num(int* numb){
  if (*numb < 0){
    *numb = abs(*numb);
    update(3, '-');
    update(2, *numb % 1000 / 100 + 48);
    update(1, *numb % 1000 % 100 / 10 + 48);  
    update(0, *numb % 1000 % 100 % 10 + 48);
    return;
  }
  update(3, *numb / 1000 + 48);
  update(2, *numb % 1000 / 100 + 48);
  update(1, *numb % 1000 % 100 / 10 + 48);  
  update(0, *numb % 1000 % 100 % 10 + 48);
}
void HPDL1414::mix(char ltr,byte* num){
  update(3, ltr);
  update(2, *num % 1000 / 100 + 48);
  update(1, *num % 1000 % 100 / 10 + 48);  
  update(0, *num % 1000 % 100 % 10 + 48);
}