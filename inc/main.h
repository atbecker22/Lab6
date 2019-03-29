/*----------------------------------------------------------------------------
 * Name:    LED.h
 * Purpose: low level LED definitions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2011 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#ifndef __MAIN_H
#define __MAIN_H

#include "USART.h"
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);

//UART4
#define MAX_STRLEN 2048
static char receivedString[MAX_STRLEN+1]; //Hold received string
static uint8_t haveString;

#endif
