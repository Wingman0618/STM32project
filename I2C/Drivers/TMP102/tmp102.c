#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <tmp102.h>

static const uint8_t REG_TEMP = 0x00;

uint8_t buf[12];
uint16_t val;

char temp[4];

float temp_c;

char* getTemp(void){
	buf[0] = REG_TEMP;
	HAL_I2C_Master_Transmit(&TMP102_I2C_PORT, TMP102_I2C_ADDR, buf, 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(&TMP102_I2C_PORT, TMP102_I2C_ADDR, buf, 2, HAL_MAX_DELAY);

	val = ((int16_t)buf[0]<<4 | buf[1]>>4);
	if(val > 0x7Ff){
		val |= 0xF000;
	}

	temp_c = val * 0.0625;

	temp_c *= 100;

	sprintf((char*)buf, "%u.%uC", ((unsigned int)temp_c / 100),((unsigned int)temp_c % 100));

//	HAL_UART_Transmit(&huart2, buf, strlen((char*)buf), HAL_MAX_DELAY);
//	gcvt(temp_c, 3, temp);

	return (char*)buf;
}
