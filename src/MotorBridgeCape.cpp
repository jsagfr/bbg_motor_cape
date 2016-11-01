#include <iostream>
#include "MotorBridgeCape.h"
#include "Channel.h"
#include "I2C.h"


using namespace std;

MotorBridgeCape::MotorBridgeCape(I2C i2cDevice) :
  _i2cDevice(i2cDevice),
  _channel1(Channel()),
  _channel2(Channel())
{}

MotorBridgeCape::MotorBridgeCape(std::string i2cPath) :
  MotorBridgeCape(I2C(i2cPath))
{}
// MotorBridgeCape::MotorBridgeCape(std::string i2cPath, ChannelType channel1 = Channel::Unused, ChannelType channel2 = Channel::Unused) :
//   i2cDevice(I2C(i2cPath))
//   channel1(Channel::create(channel1, 1)),
//   channel2(Channel::create(channel2, 2)),
// {}

void MotorBridgeCape::setChannel1(ChannelType channel1)
{
  switch (channel1)
    {
    case DcDc :
      _channel1 = ChannelDcDc1(&_i2cDevice);
      break;
    case Stepper :
      break;
    default :
      break;
    }
}
void MotorBridgeCape::setChannel2(ChannelType channel2)
{
  switch (channel2)
    {
    case DcDc :
      _channel2 = ChannelDcDc2(&_i2cDevice);
      break;
    case Stepper :
      break;
    default :
      break;
    }
}

  
// MotorBridgeCape::MotorBridgeCape(string i2cdev, int dcfrequency)
// {
//   cout << i2cdev << endl;
// }

void MotorBridgeCape::setDCMotorFrequency(int frequency)
{
  cout << frequency << endl;
}

Channel* MotorBridgeCape::getChannel1()
{
  return &_channel1;
}
Channel* MotorBridgeCape::getChannel2()
{
  return &_channel2;
}

