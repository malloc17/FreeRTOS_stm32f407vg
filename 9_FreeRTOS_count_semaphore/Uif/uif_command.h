/*
 * uif_command.h
 *
 *  Created on: Jun 4, 2023
 *      Author: Burak
 */

#ifndef UIF_COMMAND_H_
#define UIF_COMMAND_H_

#include "main.h"
#include <string.h>

#define COMMAND_SIZE_IN_COMMAND_WORD  5
#define DATA_SIZE_IN_COMMAND_WORD     11

struct uif_command_s
{
	char command[COMMAND_SIZE_IN_COMMAND_WORD];
	char data[DATA_SIZE_IN_COMMAND_WORD];
};

enum command_enum
{
	SHOW_COMMAND,
	EMPTY_COMMAND
};

extern int send_UART(uint8_t * pData, uint16_t Size);
extern void show_request_handler(const char *);

void command_parser(uint8_t * );
void tokenize_command(struct uif_command_s *, const uint8_t *);
void add_null_char_to_end_of_arr(struct uif_command_s *);
enum command_enum find_command(struct uif_command_s);

#endif /* UIF_COMMAND_H_ */
