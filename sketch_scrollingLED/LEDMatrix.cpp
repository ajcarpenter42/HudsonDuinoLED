#include "LEDMatrix.h"

//the opcodes for the MAX7221 and MAX7219
#define ADDR_DECODEMODE  9
#define ADDR_INTENSITY   10
#define ADDR_SCANLIMIT   11
#define ADDR_SHUTDOWN    12
#define ADDR_DISPLAYTEST 15



LEDMatrix::LEDMatrix(int CS, int CLK, int DIN)
  : CS(CS), CLK(CLK), DIN(DIN)
{
  pinMode(DIN, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(CS, OUTPUT);
  digitalWrite(CS, HIGH);

  // Turn on
  send(ADDR_SHUTDOWN, 1);
  // No BCD decoding
  send(ADDR_DECODEMODE, 0);
  // Medium intensity
  send(ADDR_INTENSITY, 3);
  // Use all LEDs
  send(ADDR_SCANLIMIT, 7);
  send(ADDR_DISPLAYTEST, 0);
  clear();
}

void LEDMatrix::test()
{
  send(ADDR_DISPLAYTEST, 1);
  delay(500);
  send(ADDR_DISPLAYTEST, 0);
}

void LEDMatrix::clear()
{
  memset(map, 0, sizeof(map));
  show();
}

void LEDMatrix::fill()
{
  memset(map, 0xFF, sizeof(map));
  show();
}

void LEDMatrix::randomFill()
{
  while (! isFilled())
  {
    int row = random(8);
    int col = random(8);
    if (isSet(row, col))
      continue;
    set(row, col);
    delay(10);
  }
}

void LEDMatrix::randomClear()
{
  while (! isClear())
  {
    int row = random(8);
    int col = random(8);
    if (! isSet(row, col))
      continue;
    clear(row, col);
    delay(10);
  }
}

bool LEDMatrix::isFilled()
{
  for (byte row=0; row<8; ++row)
    if (map[row] != 0xFF)
      return false;
  return true;  
}

bool LEDMatrix::isClear()
{
  for (byte row=0; row<8; ++row)
    if (map[row] != 0)
      return false;
  return true;  
}

bool LEDMatrix::isSet(int row, int col)
{
  byte mask = 1 << col;
  return (map[row] & mask) == mask;
}

void LEDMatrix::set(int row, int col)
{
  map[row] |= 1 << col;
  show();
}

void LEDMatrix::clear(int row, int col)
{
  map[row] &= ~(1 << col);
  show();
}

void LEDMatrix::row(byte row, byte data)
{
  map[row] = data;
  show();
}

void LEDMatrix::image(byte pixels[8])
{
  memcpy(map, pixels, sizeof(map));
  show();
}

void LEDMatrix::send(byte address, byte data)
{
  digitalWrite(CS, LOW);
  shiftOut(DIN, CLK, MSBFIRST, address);
  shiftOut(DIN, CLK, MSBFIRST, data);
  digitalWrite(CS,HIGH);
}

void LEDMatrix::show()
{
  for (byte row=0; row<8; ++row)
    send(row+1, map[row]);
}

