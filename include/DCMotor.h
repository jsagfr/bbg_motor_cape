#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include "Constants.h"
#include "I2C.h"



class DCMotor
{
protected:
  I2C* _i2cDevice;
  uint8_t const _TB_MODE;
  uint8_t const _TB_DIR;
  uint8_t const _TB_DUTY;

public:
  DCMotor(I2C* i2cDevice, uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY);
  
  void power(float power);
  void stop();
};

class DCMotor1A: public DCMotor
{
public:
  DCMotor1A(I2C* i2cDevice);
};

class DCMotor2A: public DCMotor
{
public:
  DCMotor2A(I2C* i2cDevice);
};

class DCMotor1B: public DCMotor
{
public:
  DCMotor1B(I2C* i2cDevice);
};

class DCMotor2B: public DCMotor
{
public:
  DCMotor2B(I2C* i2cDevice);
};

#endif
