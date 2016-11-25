#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstdint>
#include <chrono>

/*  */
constexpr std::chrono::milliseconds motorCapeDelay{6};
constexpr std::chrono::seconds pinCapeDelay{1};


/*  */
constexpr uint8_t READ_MODE  = 0;
constexpr uint8_t WRITE_MODE = 1;
/* constexpr uint32_t CONFIG_VALID = 0x3a6fb67c; */

/* I2C Adresse */
constexpr uint8_t motorBridgeAddr = 0x4b;

/* TB_WORKMODE */

constexpr uint8_t TB_SHORT_BREAK  = 0;
constexpr uint8_t TB_CW           = 1;
constexpr uint8_t TB_CCW          = 2;
constexpr uint8_t TB_STOP         = 3;
constexpr uint8_t TB_WORKMODE_NUM = 4;


/* TB_PORTMODE */

constexpr uint8_t TB_DCM          = 0;
constexpr uint8_t TB_SPM          = 1;
constexpr uint8_t TB_PORTMODE_NUM = 2;


/* SVM_PORT */

constexpr uint8_t SVM1            = 0;
constexpr uint8_t SVM2            = 1;
constexpr uint8_t SVM3            = 2;
constexpr uint8_t SVM4            = 3;
constexpr uint8_t SVM5            = 4;
constexpr uint8_t SVM6            = 5;
constexpr uint8_t SVM_PORT_NUM    = 6;

/* SVM_STATE */

constexpr uint8_t SVM_DISABLE     = 0;
constexpr uint8_t SVM_ENABLE      = 1;
constexpr uint8_t SVM_STATE_NUM   = 2;

/* IO_MODE */

constexpr uint8_t IO_IN           = 0;
constexpr uint8_t IO_OUT          = 1;
constexpr uint8_t IO_MODE_NUM     = 2;

/* IO_PUPD */

constexpr uint8_t IO_PU           = 0;
constexpr uint8_t IO_PD           = 1;
constexpr uint8_t IO_NP           = 2;
constexpr uint8_t IO_PUPD_NUM     = 3;

/* IO_PPOD */

constexpr uint8_t IO_PP           = 0;
constexpr uint8_t IO_OD           = 1;
constexpr uint8_t IO_PPOD_NUM     = 2;

/* IO_STATE */

constexpr uint8_t IO_LOW          = 0;
constexpr uint8_t IO_HIGH         = 1;
constexpr uint8_t IO_STATE_NUM    = 2;

/* IO_PORT */

constexpr uint8_t IO1             = 0;
constexpr uint8_t IO2             = 1;
constexpr uint8_t IO3             = 2;
constexpr uint8_t IO4             = 3;
constexpr uint8_t IO5             = 4;
constexpr uint8_t IO6             = 5;
constexpr uint8_t IO_NUM          = 6;

/* PARAM_REG */
  
constexpr uint8_t CONFIG_VALID        = 0;
constexpr uint8_t CONFIG_TB_PWM_FREQ  = CONFIG_VALID + 4;
  
constexpr uint8_t I2C_ADDRESS         = CONFIG_TB_PWM_FREQ + 4;
  
constexpr uint8_t TB_1A_MODE          = I2C_ADDRESS + 1;
constexpr uint8_t TB_1A_DIR           = TB_1A_MODE + 1;
constexpr uint8_t TB_1A_DUTY          = TB_1A_DIR + 1;
constexpr uint8_t TB_1A_SPM_SPEED     = TB_1A_DUTY + 2;
constexpr uint8_t TB_1A_SPM_STEP      = TB_1A_SPM_SPEED + 4;
  
constexpr uint8_t TB_1B_MODE          = TB_1A_SPM_STEP + 4;
constexpr uint8_t TB_1B_DIR           = TB_1B_MODE + 1;
constexpr uint8_t TB_1B_DUTY          = TB_1B_DIR + 1;
constexpr uint8_t TB_1B_SPM_SPEED     = TB_1B_DUTY + 2;
constexpr uint8_t TB_1B_SPM_STEP      = TB_1B_SPM_SPEED + 4;
  
constexpr uint8_t TB_2A_MODE          = TB_1B_SPM_STEP + 4;
constexpr uint8_t TB_2A_DIR           = TB_2A_MODE + 1;
constexpr uint8_t TB_2A_DUTY          = TB_2A_DIR + 1;
constexpr uint8_t TB_2A_SPM_SPEED     = TB_2A_DUTY + 2;
constexpr uint8_t TB_2A_SPM_STEP      = TB_2A_SPM_SPEED + 4;
  
constexpr uint8_t TB_2B_MODE          = TB_2A_SPM_STEP + 4;
constexpr uint8_t TB_2B_DIR           = TB_2B_MODE + 1;
constexpr uint8_t TB_2B_DUTY          = TB_2B_DIR + 1;
constexpr uint8_t TB_2B_SPM_SPEED     = TB_2B_DUTY + 2;
constexpr uint8_t TB_2B_SPM_STEP      = TB_2B_SPM_SPEED + 4;

constexpr uint8_t SVM1_STATE          = TB_2B_SPM_STEP + 4;
constexpr uint8_t SVM1_FREQ           = SVM1_STATE + 1;
constexpr uint8_t SVM1_ANGLE          = SVM1_FREQ + 2;
 
constexpr uint8_t SVM2_STATE          = SVM1_ANGLE + 2;
constexpr uint8_t SVM2_FREQ           = SVM2_STATE + 1;
constexpr uint8_t SVM2_ANGLE          = SVM2_FREQ + 2;
 
constexpr uint8_t SVM3_STATE          = SVM2_ANGLE + 2;
constexpr uint8_t SVM3_FREQ           = SVM3_STATE + 1;
constexpr uint8_t SVM3_ANGLE          = SVM3_FREQ + 2;
 
constexpr uint8_t SVM4_STATE          = SVM3_ANGLE + 2;
constexpr uint8_t SVM4_FREQ           = SVM4_STATE + 1;
constexpr uint8_t SVM4_ANGLE          = SVM4_FREQ + 2;
 
constexpr uint8_t SVM5_STATE          = SVM4_ANGLE + 2;
constexpr uint8_t SVM5_FREQ           = SVM5_STATE + 1;
constexpr uint8_t SVM5_ANGLE          = SVM5_FREQ + 2;
  
constexpr uint8_t SVM6_STATE          = SVM5_ANGLE + 2;
constexpr uint8_t SVM6_FREQ           = SVM6_STATE + 1;
constexpr uint8_t SVM6_ANGLE          = SVM6_FREQ + 2;

constexpr uint8_t IO1_STATE           = SVM6_ANGLE + 2;
constexpr uint8_t IO1_MODE            = IO1_STATE + 1;
constexpr uint8_t IO1_PUPD            = IO1_MODE + 1;
constexpr uint8_t IO1_PPOD            = IO1_PUPD + 1;

constexpr uint8_t IO2_STATE           = IO1_PPOD + 1;
constexpr uint8_t IO2_MODE            = IO2_STATE + 1;
constexpr uint8_t IO2_PUPD            = IO2_MODE + 1;
constexpr uint8_t IO2_PPOD            = IO2_PUPD + 1;
 
constexpr uint8_t IO3_STATE           = IO2_PPOD + 1;
constexpr uint8_t IO3_MODE            = IO3_STATE + 1;
constexpr uint8_t IO3_PUPD            = IO3_MODE + 1;
constexpr uint8_t IO3_PPOD            = IO3_PUPD + 1;
  
constexpr uint8_t IO4_STATE           = IO3_PPOD + 1;
constexpr uint8_t IO4_MODE            = IO4_STATE + 1;
constexpr uint8_t IO4_PUPD            = IO4_MODE + 1;
constexpr uint8_t IO4_PPOD            = IO4_PUPD + 1;
  
constexpr uint8_t IO5_STATE           = IO4_PPOD + 1;
constexpr uint8_t IO5_MODE            = IO5_STATE + 1;
constexpr uint8_t IO5_PUPD            = IO5_MODE + 1;
constexpr uint8_t IO5_PPOD            = IO5_PUPD + 1;
 
constexpr uint8_t IO6_STATE           = IO5_PPOD + 1;
constexpr uint8_t IO6_MODE            = IO6_STATE + 1;
constexpr uint8_t IO6_PUPD            = IO6_MODE + 1;
constexpr uint8_t IO6_PPOD            = IO6_PUPD + 1;

constexpr uint8_t PARAM_REG_NUM = IO6_PPOD + 1;

#endif
