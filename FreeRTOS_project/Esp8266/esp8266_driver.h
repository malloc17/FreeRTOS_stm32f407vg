/*
 * esp8266_driver.h
 *
 *  Created on: Sep 22, 2023
 *      Author: Burak
 */

#ifndef ESP8266_DRIVER_H_
#define ESP8266_DRIVER_H_

#include "main.h"
#include <stdint.h>
#include "access_modifiers.h"

#define PORT_NUMBER 5003      // TCP
#define CREATE_TCP_SERVER 1

#define UART_TRANSMIT_TIMEOUT 5000
#define UART_RECEIVE_TIMEOUT  1000

#define MAX_SIZE_OF_RECEIVE_UART_BUFF    35

typedef enum
{
    ACCESS_POINT_MODE,
    STATION_MODE,
    NUM_OF_WORKING_MODE
}WorkingMode_t;

typedef enum
{
    ESP8266_INIT_FAILED,
    ESP8266_INIT_SUCCESS
}InitResult_t;

struct esp8266_uart_receive_s
{
  volatile uint8_t input_data_buf[MAX_SIZE_OF_RECEIVE_UART_BUFF];
  volatile uint8_t input_data;
  volatile uint8_t index;
  volatile uint8_t receive_data_start_flag;
};

typedef void (**INIT_FP)(void);
typedef void (*AP_FP)(void);
typedef void (*STA_FP)(void);

typedef enum
{
  AT_COMMAND,
  ATE_COMMAND,
  SET_NETWORK_NAME_PASSWORD_COMMAND,
  ENABLE_MULTIPLE_TCP_CONN_COMMAND,
  CONNECT_TO_AP_COMMAND,
  CONFIG_AS_TCP_SERVER_COMMAND,
  SEND_DATA_COMMAND
}Command;

static const char * const esp8266_command_table[] =
{
  "AT\r\n",
  "ATE0\r\n",
  "AT+CWSAP_CUR=",
  "AT+CIPMUX=1\r\n",
  "AT+CWJAP_CUR=",
  "AT+CIPSERVER=",
  "AT+CIPSEND="
};

typedef enum
{
  OK_RESPONSE,
  ALREADY_RESPONSE
}Response;

static const char * const esp8266_response_table[] =
{
  "OK",
  "ALREADY"
};

PUBLIC int    init_esp8266(WorkingMode_t );
PUBLIC void   send_to_esp8266(uint8_t * ,size_t );
PUBLIC void   send_data_to_esp8266(uint8_t * ,size_t );
PUBLIC void   receive_from_esp8266_polling(uint8_t * , size_t);

#endif /* ESP8266_DRIVER_H_ */
