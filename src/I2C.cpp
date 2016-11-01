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
  cout << "reg: " << hex << static_cast<int>(reg) << " data: " << hex << static_cast<int>(data) << endl;
}

void I2C::write(uint8_t reg, uint16_t data)
{
  cout << "reg: " << hex << static_cast<int>(reg) << " data: " << hex << static_cast<int>(data) << endl;
}

void I2C::write(uint8_t reg, uint32_t data)
{
  cout << "reg: " << hex << static_cast<int>(reg) << " data: " << hex << static_cast<int>(data) << endl;
}

