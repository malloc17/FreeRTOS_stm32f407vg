/*
 * task_definition.h
 *
 *  Created on: Jun 2, 2023
 *      Author: Burak
 */

#ifndef INC_TASK_DEFINITION_H_
#define INC_TASK_DEFINITION_H_

#include "main.h"
#include "portmacro.h"
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void GS_task_handler(void *param);
void FB_task_handler(void *param);
void command_task_handler(void *param);

extern QueueHandle_t q_read_data;

extern void command_parser(uint8_t * command);

#endif /* INC_TASK_DEFINITION_H_ */
