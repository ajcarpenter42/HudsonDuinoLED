#include "ScrollingLED.h"
#include "Font8x8_P.h"
/** Pins of LED Matrix*/
#define CS   10
#define CLK  11
#define DIN  12

#define MAX 32 //max number of bytes (multiple of 8)

ScrollingLED animator = ScrollingLED(CS, CLK, DIN);
byte bytes[MAX];
int numBytes = 8;
int steps = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println(">"); //signal that Serial connected
  animator.test();
}

void printBytes()
{
  for (int row = 0; row < 8; row++)
  {
    for (int frame = 0; frame < numBytes/8; frame++)
    {
      for (int b = 8; b > 0; b--)
        Serial.write( bytes[frame*8+row] & 1 << b-1 ? 'o' : '-' );
      Serial.write(' ');
    }
    Serial.write('\n');
  }
}

void loop()
{
  if(Serial.available())
  {
    steps = 0;
    numBytes = 0;
    do
    {
      steps = appendFontChar(Serial.read(), bytes, MAX, numBytes, steps);
    } while(Serial.available() && numBytes < MAX);
    numBytes+=8;
    steps = 0;
    printBytes();
    Serial.write('\n');
  }
  steps = animator.scrollStepWiggle(bytes, numBytes, steps);
  delay(100);
}