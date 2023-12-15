/*
 * general_log.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Burak
 */
#include "general_log.h"
#include <string.h>

void show_request_handler(const char * uif_command_data)
{
	//int i;
	//while(uif_command_data[i++] = '\0')

	int j = -1;
	char send_arr[20];
	while(strcmp(general_log_table[++j].log_name,"EMPTY"))
	{
		if(!strcmp(uif_command_data,general_log_table[j].log_name))
		{
			sprintf(send_arr, "%s  %d\n",uif_command_data,*(general_log_table[j].add_of_value));
			send_UART((uint8_t *)send_arr, strlen(send_arr));
		}

	}

}

//
