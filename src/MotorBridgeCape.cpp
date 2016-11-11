#include <iostream>
#include <thread>
#include "MotorBridgeCape.h"
#include "Constants.h"
#include "Channel.h"
#include "I2cDevice.h"
#include "Gpio.h"
#include "BeagleBone.h"


using namespace std;

MotorBridgeCape::MotorBridgeCape(const std::string& i2cPath) :
  _resetPin(P9_23),
  _i2cDevice(i2cPath, motorBridgeAddr),
  _channel1(nullptr),
  _channel2(nullptr)
{
  _channel1 = new Channel();
  _channel2 = new Channel();
  _resetPin.setHigh();
  std::this_thread::sleep_for(motorCapeDelay);
}

MotorBridgeCape::~MotorBridgeCape()
{
  if (_channel1) {
    delete[] _channel1;
  }
  if (_channel2) {
    delete[] _channel2;
  }
  // Seems natural but it does not appears in the ptyhon version:
  // _resetPin.setLow();
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

void MotorBridgeCape::setDCMotorFrequency(uint16_t frequency)
{
  char * buf = reinterpret_cast<char *>(&frequency);
  uint16_t f = (buf[0] >> 8) + buf[1];
  _i2cDevice.write(CONFIG_TB_PWM_FREQ, f);
  std::this_thread::sleep_for(motorCapeDelay);
}

Channel* MotorBridgeCape::getChannel1()
{
  return _channel1;
}
Channel* MotorBridgeCape::getChannel2()
{
  return _channel2;
}

