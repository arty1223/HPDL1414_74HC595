//outputs every symbol from HPDL1414's table, works via ascii
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
  for (byte i = 0; i < 64; i++){
    disp.update(0,32+i);
    disp.update(1,32+i);
    disp.update(2,32+i);
    disp.update(3,32+i);
    delay(200);
  }
}