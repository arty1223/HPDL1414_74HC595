//text output example
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
  disp.string("TEXT");
  delay(500);
  disp.string("TEST");
  delay(500);
  disp.string("HELO");
  delay(500);
  disp.string("WRLD");
  delay(500);
  disp.string("1234");
  delay(500);
  disp.string("5678");
  delay(500);
  disp.string("90#&");
  delay(500);
}