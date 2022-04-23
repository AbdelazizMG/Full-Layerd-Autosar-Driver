/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 *
 * Author: Abdelaziz Mohammad
 ******************************************************************************/
#include "Port.h"
#include "Dio.h"
#include "Led.h"

/* LED Configurations Structure */
static Port_ConfigPin  g_LED_Config;

/*********************************************************************************************/
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
void LED_setOn(void)
{
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,LED_ON);  /* LED ON */
}

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
void LED_setOff(void)
{
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,LED_OFF); /* LED OFF */
}

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
void LED_refreshOutput(void)
{
    Dio_LevelType state = Dio_ReadChannel(DioConf_LED1_CHANNEL_ID_INDEX);
    Dio_WriteChannel(DioConf_LED1_CHANNEL_ID_INDEX,state); /* re-write the same value */
}

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
void LED_toggle(void)
{
    Dio_LevelType state = Dio_FlipChannel(DioConf_LED1_CHANNEL_ID_INDEX);
}

/*********************************************************************************************/
