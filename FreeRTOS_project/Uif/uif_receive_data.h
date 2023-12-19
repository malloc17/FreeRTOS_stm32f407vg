/*
 * uif_receive_data.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Burak
 */

#ifndef UIF_RECEIVE_DATA_H_
#define UIF_RECEIVE_DATA_H_

struct receive_command_s
{
	volatile uint8_t   input_data;
	volatile char      input_data_buf[LOG_MAX_COMMAND_LENGTH];
	volatile uint8_t   index;
};

struct receive_command_s   receive_command;

#endif /* UIF_RECEIVE_DATA_H_ */
