 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: Abdelaziz Mohammad
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H




/*******************************************************************************
 *                              Includes                                       *
 *******************************************************************************/
#include "Common_Macros.h"
#include "Std_Types.h"
#include "Port_Regs.h"

/*******************************************************************************
 *                              Versions                                       *
 *******************************************************************************/
/* Id for the company in the AUTOSAR,  Abdelaziz Mohammad's ID = 12  */

#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (120U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/* Macro for PORT Status */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Module Version 1.0.0 */

#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)


 /* AUTOSAR Version 4.0.3 */
 
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)


/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for Port Init */
#define PORT_INIT_SID                      (uint8)0x00

/* Service ID for Port Set Pin Direction */
#define PORT_SET_PIN_DIRECTION_SID         (uint8)0x01

/* Service ID for Refresh Port Direction*/
#define PORT_REFRESH_PORT_DIRECTION_SID    (uint8)0x02

/* Service ID for Port Get Version Info */
#define PORT_Port_GET_VERSION_INFO_SID     (uint8)0x03

/* Service ID for Port Set Pin Mode */
#define PORT_Port_SET_PIN_MODE_SID         (uint8)0x04





/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* Type definition for Port_PinType used by the PORT APIs */
typedef uint8 Port_PinType;

/* Type definition for Port_PinModeType used by the PORT APIs */
typedef uint8 Port_PinModeType;

/* Type definition for Port_PinModeInitValue used by the PORT APIs */
typedef uint8 Port_PinLevelInitValue;

/* Type definition for Port_PinModeChangeable used by the PORT APIs */
typedef uint8 Port_PinModeChangeable;

/* Type definition for Port_PinDirectionChangeable used by the PORT APIs */
typedef uint8 Port_PinDirectionChangeable;


/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Port Pin Id requested*/
#define PORT_E_PARAM_PIN                    ( uint8 )0x0A 

/* DET code to report Port Pin not configured as changeable*/
#define PORT_E_DIRECTION_UNCHANGEABLE       ( uint8 )0x0B

/* DET code to report API Port_Init service called with wrong paramter*/
#define PORT_E_PARAM_CONFIG                 ( uint8 )0x0C 

/* DET code to report API Port_SetPinMode service called when mode doesn't exist*/
#define PORT_E_PARAM_INVALID_MODE           ( uint8 )0x0D 

/* DET code to report API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE            ( uint8 )0x0E 

/* DET code to report API service called without module initialization*/
#define PORT_E_UNINIT                       ( uint8 )0x0F 

/* DET code to report APIs called with a Null Pointer*/
#define PORT_E_PARAM_POINTER                ( uint8 )0x10 

#define PORT_GET_VERSION_INFO_SID           ( uint8 )0x11


/*******************************************************************************
* Name: Port_PinDirection
* Type: Enumeration
* Range: PORT_PIN_IN - PORT_PIN_OUT
* Description: Possible Direction for a port pin 
********************************************************************************/
typedef enum
{
    PORT_PIN_IN ,PORT_PIN_OUT
}Port_PinDirectionType;

/*******************************************************************************
* Name: Port_InternalResistor
* Type: Enumeration
* Range: OFF - PULL_UP - PULL_DOWN
* Description: num to hold internal resistor type for PIN in case it's input pin
********************************************************************************/
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistor;

/*******************************************************************************
* Name: Port_ConfigPins
* Type: Structure
* Range: Hardware dependent structure
* Description: Structure to configure each individual PIN
*              1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
*              2. the number of the pin in the PORT.
*              3. the pin mode type                       --> DIO, ADC or SPI
*              4. the direction of pin                    --> PORT_PIN_IN or PORT_PIN_OUT
*              5. the internal resistor                   --> OFF, Pull up or Pull down
*              6. the pin initial value                   --> STD_OFF, STD_ON
*              7. the direction changability              --> STD_OFF, STD_ON
*              8. the mode changeability                  --> STD_OFF, STD_ON
********************************************************************************/
typedef struct 
{
    uint8 port_num; 
    Port_PinType pin_num; 
    Port_PinModeType mode;
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    Port_PinLevelInitValue initial_value;
    Port_PinDirectionChangeable direction_changeable;
    Port_PinModeChangeable mode_changeable;
    
}Port_ConfigPin;

/*******************************************************************************
* Name: Port_ConfigType
* Type: Structure
* Range: Hardware dependent structure
* Description: Struct that contains array of configured pins;
********************************************************************************/
typedef struct 
{
    Port_ConfigPin CONFIGURED_PINS[PORT_CONFIGURED_PINS];

}Port_ConfigType;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/*******************************************************************************
* Service Name:       Port_Init
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    ConfigPtr
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Initializes the Port Driver module
********************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr);


/*******************************************************************************
* Service Name:       Port_SetPinDirection
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Sets the port pin direction
********************************************************************************/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction ); 


/*******************************************************************************
* Service Name:       Port_RefreshPortDirection
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Refreshes port direction
********************************************************************************/
void Port_RefreshPortDirection( void );


/*******************************************************************************
* Service Name: 
* Sync/Async:         Synchronous
* Reentrancy:         Non Reentrant
* Parameters (in):    None
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description: 
********************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo ) ;

/*******************************************************************************
* Service Name:       Port_SetPinMode
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Port Pin ID Number - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out):   None
* Return value:       None
* Description:        Sets the port pin mode. 
********************************************************************************/
void Port_SetPinMode ( Port_PinType Pin , Port_PinModeType Mode);



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Dio and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */
