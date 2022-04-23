/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.h
 *
 * Description: Header file for Led Module.
 *
 * Author: Abdelaziz Mohammad
 ******************************************************************************/
#ifndef LED_H
#define LED_H

#include "Std_Types.h"

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON  STD_HIGH
#define LED_OFF STD_LOW

/* Set the LED Port */
#define LED_PORT DioConf_LED1_PORT_NUM

/* Set the LED Pin Number */
#define LED_PIN_NUM DioConf_LED1_CHANNEL_NUM


/*******************************************************************************
* Service Name:       LED_setOn
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Used to turn the led on
********************************************************************************/
void LED_setOn(void);

/*******************************************************************************
* Service Name:       LED_setOff
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Used to turn the led off
********************************************************************************/
void LED_setOff(void);

/*******************************************************************************
* Service Name:       LED_toggle
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        used to toggle the led ( Turn it to on if off and vice versa )
********************************************************************************/
void LED_toggle(void);

/*******************************************************************************
* Service Name:       LED_refreshOutput
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Used to refresh the output
********************************************************************************/
void LED_refreshOutput(void);

#endif /* LED_H */
