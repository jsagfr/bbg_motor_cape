#include <iostream>
#include "MotorBridgeCape.h"
#include "Channel.h"

int main (int argc, char *argv[])
{
  MotorBridgeCape cape("/dev/i2c-1");
  cape.setChannel1(ChannelType::DcDc);
  cape.setChannel2(ChannelType::DcDc);

  cape.setDCMotorFrequency(1000);

  auto channelDcDc1 = static_cast<ChannelDcDc*>(cape.getChannel1());
  auto channelDcDc2 = static_cast<ChannelDcDc*>(cape.getChannel2());

  auto motor1A = dynamic_cast<DCMotor*>(channelDcDc1->getMotorA());
  auto motor1B = dynamic_cast<DCMotor*>(channelDcDc1->getMotorB());
  auto motor2A = dynamic_cast<DCMotor*>(channelDcDc2->getMotorA());
  auto motor2B = dynamic_cast<DCMotor*>(channelDcDc2->getMotorB());
  if (!motor1A || !motor1B || !motor2A || !motor2B)
    {
      return EXIT_FAILURE;
    }
  
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
