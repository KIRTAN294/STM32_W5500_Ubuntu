/*
 * tcp_server.c
 *
 *  Created on: May 23, 2025
 *      Author: kirtan
 */
#include "main.h"
#include "tcp_server.h"
#include "socket.h"
#include <stdint.h>
#include "dhcp.h"
#include "wizchip_conf.h"

extern SPI_HandleTypeDef hspi1;
volatile uint8_t spiTxComplete = 1;
volatile uint8_t spiRxComplete = 1;

uint8_t dhcp_buffer[1024];
//uint8_t S_ADDR[4] = {176,162,10,2};  // IP of PC server
//uint16_t S_PORT = 6565;
wiz_NetInfo netInfo={

		.mac = {0x02, 0x00, 0x00, 0x00, 0x00, 0x01},
		.ip = {176,162,10,1},
		.sn = {255,255,255,0},
		.dns = {0,0,0,0},
		.dhcp = NETINFO_STATIC

};
//wiz_NetInfo netInfo={
//
//
//	 .mac = {0x02, 0x34, 0x40, 0x18, 0x30, 0x67},
//	 .dhcp = NETINFO_DHCP
//
//};
//void tcp_server_host(void){
//
//	DHCP_init(DHCP_SOCKET, dhcp_buffer);
//
//
////	reg_dhcp_cbfunc(my_ip_assign, my_ip_update, my_ip_conflict);
//
//	uint8_t dhcp_ret;
//	do {
//	    dhcp_ret = DHCP_run();
//	} while (dhcp_ret != DHCP_IP_LEASED);
//
//	getIPfromDHCP(netInfo.ip);
//	getGWfromDHCP(netInfo.gw);
//	getSNfromDHCP(netInfo.sn);
//	getDNSfromDHCP(netInfo.dns);
//
//	setSHAR(netInfo.mac);
//	setGAR(netInfo.gw);
//	setSUBR(netInfo.sn);
//	setSIPR(netInfo.ip);
//
//    int sock = socket(TCP_SOCKET, Sn_MR_TCP, LOCAL_PORT, 0);
//    if (sock < 0) {
//        printf("Socket creation failed\n");
//        return;
//    }
//
//    int ret = connect(TCP_SOCKET, S_ADDR, S_PORT);;
//    if (ret != SOCK_OK) {
//        printf("Connection failed\n");
//        close(TCP_SOCKET);
//        return;
//    }
//
//    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);  // Indicate success
//    printf("Connected to server\n");
//
//
//}
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
    HAL_SPI_Receive(&hspi1, &byte, 1, HAL_MAX_DELAY);
    return byte;
}
void W5500_WriteByte(uint8_t byte)

{
    HAL_SPI_Transmit(&hspi1, &byte, 1, HAL_MAX_DELAY);
}

void W5500_ReadBuff(uint8_t* buff, uint16_t len)
{
	 spiRxComplete = 0;
    HAL_SPI_Receive_DMA(&hspi1, buff, len);
    while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);

}
void W5500_WriteBuff(uint8_t* buff, uint16_t len)
{
	 spiTxComplete = 0;
    HAL_SPI_Transmit_DMA(&hspi1, buff, len);
    while(HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);

}
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if(hspi->Instance == SPI1)
    {
    	 spiTxComplete = 1;
    }
}
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
    if(hspi->Instance == SPI1)
    {
    	 spiRxComplete = 1;
    }
}
void W5500_Init(){

    reg_wizchip_cs_cbfunc(W5500_Select, W5500_Unselect);
    reg_wizchip_spi_cbfunc(W5500_ReadByte, W5500_WriteByte);
    reg_wizchip_spiburst_cbfunc(W5500_ReadBuff, W5500_WriteBuff);

    uint8_t memsize[2][8] = {{2,2,2,2,2,2,2,2}, {2,2,2,2,2,2,2,2}};
    if(wizchip_init(memsize[0], memsize[1]) < 0)
    {
    	Error_Handler();
    }

}

