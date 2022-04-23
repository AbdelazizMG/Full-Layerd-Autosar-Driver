 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Abdelaziz Mohammad
 ******************************************************************************/
#include "Port.h"
#include "Port_Cfg.h"
/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Dio_Init API */
const Port_ConfigType Port_Configuration = {


      PORT_A_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTA_PIN_0,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */
        
      PORT_A_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTA_PIN_1,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_A_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTA_PIN_2,                        /* PIN Number                     [ ORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_A_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTA_PIN_3,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_A_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTA_PIN_4,                        /* PIN Number                     [   PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_A_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTA_PIN_5,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_A_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTA_PIN_6,                        /* PIN Number                     [   PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_A_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTA_PIN_7,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */      

      PORT_B_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTB_PIN_0,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                             /* PIN Mode Changeable            [ STD_OFF - STD_ON] */
        
      PORT_B_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTB_PIN_1,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_B_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTB_PIN_2,                        /* PIN Number                     [ ORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_B_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTB_PIN_3,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_B_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTB_PIN_4,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_B_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTB_PIN_5,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_B_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTB_PIN_6,                        /* PIN Number                     [   PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_B_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTB_PIN_7,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */   

      PORT_C_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTC_PIN_0,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                             /* PIN Mode Changeable            [ STD_OFF - STD_ON] */
        
      PORT_C_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTC_PIN_1,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_C_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTC_PIN_2,                        /* PIN Number                     [ ORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_C_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTC_PIN_3,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_C_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTC_PIN_4,                        /* PIN Number                     [   PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_C_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTC_PIN_5,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_C_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTC_PIN_6,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_C_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTC_PIN_7,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */   

      PORT_D_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTD_PIN_0,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                             /* PIN Mode Changeable            [ STD_OFF - STD_ON] */
        
      PORT_D_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTD_PIN_1,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_D_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTD_PIN_2,                        /* PIN Number                     [ ORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_D_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTD_PIN_3,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_D_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTD_PIN_4,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_D_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTD_PIN_5,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_D_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTD_PIN_6,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_D_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTD_PIN_7,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */       
 
      PORT_E_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTE_PIN_0,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                             /* PIN Mode Changeable            [ STD_OFF - STD_ON] */
        
      PORT_E_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTE_PIN_1,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_E_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTE_PIN_2,                        /* PIN Number                     [ ORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_E_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTE_PIN_3,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_E_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTE_PIN_4,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_E_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTE_PIN_5,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */     

      PORT_F_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTF_PIN_0,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                             /* PIN Mode Changeable            [ STD_OFF - STD_ON] */
        
      PORT_F_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTF_PIN_1,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_F_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTF_PIN_2,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_F_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTF_PIN_3,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF,                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */

      PORT_F_NUM,                         /* PORT Number                    [ PORT_A_NUM - PORT_B_NUM - PORT_C_NUM - PORT_D_NUM - PORT_E_NUM - PORT_F_NUM] */
      PORTF_PIN_4,                        /* PIN Number                     [ PORTA_PIN_0 :       PORTF_PIN_4                                          ] */
      PIN_DIO_MODE,                       /* PIN Mode                       [ PIN_DIO MODE - PIN_ANALOG_MODE - Others] */
      PORT_PIN_OUT,                       /* PIN Direction                  [ PORT_PIN_IN - PORT_PIN_OUT] */
      OFF,                                /* PIN Resistor                   [ OFF - PULL_UP - PULL_DOWN ]*/
      STD_OFF,                            /* PIN INITIAL VALUE              [ STD_OFF - STD_ON ] */
      STD_OFF,                            /* PIN Direction Changeable       [ STD_OFF - STD_ON] */
      STD_OFF                            /* PIN Mode Changeable            [ STD_OFF - STD_ON] */
};