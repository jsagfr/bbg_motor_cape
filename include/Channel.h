#ifndef CHANNEL_H
#define CHANNEL_H

#include "Constants.h"
#include "DCMotor.h"
#include "I2cDevice.h"

enum ChannelType {
  DcDc,
  Stepper,
  Unused,
};

class Channel
{
protected:
  I2cDevice* _i2cDevice;
  ChannelType _type;
  
public:
  Channel(I2cDevice* i2cDevice, ChannelType type);
  Channel();
  // virtual ~Channel() = default; // TODO(jsagfr)
  
  ChannelType getType() const;
};

class ChannelDcDc : public Channel
{
protected:
  uint8_t const _tbAMode;
  uint8_t const _tbBMode;
  uint8_t const _tbADir;
  uint8_t const _tbBDir;
  DCMotor _motorA;
  DCMotor _motorB;
  
public:
  ChannelDcDc(I2cDevice* i2cDevice,
              uint8_t tbAMode, uint8_t tbBMode,
              uint8_t tbADir, uint8_t tbBDir,
              DCMotor motorA, DCMotor motorB);
  
  DCMotor* getMotorA();
  DCMotor* getMotorB();
};

class ChannelDcDc1: public ChannelDcDc
{
public:
  ChannelDcDc1(I2cDevice* i2cDevice);
};

class ChannelDcDc2: public ChannelDcDc
{
public:
  ChannelDcDc2(I2cDevice* i2cDevice);
};

#endif
