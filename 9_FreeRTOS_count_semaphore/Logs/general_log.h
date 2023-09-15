/*
 * general_log.h
 *
 *  Created on: Jun 11, 2023
 *      Author: Burak
 */

#ifndef GENERAL_LOG_H_
#define GENERAL_LOG_H_

#include "main.h"
#include "log_global_var.h"

int x = 5;
int y = 4;
int z = 3;

struct log_type_s  general_log_table[] =
{
		{"BURAK" , &x},
		{"METIN" , &y},
		{"RUM" , &z},
		{"EMPTY" , &x}
};

void show_request_handler(const char *);
extern int send_UART(uint8_t * pData, uint16_t Size);

#endif /* GENERAL_LOG_H_ */
