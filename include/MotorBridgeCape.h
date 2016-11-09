#ifndef MOTOR_BRIDGE_CAPE_H
#define MOTOR_BRIDGE_CAPE_H

#include "Constants.h"
#include "Channel.h"
#include "Gpio.h"


/* enum Direction: int {A = 1, B = -1}; */


class MotorBridgeCape
{
protected:
  Gpo _resetPin;
  I2cDevice _i2cDevice;
  Channel* _channel1;
  Channel* _channel2;

 public:
  // MotorBridgeCape(unsigned int resetPin, I2cDevice i2cdev);
  // MotorBridgeCape(I2cDevice i2cdev);
  MotorBridgeCape(const std::string& i2cPath);
  ~MotorBridgeCape();

  void setChannel1(ChannelType channel1);
  void setChannel2(ChannelType channel2);
  
  
  void setDCMotorFrequency(unsigned int frequency);

  Channel* getChannel1();
  Channel* getChannel2();

};

#endif
