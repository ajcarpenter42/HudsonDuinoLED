//author: Amanda Carpenter

//A font table utility for an 8x8 LED

//=================font table======================
//..............(methods below)....................
//The last 5 bits of each const byte represent a 5x5
//pixel array for the character, right-justified.

//The first three bits represent the width,
//of the character (binary base). The values
//6 (110) and 7 (111) indicate 2- and 3-pixel
//characters, respectively, with a descender, e.g.
//g, y, j. 000 has no defined meaning.

#include <avr/pgmspace.h>

const PROGMEM byte font_sp [5] =
  {
    0b00100000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000
  };

const PROGMEM byte font_ex [5] =
  {
    0b00100001,
    0b00000001,
    0b00000001,
    0b00000000,
    0b00000001
  };

const PROGMEM byte font_qt [5] =
  {
    0b01100101,
    0b00000101,
    0b00000000,
    0b00000000,
    0b00000001
  };

const PROGMEM byte font_num [5] =
  {
    0b10101010,
    0b00011111,
    0b00001010,
    0b00011111,
    0b00001010
  };

const PROGMEM byte font_dol [5] =
  {
    0b10000111,
    0b00001010,
    0b00000110,
    0b00000011,
    0b00001110
  };

const PROGMEM byte font_pct [5] =
  {
    0b10111001,
    0b00011010,
    0b00000100,
    0b00001011,
    0b00010011
  };

const PROGMEM byte font_and [5] =
  {
    0b10000100,
    0b00001010,
    0b00000100,
    0b00001011,
    0b00001101
  };

const PROGMEM byte font_apos [5] =
  {
    0b00100001,
    0b00000001,
    0b00000000,
    0b00000000,
    0b00000000
  };

const PROGMEM byte font_paren1 [5] =
  {
    0b01000001,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00000001
  };

const PROGMEM byte font_paren2 [5] =
  {
    0b01000010,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000010
  };

const PROGMEM byte font_dash [5] =
  {
    0b01100000,
    0b00000000,
    0b00000111,
    0b00000000,
    0b00000000
  };

const PROGMEM byte font_dot [5] =
  {
    0b00100000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000001
  };

const PROGMEM byte font_slash [5] =
  {
    0b10100001,
    0b00000010,
    0b00000100,
    0b00001000,
    0b00010000
  };

const byte PROGMEM font_0 [5] =
  {
    0b01100010,
    0b00000101,
    0b00000101,
    0b00000101,
    0b00000010
  };

const byte PROGMEM font_1 [5] =
  {
    0b01100010,
    0b00000110,
    0b00000010,
    0b00000010,
    0b00000111
  };

const byte PROGMEM font_2 [5] =
  {
    0b01100111,
    0b00000001,
    0b00000011,
    0b00000100,
    0b00000111
  };

const byte PROGMEM font_3 [5] =
  {
    0b01100111,
    0b00000001,
    0b00000111,
    0b00000001,
    0b00000111
  };

const byte PROGMEM font_4 [5] =
  {
    0b01100101,
    0b00000101,
    0b00000111,
    0b00000001,
    0b00000001
  };

const byte PROGMEM font_5 [5] =
  {
    0b01100111,
    0b00000100,
    0b00000110,
    0b00000001,
    0b00000110
  };

const byte PROGMEM font_6 [5] =
  {
    0b01100111,
    0b00000100,
    0b00000111,
    0b00000101,
    0b00000111
  };

const byte PROGMEM font_7 [5] =
  {
    0b01100111,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001
  };

const byte PROGMEM font_8 [5] =
  {
    0b01100111,
    0b00000101,
    0b00000111,
    0b00000101,
    0b00000111
  };

const byte PROGMEM font_9 [5] =
  {
    0b01100111,
    0b00000101,
    0b00000111,
    0b00000001,
    0b00000111
  };

const byte PROGMEM font_A [5] =
  {
    0b01100010,
    0b00000101,
    0b00000111,
    0b00000101,
    0b00000101
  };

const byte PROGMEM font_B [5] =
  {
    0b01100110,
    0b00000101,
    0b00000110,
    0b00000101,
    0b00000110
  };
  
const byte PROGMEM font_C [5] =
  {
    0b01100011,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000011
  };
  
const byte PROGMEM font_D [5] =
  {
    0b10001110,
    0b00001001,
    0b00001001,
    0b00001001,
    0b00001110
  };
  
const byte PROGMEM font_E [5] =
  {
    0b01100111,
    0b00000100,
    0b00000111,
    0b00000100,
    0b00000111
  };

const byte PROGMEM font_F [5] =
  {
    0b01100111,
    0b00000100,
    0b00000110,
    0b00000100,
    0b00000100
  };
  
const byte PROGMEM font_G [5] =
  {
    0b10000111,
    0b00001000,
    0b00001011,
    0b00001001,
    0b00000111
  };

const byte PROGMEM font_H [5] =
  {
    0b01100101,
    0b00000101,
    0b00000111,
    0b00000101,
    0b00000101
  };

const byte PROGMEM font_I [5] =
  {
    0b01100111,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00000111
  };

const byte PROGMEM font_J [5] =
  {
    0b01100111,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00000110
  };

const byte PROGMEM font_K [5] =
  {
    0b01100101,
    0b00000101,
    0b00000110,
    0b00000101,
    0b00000101
  };

const byte PROGMEM font_L [5] =
  {
    0b01100100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000111
  };

const byte PROGMEM font_M [5] =
  {
    0b10110001,
    0b00011011,
    0b00010101,
    0b00010001,
    0b00010001
  };

const byte PROGMEM font_N [5] =
  {
    0b10001001,
    0b00001101,
    0b00001011,
    0b00001011,
    0b00001001
  };

const byte PROGMEM font_O [5] =
  {
    0b10001111,
    0b00001001,
    0b00001001,
    0b00001001,
    0b00001111
  };

const byte PROGMEM font_P [5] =
  {
    0b01100111,
    0b00000101,
    0b00000111,
    0b00000100,
    0b00000100
  };

const byte PROGMEM font_Q [5] =
  {
    0b10001110,
    0b00001010,
    0b00001010,
    0b00001010,
    0b00000111
  };

const byte PROGMEM font_R [5] =
  {
    0b01100110,
    0b00000101,
    0b00000110,
    0b00000101,
    0b00000101
  };

const byte PROGMEM font_S [5] =
  {
    0b01100011,
    0b00000100,
    0b00000011,
    0b00000001,
    0b00000110
  };

const byte PROGMEM font_T [5] =
  {
    0b01100111,
    0b00000010,
    0b00000010,
    0b00000010,
    0b00000010
  };

const byte PROGMEM font_U [5] =
  {
    0b01100101,
    0b00000101,
    0b00000101,
    0b00000101,
    0b00000111
  };

const byte PROGMEM font_V [5] =
  {
    0b01100101,
    0b00000101,
    0b00000101,
    0b00000101,
    0b00000010
  };

const byte PROGMEM font_W [5] =
  {
    0b10110001,
    0b00010001,
    0b00010101,
    0b00010101,
    0b00001010
  };

const byte PROGMEM font_X [5] =
  {
    0b01100101,
    0b00000101,
    0b00000010,
    0b00000101,
    0b00000101
  };

const byte PROGMEM font_Y [5] =
  {
    0b01100101,
    0b00000101,
    0b00000010,
    0b00000010,
    0b00000010
  };

const byte PROGMEM font_Z [5] =
  {
    0b01100111,
    0b00000001,
    0b00000010,
    0b00000100,
    0b00000111
  };

const byte PROGMEM font_a [5] =
  {
    0b01100000,
    0b00000111,
    0b00000001,
    0b00000111,
    0b00000111
  };

const byte PROGMEM font_b [5] =
  {
    0b01100100,
    0b00000100,
    0b00000111,
    0b00000101,
    0b00000111
  };

const byte PROGMEM font_c [5] =
  {
    0b01100000,
    0b00000000,
    0b00000111,
    0b00000100,
    0b00000111
  };

const byte PROGMEM font_d [5] =
  {
    0b01100001,
    0b00000001,
    0b00000111,
    0b00000101,
    0b00000111
  };

const byte PROGMEM font_e [5] =
  {
    0b01100000,
    0b00000111,
    0b00000111,
    0b00000100,
    0b00000111
  };

const byte PROGMEM font_f [5] =
  {
    0b01100011,
    0b00000010,
    0b00000111,
    0b00000010,
    0b00000010
  };

const byte PROGMEM font_g [5] =
  {
    0b11100111,
    0b00000101,
    0b00000111,
    0b00000001,
    0b00000111
  };

const byte PROGMEM font_h [5] =
  {
    0b01100100,
    0b00000100,
    0b00000111,
    0b00000101,
    0b00000101
  };

const byte PROGMEM font_i [5] =
  {
    0b00100000,
    0b00000001,
    0b00000000,
    0b00000001,
    0b00000001
  };

const byte PROGMEM font_j [5] =
  {
    0b11000001,
    0b00000000,
    0b00000001,
    0b00000001,
    0b00000011
  };

const byte PROGMEM font_k [5] =
  {
    0b01100100,
    0b00000101,
    0b00000110,
    0b00000101,
    0b00000101
  };

const byte PROGMEM font_l [5] =
  {
    0b00100001,
    0b00000001,
    0b00000001,
    0b00000001,
    0b00000001
  };

const byte PROGMEM font_m [5] =
  {
    0b10100000,
    0b00000000,
    0b00011011,
    0b00010101,
    0b00010101
  };

const byte PROGMEM font_n [5] =
  {
    0b10000000,
    0b00000000,
    0b00001011,
    0b00001101,
    0b00001001
  };

const byte PROGMEM font_o [5] =
  {
    0b01100000,
    0b00000000,
    0b00000111,
    0b00000101,
    0b00000111
  };

const byte PROGMEM font_p [5] =
  {
    0b11100111,
    0b00000101,
    0b00000111,
    0b00000100,
    0b00000100
  };

const byte PROGMEM font_q [5] =
  {
    0b11100111,
    0b00000101,
    0b00000111,
    0b00000001,
    0b00000001
  };

const byte PROGMEM font_r [5] =
  {
    0b01100000,
    0b00000000,
    0b00000111,
    0b00000100,
    0b00000100
  };

const byte PROGMEM font_s [5] =
  {
    0b01100000,
    0b00000111,
    0b00000110,
    0b00000001,
    0b00000111
  };

const byte PROGMEM font_t [5] =
  {
    0b01100010,
    0b00000010,
    0b00000111,
    0b00000010,
    0b00000011
  };

const byte PROGMEM font_u [5] =
  {
    0b01100000,
    0b00000000,
    0b00000101,
    0b00000101,
    0b00000111
  };

const byte PROGMEM font_v [5] =
  {
    0b01100000,
    0b00000000,
    0b00000101,
    0b00000101,
    0b00000010
  };

const byte PROGMEM font_w [5] =
  {
    0b10100000,
    0b00000000,
    0b00010001,
    0b00010101,
    0b00001010
  };

const byte PROGMEM font_x [5] =
  {
    0b01100000,
    0b00000000,
    0b00000101,
    0b00000010,
    0b00000101
  };

const byte PROGMEM font_y [5] =
  {
    0b11100101,
    0b00000101,
    0b00000111,
    0b00000001,
    0b00000111
  };

const byte PROGMEM font_z [5] =
  {
    0b10000000,
    0b00001111,
    0b00000010,
    0b00000100,
    0b00001111
  };

const byte PROGMEM smiley [5] =
  {
    0b10101010,
    0b00001010,
    0b00000000,
    0b00010001,
    0b00001110
  };

const byte* fonts [] = //contains PROGMEM addresses
{
  font_sp, font_ex, font_qt, font_num, font_dol, font_pct, font_and, font_apos, font_paren1, font_paren2,
  font_dash, font_dot, font_slash, font_0, font_1, font_2, font_3, font_4, font_5, font_6, font_7, font_8, font_9,
  font_A, font_B, font_C,font_D, font_E, font_F, font_G, font_H, font_I, font_J, font_K, font_L, font_M,
  font_N, font_O, font_P, font_Q, font_R, font_S, font_T, font_U, font_V, font_W, font_X, font_Y, font_Z,
  font_a, font_b, font_c, font_d, font_e, font_f, font_g, font_h, font_i, font_j, font_k, font_l, font_m,
  font_n, font_o, font_p, font_q, font_r, font_s, font_t, font_u, font_v, font_w, font_x, font_y, font_z
};

//==================function headers==================
/** @return A pointer to the 5-byte representation of 'c'*/
const byte* getFont(char c);

/** Translates string into pixels written in the given buffer 'buff'
    so that each byte is a row of 8 pixels and each 8-byte block
    is one 8x8 frame, read top-down and left-to-right.

    Most characters are 4 bits wide with spacing, so two char can
    usually be represented in 8 bytes.

   @return: number of columns (bits per row) occupied in last frame
   @post: 'str' has been translated into pixels stored in 'buff',
   truncated if necessary to a max. length of 'maxNumBytes' bytes,
   and 'numBytes' holds the number of elements in the buffer. */
byte getFontBytes(char str [], int len, byte buff [], int maxNumBytes, int& numBytes);

/** A utility for appending chars to a partially complete font byte array.
    @return: number of columns (bits per row) occupied in last frame
    @pre: numBytes should be the number of FULLY FILLED bytes,
    or 8 less than the number of elements in the buffer
    @post: numBytes is 8 less than the number of elements*/
byte appendFontChar(char c, byte buff[], int maxNumBytes, int &numBytes, byte col);

//====================function defs================
//characters: ' ' thru ')', '-' thru '9', 'A' thru 'Z', 'a' thru 'z'; and '@' = smiley
const byte* getFont(char c)
{
  if (c == '@')
    return smiley;
  if (c > 'z')
    c = 0;
  if (c >= 'a')
    c -= ('a' - 'Z' - 1);
  if (c >= 'A')
    c -= ('A' - '9' - 1);
  if (c >= '-')
    c -= ('-' - ')' - 1);
  if (c > ' ')
    c -= ' ';
  else
    c = 0;
  return fonts[c]; //if fonts in PROGMEM: pgm_read_ptr_near(fonts+c);
}

byte getFontBytes(char str [], int len, byte buff [], int maxNumBytes, int& numBytes)
{
  for (int i = 1; i < 8; i++)
    buff[i] = 0;
  numBytes = 0;
  byte col = 0;
  
  for (int i = 0; i < len; i++)
    col = appendFontChar(str[i], buff, maxNumBytes, numBytes, col);

  if (numBytes+8 <= maxNumBytes)
    numBytes+=8;

  return col;
}

byte appendFontChar(char c, byte buff [], int maxNumBytes, int &numBytes, byte col)
{
    if (numBytes >= maxNumBytes) return col;

    const byte* font = getFont(c);

    //interpret first 3 bits
    byte w = pgm_read_byte_near(font + 0) >> 5;
    byte rows; //number of (blank) top rows
    if (w > 5)
    {
      w -= 4;
      rows = w;
    }
    else
      rows = 1;
    col += w;

    //loop through the current frame
    for (int row = 0; row < 8; row++)
    {
      //mask area under and right of new font character
      if (col-w == 0)
        buff[numBytes+row] = 0;
      else if ((col-w) < 9)
        buff[numBytes+row] &= (0xFF << 9-(col-w));

      //add font rows
      if (row-rows > -1 && row-rows < 5)
      {
        if (col > 8)
        {
          if (numBytes+row+8 < maxNumBytes)
          {
            buff[numBytes+row] |= ( pgm_read_byte_near(font + row-rows) & 0x1F ) >> (col-8);
            buff[numBytes+row+8] = (pgm_read_byte_near(font + row-rows) & 0x1F) << (16-col);
          }
        }
        else
          buff[numBytes+row] |= ( pgm_read_byte_near(font + row-rows) & 0x1F ) << (8-col);
      }
      else if (col > 8 && numBytes+row+8 < maxNumBytes)
      {
        buff[numBytes+row+8] = 0;
      }
    }

    //adjust col and numBytes
    if (col > 8 && numBytes+15 < maxNumBytes)
    {
      col -= 8;
      numBytes+=8;
    }
    else if (col > 8)
    {
      return 0;
    }
    col++;
    return col;
}
