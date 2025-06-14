/*
 * tcp_server.h
 *
 *  Created on: May 23, 2025
 *      Author: kirtan
 */

#ifndef INC_TCP_SERVER_H_
#define INC_TCP_SERVER_H_

#include "wizchip_conf.h"

extern uint8_t S_ADDR[4] ;
extern uint16_t S_PORT;

void W5500_Init(void);
void W5500_Select(void);
void W5500_Unselect(void);
uint8_t W5500_ReadByte(void);
void W5500_WriteByte(uint8_t byte);
void W5500_ReadBuff(uint8_t *buff , uint16_t len);
void W5500_WriteBuff(uint8_t *buff ,uint16_t len);

void W5500_Init();
void tcp_server_host();

extern wiz_NetInfo netInfo;
#endif /* INC_TCP_SERVER_H_ */
