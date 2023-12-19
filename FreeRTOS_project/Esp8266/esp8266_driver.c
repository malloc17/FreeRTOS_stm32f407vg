/*
 * Esp8266_driver.c
 *
 *  Created on: Sep 22, 2023
 *      Author: Burak
 */

#include "esp8266_driver.h"
#include <string.h>
#include <stdbool.h>

extern UART_HandleTypeDef huart4;
extern TaskHandle_t Command_task_handle;
extern int send_to_UART(uint8_t * pData, uint16_t Size);

PRIVATE void send_AT(void);
PRIVATE void connection_test(void);
PRIVATE void disable_echo(void);
PRIVATE void set_network_name_and_password(void);
PRIVATE void enable_multiple_tcp_conn(void);
PRIVATE void connect_to_AP(void);
PRIVATE void configure_as_tcp_server(void);

PRIVATE struct esp8266_uart_receive_s  esp8266_uart_receive;

AP_FP init_ap_mode_func_ptr[] =
{
  connection_test,
  disable_echo,
  set_network_name_and_password,
  enable_multiple_tcp_conn,
  connect_to_AP,
  configure_as_tcp_server,
  NULL
};

STA_FP init_sta_mode_func_ptr[] =
{
  connection_test,
  disable_echo,
  set_network_name_and_password,
  enable_multiple_tcp_conn,
  configure_as_tcp_server,
  NULL
};

INIT_FP init_esp8266_func_ptr[NUM_OF_WORKING_MODE]  =
{
  init_ap_mode_func_ptr,
  init_sta_mode_func_ptr
};

PUBLIC int init_esp8266(WorkingMode_t working_mode)
{
  unsigned char i = 0;
  switch (working_mode)
  {
  case ACCESS_POINT_MODE:
      while( init_esp8266_func_ptr[ACCESS_POINT_MODE][i] != NULL )
      {
        init_esp8266_func_ptr[ACCESS_POINT_MODE][i++]();
      }
    break;
  case STATION_MODE:
      while( init_esp8266_func_ptr[STATION_MODE][i] != NULL )
      {
        init_esp8266_func_ptr[STATION_MODE][i++]();
      }
    break;
  default:
    return ESP8266_INIT_FAILED;
    break;
  }

  return ESP8266_INIT_SUCCESS;
}

PUBLIC void send_to_esp8266(uint8_t *espBuff ,size_t buffLen)
{
  HAL_UART_Transmit(&huart4, espBuff, (uint16_t) buffLen, UART_TRANSMIT_TIMEOUT);
}

PUBLIC void send_data_to_esp8266(uint8_t * send_data ,size_t len)
{
  uint8_t espBuff[30] = {0};
  uint8_t cmdBuff[20] = {0};

  strcpy((char *)espBuff, esp8266_command_table[SEND_DATA_COMMAND]);
  
  (void) sprintf((char *)cmdBuff, "%d,%d\r\n",0,len);
  (void) strcat((char *)espBuff, (const char *) cmdBuff);
  HAL_Delay(1);
  send_to_esp8266(espBuff, strlen((const char *)espBuff));
  HAL_Delay(1);
  send_to_esp8266(send_data,len);
}

PRIVATE void send_AT()
{
  uint8_t espBuff[20] = {0};
  size_t buffLen;

  buffLen = (size_t) sprintf((char *)espBuff, esp8266_command_table[AT_COMMAND]);
  HAL_Delay(200);
  send_to_esp8266(espBuff, buffLen);
}

PUBLIC void receive_from_esp8266_polling(uint8_t * rBuff, size_t size)
{
  HAL_UART_Receive(&huart4, (uint8_t *)rBuff, size, UART_RECEIVE_TIMEOUT);
}

PRIVATE void waiting_OK()
{
  uint8_t rBuff[20] = {0};

  receive_from_esp8266_polling(rBuff, 20);
  HAL_Delay(100);

  while(strstr((char *) rBuff,esp8266_response_table[OK_RESPONSE]) == NULL)
  {
    HAL_Delay(200);
    send_AT();
    receive_from_esp8266_polling(rBuff, 20);
    HAL_Delay(500);
  }
}

PRIVATE void connection_test()
{
  send_AT();
  waiting_OK();
}

PRIVATE void disable_echo()
{
  int buffLen;
  uint8_t espBuff[20] = {0};

  buffLen = sprintf((char *)espBuff,esp8266_command_table[ATE_COMMAND]);
  HAL_Delay(200);
  send_to_esp8266(espBuff,buffLen);
}

PRIVATE void set_network_name_and_password()
{
  uint8_t espBuff[50] = {0};
  strcpy((char *) espBuff,esp8266_command_table[SET_NETWORK_NAME_PASSWORD_COMMAND]);
  uint8_t cmdBuff[40] = {0};

  const char MY_NETWORK_NAME[]= "FreeRTOS_UGUR_UNAL";
  const char MY_NETWORK_PASSWORD[] =  "Naber7816";

  (void) sprintf((char *)cmdBuff, "\"%s\",\"%s\",5,4\r\n",MY_NETWORK_NAME,MY_NETWORK_PASSWORD);
  (void) strcat((char *) espBuff, (const char *) cmdBuff);
  HAL_Delay(200);
  send_to_esp8266(espBuff, strlen((const char *)espBuff) + 1);
}

PRIVATE void enable_multiple_tcp_conn()
{
  int buffLen;
  uint8_t espBuff[20] = {0};

  buffLen = sprintf((char *)espBuff, esp8266_command_table[ENABLE_MULTIPLE_TCP_CONN_COMMAND]);
  HAL_Delay(200);
  send_to_esp8266(espBuff, buffLen);
}

PRIVATE void connect_to_AP() 
{
  uint8_t espBuff[50] = {0};
  strcpy((char *) espBuff,esp8266_command_table[CONNECT_TO_AP_COMMAND]);
  uint8_t cmdBuff[40] = {0};

  const char MY_WIFI_NAME[]= "FiberHGW_TP67EA_2.4GHz"; //"TTNET_ZyXEL_V4P9";
  const char PASSWORD[] = "MgN4juXH";  // "4C6FcB7B29454";

  (void) sprintf((char *)cmdBuff, "\"%s\",\"%s\"\r\n",MY_WIFI_NAME,PASSWORD);
  (void) strcat((char *)espBuff, (const char *) cmdBuff);
  HAL_Delay(200);
  send_to_esp8266(espBuff, strlen((const char *) espBuff) + 1);
}

PRIVATE void configure_as_tcp_server()
{
  uint8_t espBuff[50] = {0};
  strcpy((char *) espBuff,esp8266_command_table[CONFIG_AS_TCP_SERVER_COMMAND]);
  uint8_t cmdBuff[40] = {0};
  uint8_t rBuff[20] = {0};

  (void) sprintf((char *)cmdBuff, "%d,%d\r\n",CREATE_TCP_SERVER,PORT_NUMBER);
  (void) strcat((char *)espBuff,(const char *) cmdBuff);

  HAL_Delay(200);
  send_to_esp8266(espBuff, strlen((const char *) espBuff) + 1);

  receive_from_esp8266_polling(rBuff, 20);

  while(strstr((char *) rBuff,esp8266_response_table[OK_RESPONSE]) == NULL && strstr((char *) rBuff,esp8266_response_table[ALREADY_RESPONSE]) == NULL)
  {
    HAL_Delay(200);
    send_to_esp8266(espBuff, strlen((const char *) espBuff) + 1);
    receive_from_esp8266_polling(rBuff, 20);
    HAL_Delay(1000);
  }
}

void enable_receive_esp8266_IT()
{
	 HAL_UART_Receive_IT(&huart4, (uint8_t *)&esp8266_uart_receive.input_data, 1);
}

void receive_from_esp8266_IT(UART_HandleTypeDef *huart)
{
  if(xQueueIsQueueFullFromISR(esp8266_input_queue))
	{
		return;
	}
	else if(esp8266_uart_receive.receive_data_start_flag == false)
	 {
		 if(esp8266_uart_receive.input_data == ':')
		 {
			 esp8266_uart_receive.receive_data_start_flag = true;
		 }
		 enable_receive_esp8266_IT();
		 return;
	 }
	 else
	 {
		 esp8266_uart_receive.input_data_buf[esp8266_uart_receive.index++] = esp8266_uart_receive.input_data;
		 if(esp8266_uart_receive.index >= 10)
		 {
			 //esp8266_uart_receive.input_data_buf[esp8266_uart_receive.index] = '\n';
			 esp8266_uart_receive.receive_data_start_flag = false;
       xQueueSendFromISR(esp8266_input_queue,(void *)&esp8266_uart_receive.input_data_buf ,NULL);
			 esp8266_uart_receive.index = 0;
			 xTaskNotifyFromISR(Command_task_handle,0,eNoAction,NULL);
			 //send_to_UART((uint8_t *)esp8266_uart_receive.input_data_buf, strlen((const char *) esp8266_uart_receive.input_data_buf));
       //send_to_esp8266((uint8_t *)esp8266_uart_receive.input_data_buf, (size_t) esp8266_uart_receive.index);
			 
		 }
		 enable_receive_esp8266_IT();
	 }
}

