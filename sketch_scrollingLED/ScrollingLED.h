#include "LEDMatrix.h"

class ScrollingLED
{
  private:
    LEDMatrix matrix = LEDMatrix(10, 11, 12); //initilized for sake of compiler
    byte currBytes[8];
  public:
    ScrollingLED(int cs, int clk, int din);
    
    void fill();
    void clear();
    void test();
    void set(byte bytes[8]);
    
    void scrollInFromLeft(byte bytes[8]);
    void scrollInFromLeft(byte bytes[], int num_bytes);
    void scrollInFromRight(byte bytes[8]);
    void scrollInFromRight(byte bytes[], int num_bytes);

    int scrollStepFromRight(byte bytes [], int num_bytes, int step);
    int scrollStepFromLeft(byte bytes [], int num_bytes, int step);
    int scrollStepWiggle(byte bytes[], int num_bytes, int step);
};

ScrollingLED::ScrollingLED(int cs, int clk, int din)
{
  matrix = LEDMatrix(cs, clk, din);
  clear();
}
void ScrollingLED::fill()
{
  matrix.fill();
  for (int row = 0; row < 8; row++)
    currBytes[row] = 0xFF;
}
void ScrollingLED::clear()
{
  matrix.clear();
  for (int row = 0; row < 8; row++)
    currBytes[row] = 0;
}
void ScrollingLED::set(byte bytes[8])
{
  matrix.image(bytes);
  for (int row = 0; row < 8; row++)
    currBytes[row] = bytes[row];
}
void ScrollingLED::test()
{
  matrix.test();
  for (int row = 0; row < 8; row++)
    currBytes[row] = 0;
}
void ScrollingLED::scrollInFromLeft(byte bytes[8])
{
  for (int col = 0; col < 8; col++)
  {
    for(int row = 0; row < 8; row++)
      currBytes[row] = (currBytes[row] >> 1) | (bytes[row] << (7-col));
    delay(500);
    matrix.image(currBytes);
  }
}
void ScrollingLED::scrollInFromLeft(byte bytes[], int num_bytes)
{
  for (int fr_byte = num_bytes-8; fr_byte > -1; fr_byte-=8)
    scrollInFromLeft(bytes+fr_byte);
}
void ScrollingLED::scrollInFromRight(byte bytes[8])
{
  for (int col = 0; col < 8; col++)
  {
    for(int row = 0; row < 8; row++)
      currBytes[row] = (currBytes[row] << 1) | (bytes[row] >> (7-col));
    delay(500);
    matrix.image(currBytes);
  }
}
void ScrollingLED::scrollInFromRight(byte bytes[], int num_bytes)
{
  for (int fr_byte = 0; fr_byte < num_bytes; fr_byte+=8)
    scrollInFromRight(bytes+fr_byte);
}

int ScrollingLED::scrollStepFromLeft(byte bytes [], int num_bytes, int step = 0)
{
  step++;
  int fr_byte = ( num_bytes-8 - ((step-step%8)%num_bytes) )%num_bytes;
  for(int row = 0; row < 8; row++)
    currBytes[row] = currBytes[row] >> 1 | bytes[fr_byte+row] << (7-step%8);
  matrix.image(currBytes);
  return step;
}
int ScrollingLED::scrollStepFromRight(byte bytes [], int num_bytes, int step = 0)
{
  step++;
  int fr_byte = (step-step%8)%num_bytes;
  for(int row = 0; row < 8; row++)
    currBytes[row] = currBytes[row] << 1 | bytes[fr_byte+row] >> (7-step%8);
  matrix.image(currBytes);
  return step;
}

int ScrollingLED::scrollStepWiggle(byte bytes[], int num_bytes, int step = 0)
{
   step %= (2*num_bytes+16);

   if (step < num_bytes)
     scrollStepFromRight(bytes, num_bytes, step-1);
   else if (step < num_bytes+8)
   {
     for (int i = 0; i < 8; i++)
       currBytes[i] = currBytes[i] << 1;
     matrix.image(currBytes);
   }
   else if (step < 2*num_bytes+8)
     scrollStepFromLeft(bytes, num_bytes, step-8);
   else
   {
     for (int i = 0; i < 8; i++)
       currBytes[i] = currBytes[i] >> 1;
     matrix.image(currBytes);
   }

   step++;
   return step;
}
