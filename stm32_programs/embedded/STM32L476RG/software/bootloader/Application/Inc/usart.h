/*
 * usart.h
 *
 *  Created on: 8 d�c. 2022
 *      Author: Administrateur
 */

#ifndef INC_USART_H_
#define INC_USART_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"


extern UART_HandleTypeDef huart1;

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

void CV_fputc_USART1_UART_Init(void);

void CV_USART2_UART_Init(void);
void CV_USART3_UART_Init(void);


#ifdef __cplusplus
}
#endif

#endif /* INC_USART_H_ */
