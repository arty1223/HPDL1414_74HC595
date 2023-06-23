//simple counter example
#include <HPDL1414_74HC595.h>
//HPDL1414 display(datapin, latchpin, clockpin, writepin);
#define data A0
#define STCP A1
#define SHCP A2
#define write PB0

#define dig0 PB1
#define dig1 PB2

HPDL1414 disp(data,STCP,SHCP,write,dig0,dig1);
void setup() {
}
void loop(){
  for (int i = 0; i < 9999; i+=1){
    disp.num(i);
    delay(100);
  }
}