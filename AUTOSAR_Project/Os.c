 /******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.c
 *
 * Description: Source file for Os Scheduler.
 *
 * Author: Abdelaziz Mohammad
 ******************************************************************************/

#include "Os.h"
#include "App.h"
#include "Button.h"
#include "Led.h"
#include "Gpt.h"

/* Enable IRQ Interrupts ... This Macro enables IRQ interrupts by clearing the I-bit in the PRIMASK. */
#define Enable_Interrupts()    __asm("CPSIE I")

/* Disable IRQ Interrupts ... This Macro disables IRQ interrupts by setting the I-bit in the PRIMASK. */
#define Disable_Interrupts()   __asm("CPSID I")

/* Global variable store the Os Time */
static uint8 g_Time_Tick_Count = 0;

/* Global variable to indicate the the timer has a new tick */
static uint8 g_New_Time_Tick_Flag = 0;

/*******************************************************************************
* Service Name:       Os_start
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        1- Enable Interrupts
*                     2- Start the Os timer
*                     3- Execute the Init Task
*                     4- Start the Scheduler to run the tasks
********************************************************************************/
void Os_start(void)
{
    /* Global Interrupts Enable */
    Enable_Interrupts();
    
    /* 
     * Set the Call Back function to call Os_NewTimerTick
     * this function will be called every SysTick Interrupt (20ms)
     */
    SysTick_SetCallBack(Os_NewTimerTick);

    /* Start SysTickTimer to generate interrupt every 20ms */
    SysTick_Start(OS_BASE_TIME);

    /* Execute the Init Task */
    Init_Task();

    /* Start the Os Scheduler */
    Os_Scheduler();
}

/*******************************************************************************
* Service Name:       Os_Scheduler
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        The Engine of the Os Scheduler used for switch between different tasks
********************************************************************************/
void Os_NewTimerTick(void)
{
    /* Increment the Os time by OS_BASE_TIME */
    g_Time_Tick_Count   += OS_BASE_TIME;

    /* Set the flag to 1 to indicate that there is a new timer tick */
    g_New_Time_Tick_Flag = 1;
}

/*******************************************************************************
* Service Name:       Os_NewTimerTick
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Function called by the Timer Driver in the MCAL layer using the call back pointer
********************************************************************************/
void Os_Scheduler(void)
{
    while(1)
    {
	/* Code is only executed in case there is a new timer tick */
	if(g_New_Time_Tick_Flag == 1)
	{
	    switch(g_Time_Tick_Count)
            {
		case 20:
		case 100:
			    Button_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 40:
		case 80:
			    Button_Task();
			    Led_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 60:
			    Button_Task();
			    App_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 120:
			    Button_Task();
			    App_Task();
			    Led_Task();
			    g_New_Time_Tick_Flag = 0;
			    g_Time_Tick_Count = 0;
			    break;
            }
	}
    }

}
/*********************************************************************************************/
