#include "DCMotor.h"
#include "Constants.h"
#include <thread>
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
  int32_t pwmDutty = static_cast<int32_t>(round(power * 1000.0));
  char * src_p = reinterpret_cast<char *>(&pwmDutty);
  
  if (pwmDutty == 0) {
    stop();
  } else {
    uint8_t direction = (power > 0.0) ? TB_CW : TB_CCW;
    uint8_t d[] = {WRITE_MODE, _TB_DIR, direction};
    _i2cDevice->write(d, 3);
    std::this_thread::sleep_for(motorCapeDelay);
    uint8_t p[] = {WRITE_MODE, _TB_DUTY,
		   src_p[0], src_p[1], src_p[2], src_p[3]};
    _i2cDevice->write(p, 6);
    std::this_thread::sleep_for(motorCapeDelay);
  }
}

void DCMotor::stop()
{
  uint8_t d[] = {WRITE_MODE, _TB_DIR, TB_STOP};
  _i2cDevice->write(d, 3);
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

