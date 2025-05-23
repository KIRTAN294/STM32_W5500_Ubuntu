/*
 * tcp_server.c
 *
 *  Created on: May 23, 2025
 *      Author: kirtan
 */
#include "main.h"
#include "tcp_server.h"
#include "socket.h"

extern SPI_HandleTypeDef hspi2;
volatile uint8_t spiTxComplete = 1;
volatile uint8_t spiRxComplete = 1;

wiz_NetInfo netInfo={

		.mac = {0x02, 0x00, 0x00, 0x00, 0x00, 0x01},
		.ip = {176,162,10,1},
		.sn = {255,255,255,0},
		.dns = {0,0,0,0},
		.dhcp = NETINFO_STATIC

};
void W5500_Select(void)
{
    HAL_GPIO_WritePin(CS_PIN_GPIO_Port,CS_PIN_Pin,GPIO_PIN_RESET);
}

void W5500_Unselect(void)
{
    HAL_GPIO_WritePin(CS_PIN_GPIO_Port, CS_PIN_Pin, GPIO_PIN_SET);
}

uint8_t W5500_ReadByte(void)
{
    uint8_t byte;
    HAL_SPI_Receive(&hspi2, &byte, 1, HAL_MAX_DELAY);
    return byte;
}
void W5500_WriteByte(uint8_t byte)

{
    HAL_SPI_Transmit(&hspi2, &byte, 1, HAL_MAX_DELAY);
}

void W5500_ReadBuff(uint8_t* buff, uint16_t len)
{
	 spiRxComplete = 0;
    HAL_SPI_Receive_DMA(&hspi2, buff, len);
    while(HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);

}
void W5500_WriteBuff(uint8_t* buff, uint16_t len)
{
	 spiTxComplete = 0;
    HAL_SPI_Transmit_DMA(&hspi2, buff, len);
    while(HAL_SPI_GetState(&hspi2) != HAL_SPI_STATE_READY);

}
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if(hspi->Instance == SPI2)
    {
    	 spiTxComplete = 1;
    }
}
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if(hspi->Instance == SPI2)
    {
    	 spiRxComplete = 1;
    }
}
void W5500_Init(){


	HAL_GPIO_WritePin(RST_PIN_GPIO_Port,RST_PIN_Pin,GPIO_PIN_RESET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(RST_PIN_GPIO_Port,RST_PIN_Pin,GPIO_PIN_SET);

    reg_wizchip_cs_cbfunc(W5500_Select, W5500_Unselect);
    reg_wizchip_spi_cbfunc(W5500_ReadByte, W5500_WriteByte);
    reg_wizchip_spiburst_cbfunc(W5500_ReadBuff, W5500_WriteBuff);

    uint8_t memsize[2][8] = {{2,2,2,2,2,2,2,2}, {2,2,2,2,2,2,2,2}};
    if(wizchip_init(memsize[0], memsize[1]) < 0)
    {
    	Error_Handler();
    }

}

