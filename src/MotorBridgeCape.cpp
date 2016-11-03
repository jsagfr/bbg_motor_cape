#include <iostream>
#include "MotorBridgeCape.h"
#include "Channel.h"
#include "I2C.h"


using namespace std;

MotorBridgeCape::MotorBridgeCape(I2C i2cDevice) :
  _i2cDevice(i2cDevice),
  _channel1(nullptr),
  _channel2(nullptr)
{
  _channel1 = new Channel();
  _channel2 = new Channel();
}

MotorBridgeCape::MotorBridgeCape(std::string i2cPath) :
  MotorBridgeCape(I2C(i2cPath))
{}

MotorBridgeCape::~MotorBridgeCape()
{
  if (_channel1) {
    delete[] _channel1;
  }
  if (_channel2) {
    delete[] _channel2;
  }
}


void MotorBridgeCape::setChannel1(ChannelType channel1)
{
  if (_channel1) {
    delete[] _channel1;
  }
  switch (channel1)
    {
    case DcDc :
      _channel1 = new ChannelDcDc1(&_i2cDevice);
      break;
    case Stepper :
      break;
    default :
      _channel1 = new Channel();
      break;
    }
}
void MotorBridgeCape::setChannel2(ChannelType channel2)
{
  if (_channel2) {
    delete[] _channel2;
  }
  switch (channel2)
    {
    case DcDc :
      _channel2 = new ChannelDcDc2(&_i2cDevice);
      break;
    case Stepper :
      break;
    default :
      _channel2 = new Channel();
      break;
    }
}

void MotorBridgeCape::setDCMotorFrequency(int frequency)
{
  cout << frequency << endl;
}

Channel* MotorBridgeCape::getChannel1()
{
  return _channel1;
}
Channel* MotorBridgeCape::getChannel2()
{
  return _channel2;
}

