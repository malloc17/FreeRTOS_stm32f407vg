/*
 * hook_functions.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Burak
 */

#include "hook_functions.h"

void vApplicationIdleHook()
{
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);	//sleep
}
