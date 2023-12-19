/*
 * handler_global_val.h
 *
 *  Created on: Oct 25, 2023
 *      Author: Burak
 */

#ifndef HANDLER_GLOBAL_VAL_H_
#define HANDLER_GLOBAL_VAL_H_

#include <stdint.h>
#include "access_modifiers.h"

struct user_info_s
{
    const char * const  ui_user_name;
    const uint64_t ui_user_id;
    uint32_t ui_user_password;
    char *   ui_user_balance;
};

PUBLIC void   init_user_balance();
PUBLIC char * adding_balance(char *, char *);

#endif /* HANDLER_GLOBAL_VAL_H_ */
