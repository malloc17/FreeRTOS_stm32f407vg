/*
 * task_definition.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Burak
 */

#ifndef INC_TASK_DEFINITION_H_
#define INC_TASK_DEFINITION_H_

#include "main.h"

void GS_task_handler(void *param);
void FB_task_handler(void *param);
void user_interface_task_handler(void *param);

extern QueueHandle_t q_read_data;

extern void ui_command_parser(uint8_t * command);
extern void esp8266_command_handler(uint8_t * command);
extern int send_to_UART(uint8_t * pData, uint16_t Size);

#endif /* INC_TASK_DEFINITION_H_ */
