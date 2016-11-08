#include "DCMotor.h"
#include "Constants.h"
#include <iostream>
#include <cmath>
#include <cstdint>

DCMotor::DCMotor(I2cDevice* i2cDevice, uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY) :
  _i2cDevice(i2cDevice),
  _TB_MODE(TB_MODE),
  _TB_DIR(TB_DIR),
  _TB_DUTY(TB_DUTY)
{}


void DCMotor::power(float power)
{
  power = fmin( 1.0, power);
  power = fmax(-1.0, power);
  uint32_t pwmDutty = static_cast<uint32_t>(round(power * 1000.0));

  if (pwmDutty == 0) {
    stop();
  } else {
    uint8_t direction = (power > 0.0) ? TB_CW : TB_CCW;
    _i2cDevice->write(_TB_DIR, direction);
    _i2cDevice->write(_TB_DUTY, pwmDutty);
  }
}

void DCMotor::stop()
{
  _i2cDevice->write(_TB_DIR, TB_STOP);  
}


DCMotor1A::DCMotor1A(I2cDevice* i2cDevice) :
  DCMotor(i2cDevice, TB_1A_MODE, TB_1A_DIR, TB_1A_DUTY)
{}

DCMotor2A::DCMotor2A(I2cDevice* i2cDevice) :
  DCMotor(i2cDevice, TB_2A_MODE, TB_2A_DIR, TB_2A_DUTY)
{}

DCMotor1B::DCMotor1B(I2cDevice* i2cDevice) :
  DCMotor(i2cDevice, TB_1B_MODE, TB_1B_DIR, TB_1B_DUTY)
{}

DCMotor2B::DCMotor2B(I2cDevice* i2cDevice) :
  DCMotor(i2cDevice, TB_2B_MODE, TB_2B_DIR, TB_2B_DUTY)
{}

