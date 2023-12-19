/*
 * command_handler.c
 *
 *  Created on: Oct 16, 2023
 *      Author: Burak
 */
#include "esp8266_driver.h"

void esp8266_command_handler(uint8_t * receive_data)
{
	/**/
	
	send_data_to_esp8266(receive_data,ESP8266_MAX_COMMAND_LENGTH);
}