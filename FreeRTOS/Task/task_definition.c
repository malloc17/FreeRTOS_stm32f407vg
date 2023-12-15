/*
 * task_definition.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Burak
 */

#include "task_definition.h"

/*void command_task_handler(void *param)
{
	volatile uint32_t ulNotifiedValue;
	uint8_t receive_data_buffer[SIZE_OF_READ_DATA_QUE];
	uint8_t receive_data;
	int i = 0;
	while(1)
	{
		xTaskNotifyWait(0, 0, &ulNotifiedValue, portMAX_DELAY);  // notify bekle
		i = 0;
		xQueueReceive(q_read_data,(void *)&receive_data,(TickType_t) 0);
		while(receive_data != '\n' )
		{
			receive_data_buffer[i++] = receive_data;
			xQueueReceive(q_read_data,(void *)&receive_data,(TickType_t) 0);
		}
		receive_data_buffer[i] = '\0';
		receive_data_buffer[--i] = '\n';  // \r yerie \n koyuldu

		send_UART(receive_data_buffer, SIZE_OF_READ_DATA_QUE_ELEMENT);
	}
}*/

void command_task_handler(void *param)
{
	volatile uint32_t ulNotifiedValue;
	//uint8_t receive_data_buffer[SIZE_OF_READ_DATA_QUE];
	uint8_t receive_data[LOG_MAX_COMMAND_LENGTH];
	int i = 0;
	while(1)
	{
		xTaskNotifyWait(0, 0, &ulNotifiedValue, portMAX_DELAY);  // notify bekle

		while(uxQueueMessagesWaiting(q_read_data) != 0)   // queue da ne kadar mesaj var?
		{
			xQueueReceive(q_read_data,(void *)&receive_data,(TickType_t) 0);

			command_parser(receive_data);

			//send_UART(receive_data, SIZE_OF_READ_DATA_QUE_ELEMENT);
		}
	}
}

void GS_task_handler(void *param)
{
	uint8_t data_buffer[SIZE_OF_READ_DATA_QUE] = "SAMPIYON GS\n";
	while(1)
	{
		send_UART(data_buffer, sizeof(data_buffer));
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void FB_task_handler(void *param)
{
	uint8_t data_buffer[SIZE_OF_READ_DATA_QUE] = "SAMPIYON FB\n";
	while(1)
	{
		send_UART(data_buffer, sizeof(data_buffer));
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
