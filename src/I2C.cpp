#include "I2C.h"
#include <cstdint>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

I2C::I2C(string path)
{
  cout << "i2c: " << path << endl;
}
  
void I2C::write(uint8_t reg, uint8_t data)
{
  cout << internal // fill between the prefix and the number
       << setfill('0'); // fill with 0s
  cout << "reg: " << hex << setw(2) << static_cast<int>(reg) << " byte: " << hex << setw(2) << static_cast<int>(data) << endl;
}

void I2C::write(uint8_t reg, uint16_t data)
{
  cout << internal // fill between the prefix and the number
       << setfill('0'); // fill with 0s
  cout << "reg: " << hex << setw(2) << static_cast<int>(reg) << " halfword: " << hex << setw(4) << data << endl;
}

void I2C::write(uint8_t reg, uint32_t data)
{
  cout << internal // fill between the prefix and the number
       << setfill('0'); // fill with 0s
  cout << "reg: " << hex << setw(2) << static_cast<int>(reg) << " word: " << hex << setw(8) << data << endl;
}
