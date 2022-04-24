 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Abdelaziz Mohammad
 ******************************************************************************/

#include "Port.h"
#include "tm4c123gh6pm_registers.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

/* static variable to store the current status of the port ( INITIALIZED - NOT_INITIALIZED )*/
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

STATIC const Port_ConfigPin * Port_PortPins = NULL_PTR;

/*******************************************************************************
 *                                                                             *
 *                              Functions Body                                 *
 *                                                                             *
 *******************************************************************************/
/*******************************************************************************
* Service Name:       Port_Init
* Service ID[hex]:    0x00
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    ConfigPtr
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initializes the Port Driver module
********************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_UNINIT);
	}
	else
#endif
	{
	    /* Convert the Port status into INITIALIZED */
		Port_Status  = PORT_INITIALIZED;

        /* Points to the first location of the array - name of the array is a constant pointer to the first element*/
		Port_PortPins = ConfigPtr->CONFIGURED_PINS;
        
	    /* point to the required Port Registers base address */
        volatile uint32 * Port_BASE_Address_Ptr = NULL_PTR;  
        
		/* Variable used to waste 3 clock cycles */
        volatile uint32 delay = 0;

		/* Variable used in for loop*/
		volatile uint8 counter = 0;

        /* Loop on all 43 cofigurable pins */
		for ( counter = 0 ; counter < PORT_CONFIGURED_PINS ; counter ++ )
		{

            /* Store the PORT # BASE Address into a pointer */
			switch(ConfigPtr->CONFIGURED_PINS[counter].port_num)
			{
				case PORT_A_NUM: Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
				                 break;
				case PORT_B_NUM: Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
				                 break;
				case PORT_C_NUM: Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
				                 break;
				case PORT_D_NUM: Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
				                 break;
				case PORT_E_NUM: Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
				                 break;
				case PORT_F_NUM: Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;
				                 break;								 								 
			}

            /* Enable clock for PORT and allow time for clock to start*/
             SYSCTL_REGCGC2_REG |= (1<<ConfigPtr->CONFIGURED_PINS[counter].port_num);
             delay = SYSCTL_REGCGC2_REG;


   		    if( (ConfigPtr->CONFIGURED_PINS[counter].port_num== 2) && (ConfigPtr->CONFIGURED_PINS[counter].pin_num  <= 3) ) /* PC0 to PC3 */
    		{
       				 /* Do Nothing ...  this is the JTAG pins */
    		}
  		   else
    		{
           				 /* Unlocking Commit for PINS  PD7 - PF0  */
           				 if( ((ConfigPtr->CONFIGURED_PINS[counter].port_num == 3) && (ConfigPtr->CONFIGURED_PINS[counter].pin_num == 7)) || ((ConfigPtr->CONFIGURED_PINS[counter].port_num == 5) && (ConfigPtr->CONFIGURED_PINS[counter].pin_num == 0)) )
   						{
       				 			*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;                     /* Unlock the GPIOCR register */   
      				  			SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_COMMIT_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
    					}

           				/*Check if the PIN is not analog configured but DIO configured*/
						if (ConfigPtr->CONFIGURED_PINS[counter].mode == PIN_DIO_MODE)
						{
								/* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
								CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num); 

							   /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
								SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);            
				
							  /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
								CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num); 
			
			            }
					    /*Check if the PIN is Analog Configured*/
					     else if (ConfigPtr->CONFIGURED_PINS[counter].mode == PIN_ANALOG_MODE)
						{
							/* Set the corresponding bit in the GPIOAMSEL register to Enable analog functionality on this pin */
							SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);

			    			/* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
							CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num); 

			   			    /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
							CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);  	

			    			
						}
						/*Check if the pin configured as an Alternative Function*/
						else
						{
							/* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
							CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);

							/* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
							SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num); 

			   				 /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
							SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num); 
						}

			 		  /* Set Pin Mode for this pin */  
			   			*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_CTL_REG_OFFSET) = ( *(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_CTL_REG_OFFSET)\
			  		  & ( ~(PORT_PIN_MODE_MASK << (ConfigPtr->CONFIGURED_PINS[counter].pin_num * 4) ) ) ) \
						| (ConfigPtr->CONFIGURED_PINS[counter].mode << (ConfigPtr->CONFIGURED_PINS[counter].pin_num * 4) );


		  			 /* Check if the PIN is configured as Output pin*/
   		 			  if(ConfigPtr->CONFIGURED_PINS[counter].direction == PORT_PIN_OUT)
   		 			  {
							/* Set the corresponding bit in the GPIODIR register to configure it as output pin */  
							SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIR_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);                
        
							 /*Check if the Initial Value is 1*/
       						 if(ConfigPtr->CONFIGURED_PINS[counter].initial_value == STD_HIGH)
       						 {
								   /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
         						   SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DATA_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);          
        					 }
							 /*Check if the Initial Value is 0*/
       		   				 else
                			{
								  /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
            					  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DATA_REG_OFFSET) ,ConfigPtr->CONFIGURED_PINS[counter].pin_num);        
        					}
          			 }
		  			 /* Check if the PIN is configured as Input pin*/
    	  			 else if(ConfigPtr->CONFIGURED_PINS[counter].direction == PORT_PIN_IN)
    	  			 {
			       			  /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        						 CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIR_REG_OFFSET) ,ConfigPtr->CONFIGURED_PINS[counter].pin_num);             

							/*Check if the resistor is PULL UP*/
                			if(ConfigPtr->CONFIGURED_PINS[counter].resistor == PULL_UP)
               				{
				   				  /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                    				 SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);       
               				}
              				else if(ConfigPtr->CONFIGURED_PINS[counter].resistor == PULL_DOWN)
               				{
				 				  /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
            					SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);     
               				}
             		 		 else
              		 		{
				 			  /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            					CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_UP_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);

							/* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */     
            						CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_DOWN_REG_OFFSET) , ConfigPtr->CONFIGURED_PINS[counter].pin_num);   
               				}
           			 }
          			 else
          			 {
                    /* Do Nothing */
           			 }
    	     }           
    	}
    }
}

/*******************************************************************************
* Service Name:       Port_SetPinDirection
* Service ID[hex]:    0x01
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Port Pin ID Number [0:42] - Port Pin Direction
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Sets the port pin direction
********************************************************************************/
void Port_SetPinDirection( Port_PinType Pin_ID, Port_PinDirectionType Direction )
{
	volatile uint32 * Port_BASE_Address_Ptr = NULL_PTR;
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (PORT_CONFIGURED_PINS <= Pin_ID)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	if(Port_PortPins[Pin_ID].direction_changeable == STD_OFF)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
		error = TRUE;
	}
	else
	{
		/* No Action Required */		
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
		/* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(Port_PortPins[Pin_ID].port_num)
		{
            case PORT_A_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
		               break;
		    case PORT_B_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
		               break;
		    case PORT_C_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
		               break;
		    case PORT_D_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
		               break;
            case PORT_E_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
		               break;
            case PORT_F_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;;
		               break;
		}
		   /* Check if the PIN is configured as Output pin*/
   		   if(Direction == PORT_PIN_OUT)
   		   {
				/* Set the corresponding bit in the GPIODIR register to configure it as output pin */  
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);                
        
				 /*Check if the Initial Value is 1*/
       			 if(Port_PortPins[Pin_ID].initial_value == STD_HIGH)
       			 {
					   /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
         			   SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);          
        		 }
				 /*Check if the Initial Value is 0*/
       		    else
                {
					  /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
            		  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);        
        		}
           }
		   /* Check if the PIN is configured as Input pin*/
    	   else if(Direction == PORT_PIN_IN)
    	   {
			         /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        			 CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);             

				/*Check if the resistor is PULL UP*/
                if(Port_PortPins[Pin_ID].resistor == PULL_UP)
               {
				     /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);       
               }
              else if(Port_PortPins[Pin_ID].resistor == PULL_DOWN)
               {
				   /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
            		SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);     
               }
               else
               {
				   /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            		CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);

					/* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */     
            		CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);   
               }
            }
           else
           {
                    /* Do Nothing */
           }

	}

}

/*******************************************************************************
* Service Name:       Port_RefreshPortDirection
* Service ID[hex]:    0x02
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Refreshes port direction
********************************************************************************/
void Port_RefreshPortDirection( void )
{
	volatile uint32 * Port_BASE_Address_Ptr = NULL_PTR;
	boolean error = FALSE;

    #if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
			/*Variable to be used in for loop*/
			volatile uint8 counter = 0 ;

			for ( counter = 0 ; counter < PORT_CONFIGURED_PINS ; counter ++)
			{

	  			 /* Check if the direction changeability is sett off */
	   			if(Port_PortPins[counter].direction_changeable == STD_OFF)
	   			{
		   				 		   /* Check if the PIN is configured as Output pin*/
   		  				 if(Port_PortPins[counter].direction == PORT_PIN_OUT)
   		   				{
							/* Set the corresponding bit in the GPIODIR register to configure it as output pin */  
							SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[counter].pin_num);                
        
							 /*Check if the Initial Value is 1*/
       						 if(Port_PortPins[counter].initial_value == STD_HIGH)
       						 {
					 			  /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
         			 			  SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[counter].pin_num);          
        		 			 }
								 /*Check if the Initial Value is 0*/
       		   				 else
                			{
								  /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
            					  CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DATA_REG_OFFSET) , Port_PortPins[counter].pin_num);        
        					}
           		}
		   /* Check if the PIN is configured as Input pin*/
    	   else if(Port_PortPins[counter].direction == PORT_PIN_IN)
    	   {
			         /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        			 CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIR_REG_OFFSET) , Port_PortPins[counter].pin_num);             

				/*Check if the resistor is PULL UP*/
                if(Port_PortPins[counter].resistor == PULL_UP)
               {
				     /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
                     SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[counter].pin_num);       
               }
              else if(Port_PortPins[counter].resistor == PULL_DOWN)
               {
				   /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
            		SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[counter].pin_num);     
               }
               else
               {
				   /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            		CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_PortPins[counter].pin_num);

					/* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */     
            		CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_PortPins[counter].pin_num);   
               }
            }
           else
           {
                    /* Do Nothing */
           }
	   }
	   else
	   {
		   /* Do Nothing - Just Exclude PINS Whose direction is not changeable  */
	   }

	}

  }


}


/*******************************************************************************
* Service Name:       Port_GetVersionInfo
* Service ID[hex]:    0x03
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Returns the version information for this module
********************************************************************************/
#if(PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif

/*******************************************************************************
* Service Name:       Port_SetPinMode
* Service ID[hex]:    0x04
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Port Pin ID Number - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Sets the port pin mode. 
********************************************************************************/
void Port_SetPinMode ( Port_PinType Pin_ID , Port_PinModeType Mode)
{
volatile uint32 * Port_BASE_Address_Ptr = NULL_PTR;
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if the Driver is initialized before using this function */
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_Port_SET_PIN_MODE_SID, PORT_E_UNINIT);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	/* Check if the used channel is within the valid range */
	if (PORT_CONFIGURED_PINS <= Pin_ID)
	{

		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_Port_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
		error = TRUE;
	}
	else
	{
		/* No Action Required */
	}
	if(Port_PortPins[Pin_ID].mode_changeable == STD_OFF)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_Port_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
		error = TRUE;		
	}
	else
	{
		/* No Action Required */		
	}
#endif

	/* In-case there are no errors */
	if(FALSE == error)
	{
       /* Point to the correct PORT register according to the Port Id stored in the Port_Num member */
		switch(Port_PortPins[Pin_ID].port_num)
		{
            case PORT_A_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS;
		               break;
		    case PORT_B_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS;
		               break;
		    case PORT_C_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS;
		               break;
		    case PORT_D_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS;
		               break;
            case PORT_E_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS;
		               break;
            case PORT_F_NUM:    Port_BASE_Address_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS;;
		               break;
		}

            /*Check if the PIN is not analog configured but DIO configured*/
			if (Mode == PIN_DIO_MODE)
			{
				/* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
				CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num); 

				 /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);            
				
				/* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
				CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num); 
			
			}
			/*Check if the PIN is Analog Configured*/
			else if (Mode == PIN_ANALOG_MODE)
			{
				/* Set the corresponding bit in the GPIOAMSEL register to Enable analog functionality on this pin */
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);

			    /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
				CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num); 

			    /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
				CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);  	
		
			}
			/*Check if the pin configured as an Alternative Function*/
			else
			{
				/* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
				CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num);

				/* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num); 

			    /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
				SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortPins[Pin_ID].pin_num); 
   
			}

			 /* Set Pin Mode for this pin */  
			*(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_CTL_REG_OFFSET) = ( *(volatile uint32 *)((volatile uint8 *)Port_BASE_Address_Ptr + PORT_CTL_REG_OFFSET)\
		  & ( ~(PORT_PIN_MODE_MASK << (Port_PortPins[Pin_ID].pin_num * 4) ) ) ) \
			| (Port_PortPins[Pin_ID].mode << (Port_PortPins[Pin_ID].pin_num* 4) );
	}


}