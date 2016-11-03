#include "Channel.h"
#include "Constants.h"
#include "I2C.h"
#include "DCMotor.h"


Channel::Channel(I2C* i2cDevice, ChannelType type) :
  i2cDevice(i2cDevice),
  type(type)
{}

Channel::Channel() :
  Channel(nullptr, ChannelType::Unused)
{}

ChannelType Channel::getType()
{
  return type;
};

ChannelDcDc::ChannelDcDc(I2C* i2cDevice,
                         uint8_t tbAMode, uint8_t tbBMode,
                         uint8_t tbADir, uint8_t tbBDir,
                         DCMotor motorA, DCMotor motorB) :
  Channel(i2cDevice, ChannelType::DcDc),
  tbAMode(tbAMode), tbBMode(tbBMode),
  tbADir(tbADir), tbBDir(tbBDir),
  _motorA(motorA), _motorB(motorB)
{
  this->i2cDevice->write(tbAMode, TB_DCM);
  this->i2cDevice->write(tbADir, TB_STOP);
  this->i2cDevice->write(tbBMode, TB_DCM);
  this->i2cDevice->write(tbBDir, TB_STOP);
}

DCMotor* ChannelDcDc::getMotorA()
{
  return &_motorA;
}

DCMotor* ChannelDcDc::getMotorB()
{
  return &_motorB;
}

ChannelDcDc1::ChannelDcDc1(I2C* i2cDevice) :
  ChannelDcDc(i2cDevice,
              TB_1A_MODE, TB_1B_MODE,
              TB_1A_DIR, TB_1B_DIR,
              DCMotor1A(i2cDevice), DCMotor1B(i2cDevice))
{}

ChannelDcDc2::ChannelDcDc2(I2C* i2cDevice) :
  ChannelDcDc(i2cDevice,
              TB_2A_MODE, TB_2B_MODE,
              TB_2A_DIR, TB_2B_DIR,
              DCMotor2A(i2cDevice), DCMotor2A(i2cDevice))
{}

