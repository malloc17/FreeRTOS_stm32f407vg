/*
 * task_definition.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Burak
 */

#include "task_definition.h"
#include "portmacro.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "command_handler.h"

void user_interface_task_handler(void *param)
{
	volatile uint32_t ulNotifiedValue;
	uint8_t receive_data[LOG_MAX_COMMAND_LENGTH];

	while(1)
	{
		xTaskNotifyWait(0, 0, &ulNotifiedValue, portMAX_DELAY);  // notify bekle
		while(uxQueueMessagesWaiting(q_read_data) != 0)   // queue da ne kadar mesaj var?
		{
			xQueueReceive(q_read_data,(void *)&receive_data,(TickType_t) 0);
			ui_command_parser(receive_data);
		}
	}
}

void command_task_handler(void *param)
{
	volatile uint32_t ulNotifiedValue;
	uint8_t receive_data[ESP8266_MAX_COMMAND_LENGTH];

	while(1)
	{
		xTaskNotifyWait(0, 0, &ulNotifiedValue, portMAX_DELAY);  
		while(uxQueueMessagesWaiting(esp8266_input_queue) != 0) 
		{
			xQueueReceive(esp8266_input_queue,(void *)&receive_data,(TickType_t) 0);
			esp8266_command_handler(receive_data);
		}
	}
}


void GS_task_handler(void *param)
{
	uint8_t data_buffer[SIZE_OF_READ_DATA_QUE] = "SAMPIYON GS\n";
	while(1)
	{
		send_to_UART(data_buffer, sizeof(data_buffer));
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}  

void FB_task_handler(void *param)
{
	uint8_t data_buffer[SIZE_OF_READ_DATA_QUE] = "SAMPIYON FB\n";
	while(1)
	{
		send_to_UART(data_buffer, sizeof(data_buffer));
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
