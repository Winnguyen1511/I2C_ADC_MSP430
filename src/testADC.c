#include <stdio.h>
#include <unistd.h>
#include "I2CRpi.h"
#define     MSP430_ADDRESS     0x48
uint8_t RxBuffer[2] = {0};
uint8_t TxBuffer[1] = {'a'};
int main(int argc, char**argv)
{
    int i, fd;
    I2C_t hi2c;
    HAL_I2C_Init(&hi2c, 0);
    for(i = 0; ; i++)
    {
        I2C_Master_Transmit(&hi2c, MSP430_ADDRESS,TxBuffer, 1 );

        I2C_Master_Receive(&hi2c, MSP430_ADDRESS, RxBuffer, 2);
        uint16_t upper, lower;
        upper = RxBuffer[0];
        lower = RxBuffer[1];
        uint16_t tempRaw = (upper << 4) + lower;
        printf("TempRaw=%d\n", tempRaw);
        sleep(1);
    }
    return 0;
}