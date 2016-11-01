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
  ChannelType type;
  I2C* i2cDevice;
  
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



// template <uint8_t TB_A_MODE, uint8_t TB_B_MODE, uint8_t TB_A_DIR, uint8_t TB_B_DIR>
// class ChannelDCDC: Channel
// {
// public:
//   ChannelDCDC();

//   void applyConfig();
  
// };

// template <uint8_t TB_A_MODE, uint8_t TB_B_MODE, uint8_t TB_A_DIR, uint8_t TB_B_DIR>
// using Channel1 = Channel<uint8_t TB_1A_MODE, uint8_t TB_1B_MODE, uint8_t TB_1A_DIR, uint8_t TB_1B_DIR>;

// template <uint8_t TB_A_MODE, uint8_t TB_B_MODE, uint8_t TB_A_DIR, uint8_t TB_B_DIR>
// using Channel2 = Channel<uint8_t TB_2A_MODE, uint8_t TB_2B_MODE, uint8_t TB_2A_DIR, uint8_t TB_2B_DIR>;

// class ChannelStepper: Channel
// {
// public:
//   ChannelStepper();

//   void applyConfig();
// };

#endif
