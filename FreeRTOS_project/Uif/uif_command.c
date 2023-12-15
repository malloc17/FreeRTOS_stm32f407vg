/*
 * uif_command.c
 *
 *  Created on: Jun 4, 2023
 *      Author: Burak
 */
#include "uif_command.h"

const char *uif_command_table[] =
{
		"show",
		"EMPTY"
};

void command_parser(uint8_t * command)
{
	int i = 0;
	while(command[i++] != '\n');

	struct uif_command_s 	uif_command;

	tokenize_command(&uif_command, (const uint8_t *)command);

	add_null_char_to_end_of_arr(&uif_command);

	enum command_enum command_val = find_command(uif_command);

	switch(command_val)
	{
		case SHOW_COMMAND:
			show_request_handler((const char *)&uif_command.data);
			break;
		case EMPTY_COMMAND:
			break;
		default:
			break;
	}

}

void tokenize_command(struct uif_command_s * uif_command, const uint8_t * command)
{
	char * token_of_command = strtok((char *)command, " ");
	strncpy(uif_command->command, token_of_command, sizeof(uif_command->command));
	token_of_command = strtok(NULL, " ");
	strncpy(uif_command->data, token_of_command, sizeof(uif_command->data));
}

void add_null_char_to_end_of_arr(struct uif_command_s * uif_command)
{
	uif_command->command[COMMAND_SIZE_IN_COMMAND_WORD - 1] = '\0';
	uif_command->data[DATA_SIZE_IN_COMMAND_WORD - 1] = '\0';
}

enum command_enum find_command(struct uif_command_s  uif_command)
{
	int command_val = 0;
	while(strcmp(uif_command_table[command_val],"EMPTY") )
	{
		if(!strcmp(uif_command_table[command_val],(const char *)uif_command.command))
			return (enum command_enum) command_val;
		command_val++;
	}
	return (enum command_enum) command_val;
}

