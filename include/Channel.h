#ifndef CHANNEL_H
#define CHANNEL_H

#include "Constants.h"
#include "DCMotor.h"
#include "I2C.h"

enum ChannelType {
  DcDc,
  Stepper,
  Unused,
};

class Channel
{
protected:
  I2C* i2cDevice;
  ChannelType type;
  
public:
  Channel(I2C* i2cDevice, ChannelType type);
  Channel();
  
  ChannelType getType();
};

class ChannelDcDc : public Channel
{
protected:
  uint8_t const tbAMode;
  uint8_t const tbBMode;
  uint8_t const tbADir;
  uint8_t const tbBDir;
  DCMotor _motorA;
  DCMotor _motorB;
  
public:
  ChannelDcDc(I2C* i2cDevice,
              uint8_t tbAMode, uint8_t tbBMode,
              uint8_t tbADir, uint8_t tbBDir,
              DCMotor motorA, DCMotor motorB);
  
  DCMotor* getMotorA();
  DCMotor* getMotorB();
};

class ChannelDcDc1: public ChannelDcDc
{
public:
  ChannelDcDc1(I2C* i2cDevice);
};

class ChannelDcDc2: public ChannelDcDc
{
public:
  ChannelDcDc2(I2C* i2cDevice);
};

#endif
