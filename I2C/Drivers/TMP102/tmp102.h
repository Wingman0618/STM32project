#ifndef tmp102_h
#define tmp102_h

#include <stddef.h>
#include "stm32f3xx_hal.h"

#ifndef TMP102_I2C_PORT
#define TMP102_I2C_PORT		hi2c1
#endif

#ifndef TMP102_I2C_ADDR
#define TMP102_I2C_ADDR		(0x48<<1)
#endif

#ifndef UART_PORT
#define UART_PORT			huart2
#endif

#if defined(UART_PORT)
extern	UART_HandleTypeDef	huart2;
#endif

extern I2C_HandleTypeDef TMP102_I2C_PORT;

char* getTemp();

#endif
