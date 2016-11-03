#include <iostream>
#include "MotorBridgeCape.h"
#include "Channel.h"

int main (int argc, char *argv[])
{
  MotorBridgeCape cape("/dev/i2c-1");
  cape.setChannel1(ChannelType::DcDc);
  cape.setChannel2(ChannelType::DcDc);
  DCMotor* motor1A = ((ChannelDcDc*) cape.getChannel1())->getMotorA();
  DCMotor* motor1B = ((ChannelDcDc*) cape.getChannel1())->getMotorB();
  DCMotor* motor2A = ((ChannelDcDc*) cape.getChannel2())->getMotorA();
  DCMotor* motor2B = ((ChannelDcDc*) cape.getChannel2())->getMotorB();

  std::cout << "power to 0.5" << std::endl;
  
  motor1A->power(0.5);
  motor2A->power(0.5);
  motor1B->power(0.5);
  motor2B->power(0.5);

  std::cout << "stop" << std::endl;

  motor1A->stop();
  motor2A->stop();
  motor1B->stop();
  motor2B->stop();

  return 0;
}
