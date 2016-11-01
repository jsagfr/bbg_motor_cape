#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include "Constants.h"
#include "I2C.h"



class DCMotor
{
protected:
  I2C* const i2cDevice;
  uint8_t const TB_MODE;
  uint8_t const TB_DIR;
  uint8_t const TB_DUTY;

public:
  DCMotor(I2C* i2cDevice, uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY);
  
  void power(float power);
  void stop();
};

class DCMotor1A: public DCMotor
{
public:
  DCMotor1A(I2C* i2cDevice);
};

class DCMotor2A: public DCMotor
{
public:
  DCMotor2A(I2C* i2cDevice);
};

class DCMotor1B: public DCMotor
{
public:
  DCMotor1B(I2C* i2cDevice);
};

class DCMotor2B: public DCMotor
{
public:
  DCMotor2B(I2C* i2cDevice);
};




// using namespace std;

// template <uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY>
// class DCMotor
// {
// public:
//   DCMotor(I2C interface);

//   void move(float power);
//   void stop();
// protected:
//   int frequency;
// };

// template <uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY>
// DCMotor<TB_MODE, TB_DIR, TB_DUTY>::DCMotor(I2C interface)
// {
//   cout << "coucou" << endl;
// }


// template <uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY>
// void DCMotor<TB_MODE, TB_DIR, TB_DUTY>::move(float power)
// {
//   cout << "coucou" << endl;
// }

// template <uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY>
// void DCMotor<TB_MODE, TB_DIR, TB_DUTY>::stop()
// {
//   cout << "coucou" << endl;
// }


// template <uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY>
// using DCMotor1A = DCMotor<TB_1A_MODE, TB_1A_DIR, TB_1A_DUTY>;

// template <uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY>
// using DCMotor2A = DCMotor<TB_2A_MODE, TB_2A_DIR, TB_2A_DUTY>;

// template <uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY>
// using DCMotor1B = DCMotor<TB_1B_MODE, TB_1B_DIR, TB_1B_DUTY>;

// template <uint8_t TB_MODE, uint8_t TB_DIR, uint8_t TB_DUTY>
// using DCMotor2B = DCMotor<TB_2B_MODE, TB_2B_DIR, TB_2B_DUTY>;

#endif
