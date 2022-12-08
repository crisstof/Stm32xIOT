/*
 * usart.c
 *
 *  Created on: 8 déc. 2022
 *      Author: Administrateur
 */


#include "usart.h"


UART_HandleTypeDef huart1;

UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;


void CV_fputc_USART1_UART_Init(void)
{
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }

}

void CV_USART2_UART_Init(void)
{
  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 9600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
 huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  }
/* USART4 init function */
void CV_USART3_UART_Init(void)
{
  /* USER CODE END USART4_Init 1 */
  huart3.Instance = USART3;//USART4
  huart3.Init.BaudRate = 9600;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
}


void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
     /* USART1 clock enable */
  __HAL_RCC_USART1_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF7_USART1; //GPIO_AF4_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  }
  else if(uartHandle->Instance==USART2)
    {
       /* USART2 clock enable */
      __HAL_RCC_USART2_CLK_ENABLE();
      __HAL_RCC_GPIOA_CLK_ENABLE();
      /**USART2 GPIO Configuration
      PA2     ------> USART2_TX
      PA3     ------> USART2_RX
      */
      GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
      GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF7_USART2 ; //GPIO_AF4_USART2;
      HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    }
    else if(uartHandle->Instance==USART3)
    {
      /* USART4 clock enable */
      __HAL_RCC_USART3_CLK_ENABLE();
      __HAL_RCC_GPIOC_CLK_ENABLE();
      /**USART4 GPIO Configuration
      PC10     ------> USART4_TX
      PC11     ------> USART4_RX
      */
      GPIO_InitStruct.Pin = GPIO_PIN_10|GPIO_PIN_11;
      GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
      GPIO_InitStruct.Pull = GPIO_NOPULL;
      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
      GPIO_InitStruct.Alternate = GPIO_AF7_USART3; //GPIO_AF6_USART4;
      HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    }
  }
void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

 if(uartHandle->Instance==USART1)
 {
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();
    /**USART1 GPIO Configuration
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10);

  }
 else if(uartHandle->Instance==USART2)
   {
     /* Peripheral clock disable */
     __HAL_RCC_USART2_CLK_DISABLE();

     /**USART2 GPIO Configuration
     PA2     ------> USART2_TX
     PA3     ------> USART2_RX
     */
     HAL_GPIO_DeInit(GPIOA, USART_TX_Pin|USART_RX_Pin);
  }
   else if(uartHandle->Instance==USART3)
   {
     /* Peripheral clock disable */
     __HAL_RCC_USART3_CLK_DISABLE();

     /**USART4 GPIO Configuration
     PC10     ------> USART4_TX
     PC11     ------> USART4_RX
     */
     HAL_GPIO_DeInit(GPIOC, GPIO_PIN_10|GPIO_PIN_11);
   }
 }


