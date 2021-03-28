#include "EcranLCD.h"

EcranLCD::EcranLCD(int rs, int en, int d4, int d5, int d6, int d7) : LiquidCrystal(rs, en, d4, d5, d6, d7)
{

  _utf8 = 0;
  _utf8_error = false;
  _unicode = 0;
}

void EcranLCD::begin()
{
  LiquidCrystal::begin(16, 2);
  delay(100);
}

void EcranLCD::refresh()
{
}

size_t EcranLCD::write(uint8_t c)
{
  if (_utf8 > 0)
  {
    _utf8--;
    if (!_utf8_error)
    {
      _unicode = (_unicode << 6) + (c & 63);
    }
    if (_utf8 == 0)
    {

      size_t answer = LiquidCrystal::write(mapUnicodeToExtASCII(_unicode));
      _unicode = 0;
      return answer;
    }
  }
  else if (c >> 3 == 30) //4 bits utf-8
  {
    _utf8 = 3;
    _unicode = c & 7;
  }
  else if (c >> 4 == 14) //3 bits utf-8
  {

    _utf8 = 2;
    _unicode = c & 15;
  }
  else if (c >> 5 == 6) //2 bits utf-8
  {
    _utf8 = 1;
    _unicode = c & 31;
  }
  else
  {
    return LiquidCrystal::write(c);
  }
  return 1;
}

uint8_t EcranLCD::mapUnicodeToExtASCII(unsigned int unicode)
{
  static unsigned int mapping[] = {
      199,
      252,
      233,
      226,
      228,
      224,
      229,
      231,
      234,
      235,
      232,
      239,
      238,
      236,
      196,
      197,
      201,
      230,
      198,
      244,
      246,
      242,
      251,
      249,
      255,
      214,
      220,
      162,
      163,
      165,
      8359,
      402,
      225,
      237,
      243,
      250,
      241,
      209,
      170,
      186,
      191,
      8976,
      172,
      189,
      188,
      161,
      171,
      187,
      9617,
      9618,
      9619,
      9474,
      9508,
      9569,
      9570,
      9558,
      9557,
      9571,
      9553,
      9559,
      9565,
      9564,
      9563,
      9488,
      9492,
      9524,
      9516,
      9500,
      9472,
      9532,
      9566,
      9567,
      9562,
      9556,
      9577,
      9574,
      9568,
      9552,
      9580,
      9575,
      9576,
      9572,
      9573,
      9561,
      9560,
      9554,
      9555,
      9579,
      9578,
      9496,
      9484,
      9608,
      9604,
      9612,
      9616,
      9600,
      945,
      223,
      915,
      960,
      931,
      963,
      181,
      964,
      934,
      920,
      937,
      948,
      8734,
      966,
      949,
      8745,
      8801,
      177,
      8805,
      8804,
      8992,
      8993,
      247,
      8776,
      176,
      8729,
      183,
      8730,
      8319,
      178,
      9632,
      160};
  for (uint8_t i = 0; i < 128; i++)
  {
    if (mapping[i] == unicode)
    {
      return i + 128;
    }
  }
  return 0;
}

void EcranLCD::ecrire(const char *msg, int x, int y, int largeur)
{

  if (y >= 0 && y < (SCREEN_HEIGHT))
  {
    writeFromBeginning(msg, x, y, largeur);
  }
}
void EcranLCD::ecrire(String msg, int x, int y, int largeur)
{

  if (y >= 0 && y < (SCREEN_HEIGHT))
  {
    writeFromBeginning(msg, x, y, largeur);
  }
}

void EcranLCD::effacer(int x, int y, int largeur)

{
  if (x < 0 || y < 0)
  {
    clear();
  }
  else
  {

    setCursor(x, y);
    for (int i = 0; i < largeur; i++)
    {
      print(' ');
    }
  }
}

void EcranLCD::writeFromBeginning(const char *msg, int x, int y, int largeur)
{
  String buffer = msg;

  EcranLCD::writeFromBeginning(buffer, x, y, largeur);
}
void EcranLCD::writeFromBeginning(String buffer, int x, int y, int largeur)
{
  setCursor(x, y);
  print(buffer);
  for (int i = buffer.length(); i < largeur; i++)
  {
    print(' ');
  }
}
