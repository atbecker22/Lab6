/**
  ******************************************************************************
 //UART Sample Project
/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
#include "main.h"
#include "stm32l4xx.h"
#include "stm32l4xx_hal.h"
#include "stm32l475e_iot01.h"
#include "string.h"
#include "CircularBuffer.h"
int LEDtime;
commBuffer_t rxCommBuffer;
commBuffer_t txCommBuffer;
static uint32_t USARTCount = 0;
char receivedstr[MAXCOMMBUFFER+10];
int main(void){
HAL_Init();
	initBuffer(&rxCommBuffer, 0);
	initBuffer(&txCommBuffer, 1);
	/* Configure the System clock to have a frequency of 80 MHz */
	SystemClock_Config();
	BSP_LED_Init(LED2);
	BSP_LED_Off(LED2);
	/* Configure UART4 */
	Configure_USART();
	char* startText= "\n{\"Action\":\"Debug\",\"Info\":\"Testing UART4\"}\n";
	SendCharArrayUSART4(startText,strlen(startText));
	unsigned long cTicks = HAL_GetTick();
	/* Infinite loop */
	while(1){
		if (haveMessage(&rxCommBuffer)){
			getMessage(&rxCommBuffer, receivedstr);
			putMessage(&txCommBuffer, receivedstr, strlen(receivedstr));
			LL_USART_EnableIT_TXE(USARTx_INSTANCE);
			cTicks = HAL_GetTick();
			BSP_LED_On(LED2);
			LEDtime = (strlen(receivedstr) - 1) * 500;
			memset(receivedstr, '\0', MAXCOMMBUFFER+10);
		}
		if(HAL_GetTick() - cTicks >= LEDtime){
			BSP_LED_Off(LED2);
			LEDtime = 0;
		}

	}
}
/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (MSI)
  *            SYSCLK(Hz)                     = 80000000
  *            HCLK(Hz)                       = 80000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 1
  *            APB2 Prescaler                 = 1
  *            MSI Frequency(Hz)              = 4000000
2
 /
4
ECE 631
Assignment 5
Spring 2019
  *            PLL_M                          = 1
  *            PLL_N                          = 40
  *            PLL_R                          = 2
  *            PLL_P                          = 7
  *            PLL_Q                          = 4
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  /* MSI is enabled after System reset, activate PLL with MSI as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLP = 7;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    /* Initialization Error */
    while(1);
  }
}

/*
 * This is a simple IRQ handler for USART4. A better design would
 * be to have a circular list of strings. Head index pointing to
 * where chars added. Tail index oldest string to be processed
 */
void USARTx_IRQHandler(void) {
	// check if the USART6 receive interrupt flag was set
	int charCount = 0;
	if(LL_USART_IsActiveFlag_RXNE(USARTx_INSTANCE)){
		char t = LL_USART_ReceiveData8(USARTx_INSTANCE);
		charCount++;
		/* check if the received character is not the LF character (used to determine end of string)
		 * or the if the maximum string length has been been reached
		 */
		if(charCount < MAXCOMMBUFFER){
		putChar(&rxCommBuffer, t);
		}
	}
	else if(LL_USART_IsActiveFlag_TXE(USARTx_INSTANCE)){
		char t = getChar(&txCommBuffer);
		LL_USART_TransmitData8(USARTx_INSTANCE, t);
		if(t == '\n'){
			LL_USART_DisableIT_TXE(USARTx_INSTANCE);
		}
	}

}
