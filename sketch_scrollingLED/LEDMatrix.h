#include <Arduino.h>

class LEDMatrix
{
public:
  LEDMatrix(int CS, int CLK, int DIN);

  void test();

  void clear();
  void fill();
  void randomFill();
  void randomClear();

  bool isFilled();
  bool isClear();
  bool isSet(int row, int col);
  void set(int row, int col);
  void clear(int row, int col);
  void row(byte row, byte data);
  void image(byte pixels[8]);
  
private:
  int CS, CLK, DIN;
  byte map[8];

  void send(byte address, byte data);

  void show();
};


