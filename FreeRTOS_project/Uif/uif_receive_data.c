/*
 * uif_receive_data.c
 *
 *  Created on: Sep 28, 2023
 *      Author: Burak
 */

#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "main.h"
#include "uif_receive_data.h"

extern QueueHandle_t q_read_data;
extern TaskHandle_t User_interface_task_handle;
extern UART_HandleTypeDef huart2;

void enable_receive_USB_IT()
{
	HAL_UART_Receive_IT(&huart2, (uint8_t *)&receive_command.input_data, 1);
}

void HAL_UART_RxCpltCallback_USB(UART_HandleTypeDef *huart)
{
	if(xQueueIsQueueFullFromISR(q_read_data))
	{
		return;
	}
	else
	{
		if(receive_command.index < LOG_MAX_COMMAND_LENGTH
				&& receive_command.input_data != '\r'
				&& receive_command.input_data != '\n')
		{
			receive_command.input_data_buf[receive_command.index++] = receive_command.input_data;
		}

		if(receive_command.input_data == '\n')
		{
			if(receive_command.index > 0)  // Doğrudan entera basılırsa onu yoksaysın \r\n
			{
				if(receive_command.index < LOG_MAX_COMMAND_LENGTH)
					receive_command.input_data_buf[receive_command.index++] = '\0';
				xQueueSendFromISR(q_read_data,(void *)&receive_command.input_data_buf ,NULL);
				receive_command.index = 0;
				xTaskNotifyFromISR(User_interface_task_handle,0,eNoAction,NULL);
			}
		}
	}

	/* Enable UART data byte reception again in IT mode */
	enable_receive_USB_IT();
}
