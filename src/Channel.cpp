#include <thread>
#include "Channel.h"
#include "Constants.h"
#include "I2cDevice.h"
#include "DCMotor.h"


Channel::Channel(I2cDevice* i2cDevice, ChannelType type) :
  _i2cDevice(i2cDevice),
  _type(type)
{}

Channel::Channel() :
  Channel(nullptr, ChannelType::Unused)
{}

ChannelType Channel::getType() const
{
  return _type;
};

ChannelDcDc::ChannelDcDc(I2cDevice* i2cDevice,
                         uint8_t tbAMode, uint8_t tbBMode,
                         uint8_t tbADir, uint8_t tbBDir,
                         DCMotor motorA, DCMotor motorB) :
  Channel(i2cDevice, ChannelType::DcDc),
  _tbAMode(tbAMode), _tbBMode(tbBMode),
  _tbADir(tbADir), _tbBDir(tbBDir),
  _motorA(motorA), _motorB(motorB)
{
  uint8_t d[] = {WRITE_MODE, _tbAMode, TB_DCM};
  _i2cDevice->write(d, 3);
  std::this_thread::sleep_for(motorCapeDelay);
  
  d[1] = _tbADir; d[2] = TB_STOP;
  _i2cDevice->write(d, 3);
  std::this_thread::sleep_for(motorCapeDelay);

  d[1] = _tbBMode; d[2] = TB_DCM;
  _i2cDevice->write(d, 3);
  std::this_thread::sleep_for(motorCapeDelay);

  d[1] = _tbBDir; d[2] = TB_STOP;
  _i2cDevice->write(d, 3);
  std::this_thread::sleep_for(motorCapeDelay);
}

DCMotor* ChannelDcDc::getMotorA()
{
  return &_motorA;
}

DCMotor* ChannelDcDc::getMotorB()
{
  return &_motorB;
}

ChannelDcDc1::ChannelDcDc1(I2cDevice* i2cDevice) :
  ChannelDcDc(i2cDevice,
              TB_1A_MODE, TB_1B_MODE,
              TB_1A_DIR, TB_1B_DIR,
              DCMotor1A(i2cDevice), DCMotor1B(i2cDevice))
{}

ChannelDcDc2::ChannelDcDc2(I2cDevice* i2cDevice) :
  ChannelDcDc(i2cDevice,
              TB_2A_MODE, TB_2B_MODE,
              TB_2A_DIR, TB_2B_DIR,
              DCMotor2A(i2cDevice), DCMotor2A(i2cDevice))
{}

