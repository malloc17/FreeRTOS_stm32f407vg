/*
 * handler_global_val.c
 *
 *  Created on: Oct 25, 2023
 *      Author: Burak
 */


#include "handler_global_val.h"

struct user_info_s user_info[] =
{
    "BURAK BEY", 12345678901, 111111, "0",
    "KURAK BEY", 12345678902, 111111, "0",
    "ZURAK BEY", 12345678903, 111111, "0",
};

PUBLIC char * adding_balance(char *old_balance, char *amount_of_money) 
{
    int len1 = strlen(old_balance);
    int len2 = strlen(amount_of_money);
    int carry = 0;

    // Make sure the result array is large enough to hold the sum
    int max_len = (len1 > len2 ? len1 : len2) + 1;
    char * result_ptr = malloc((max_len + 1)* sizeof(char));

    result_ptr[max_len] = '\0';

    int i, j, k;
    for (i = len1 - 1, j = len2 - 1, k = max_len - 1; k >= 0; i--, j--, k--) {
        int digit1 = (i >= 0) ? old_balance[i] - '0' : 0;
        int digit2 = (j >= 0) ? amount_of_money[j] - '0' : 0;

        int sum = digit1 + digit2 + carry;
        result_ptr[k] = (sum % 10) + '0';
        if(k != 0)
            carry = sum / 10;
    }
    free(old_balance);
    
    // Remove leading zeros
    while (*result_ptr == '0' && *(result_ptr + 1) != '\0') {
        result_ptr++;
    }
    return result_ptr;
}

PUBLIC void init_user_balance()
{
    /*Burayı açılışta flashtan en son bakiyeleri çek*/
    unsigned int size = sizeof(user_info)/sizeof(struct user_info_s);

    char init_arr[] = "0";

    for(int i = 0 ; i < size; i++)
    {
        user_info[i].ui_user_balance = malloc(sizeof(char)*(strlen(init_arr)+1));
    }    
    
    for(int i = 0 ; i < size; i++)
    {
        strcpy(user_info[i].ui_user_balance,init_arr);
    }
}
