#ifndef I2C_H
#define I2C_H

#include <cstdint>
#include <string>

class I2C
{
private:
  const std::string path;
  
public:
  I2C(std::string path);
  
  void write(uint8_t reg, uint8_t data);
  void write(uint8_t reg, uint16_t data);
  void write(uint8_t reg, uint32_t data);
};

#endif
