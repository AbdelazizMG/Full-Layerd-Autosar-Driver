 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 * Author: Abdelaziz Mohammad
 ******************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H



/* Module Version 1.0.0 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)



/* AUTOSAR Version 4.0.3 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Number of Configured Pins*/
#define PORT_CONFIGURED_PINS                 (43U)



/* Port Numbers */
#define PORT_A_NUM   (uint8)0
#define PORT_B_NUM   (uint8)1
#define PORT_C_NUM   (uint8)2
#define PORT_D_NUM   (uint8)3
#define PORT_E_NUM   (uint8)4
#define PORT_F_NUM   (uint8)5

/* Pins Number */
#define PORTA_PIN_0        (uint8)0
#define PORTA_PIN_1        (uint8)1
#define PORTA_PIN_2        (uint8)2
#define PORTA_PIN_3        (uint8)3
#define PORTA_PIN_4        (uint8)4
#define PORTA_PIN_5        (uint8)5
#define PORTA_PIN_6        (uint8)6
#define PORTA_PIN_7        (uint8)7

#define PORTB_PIN_0        (uint8)0
#define PORTB_PIN_1        (uint8)1
#define PORTB_PIN_2        (uint8)2
#define PORTB_PIN_3        (uint8)3
#define PORTB_PIN_4        (uint8)4
#define PORTB_PIN_5        (uint8)5
#define PORTB_PIN_6        (uint8)6
#define PORTB_PIN_7        (uint8)7

#define PORTC_PIN_0        (uint8)0
#define PORTC_PIN_1        (uint8)1
#define PORTC_PIN_2        (uint8)2
#define PORTC_PIN_3        (uint8)3
#define PORTC_PIN_4        (uint8)4
#define PORTC_PIN_5        (uint8)5
#define PORTC_PIN_6        (uint8)6
#define PORTC_PIN_7        (uint8)7

#define PORTD_PIN_0        (uint8)0
#define PORTD_PIN_1        (uint8)1
#define PORTD_PIN_2        (uint8)2
#define PORTD_PIN_3        (uint8)3
#define PORTD_PIN_4        (uint8)4
#define PORTD_PIN_5        (uint8)5
#define PORTD_PIN_6        (uint8)6
#define PORTD_PIN_7        (uint8)7

#define PORTE_PIN_0        (uint8)0
#define PORTE_PIN_1        (uint8)1
#define PORTE_PIN_2        (uint8)2
#define PORTE_PIN_3        (uint8)3
#define PORTE_PIN_4        (uint8)4
#define PORTE_PIN_5        (uint8)5

#define PORTF_PIN_0        (uint8)0
#define PORTF_PIN_1        (uint8)1
#define PORTF_PIN_2        (uint8)2
#define PORTF_PIN_3        (uint8)3
#define PORTF_PIN_4        (uint8)4


/* Pin Modes */ 
#define PIN_DIO_MODE                    0U

/*PORT A PIN MODES*/
#define PIN_A0_U0Rx_Mode                1U
#define PIN_A0_CAN1Rx_Mode              8U

#define PIN_A1_U0Tx_Mode                1U
#define PIN_A1_CAN1Tx_Mode              8U

#define PIN_A2_SSI0Clk_Mode             2U

#define PIN_A3_SSI0Fss_Mode             2U

#define PIN_A4_SSI0Rx_Mode              2U

#define PIN_A5_SSI0Tx_Mode              2U

#define PIN_A6_I2C1SCL_Mode             3U
#define PIN_A6_MIPWM2_Mode              5U

#define PIN_A7_I2C1SDA_Mode             3U
#define PIN_A7_MIPWM3_Mode              5U

/*PORT B PIN MODES*/
#define PIN_B0_U1Rx_Mode                1
#define PIN_B0_T2CCP0_Mode              7

#define PIN_B1_U1Tx_Mode                1
#define PIN_B1_T2CCP1_Mode              7

#define PIN_B2_I2C0SCL_Mode             3
#define PIN_B2_T3CCP0_Mode              7

#define PIN_B3_I2C0SDA_Mode             3
#define PIN_B3_T3CCP1_Mode              7

#define PIN_B4_SSI2Clk_Mode             2
#define PIN_B4_M0PWM2_Mode              4
#define PIN_B4_T1CCP0_Mode              7
#define PIN_B4_CAN0Rx_Mode              8

#define PIN_B5_SSI2Fss_Mode             2
#define PIN_B5_M0PWM3_Mode              4
#define PIN_B5_T1CCP1_Mode              7
#define PIN_B5_CAN0Tx_Mode              8

#define PIN_B6_SSI2Rx_Mode              2
#define PIN_B6_M0PWM0_Mode              4
#define PIN_B6_T0CCP0_Mode              7

#define PIN_B7_SSI2Tx_Mode              2
#define PIN_B7_M0PWM1_Mode              4
#define PIN_B7_T0CCP1_Mode              7

/*PORT C PIN MODES*/
#define PIN_C4_U4Rx_Mode                1
#define PIN_C4_U1Rx_Mode                2
#define PIN_C4_M0PWM6_Mode              4
#define PIN_C4_IDX1_Mode                6
#define PIN_C4_WT0CCP0_Mode             7
#define PIN_C4_U1RTS_Mode               8

#define PIN_C5_U4Tx_Mode                1
#define PIN_C5_U1Tx_Mode                2
#define PIN_C5_M0PWM7_Mode              4
#define PIN_C5_PhA1_Mode                6
#define PIN_C5_WT0CCP1_Mode             7
#define PIN_C5_U1CTS_Mode               8

#define PIN_C6_U3Rx_Mode                1
#define PIN_C6_PhB1_Mode                6
#define PIN_C6_WT1CCP0_Mode             7
#define PIN_C6_USN0epen_Mode            8

#define PIN_C7_U3Tx_Mode                1
#define PIN_C7_WT1CCP1_Mode             7
#define PIN_C7_USB0pflt_Mode            8

/*PORT D PIN MODES*/
#define PIN_D0_SSI3Clk_Mode             1
#define PIN_D0_SSI1Clk_Mode             2
#define PIN_D0_I2C3SCL_Mode             3
#define PIN_D0_M0PWM6_Mode              4
#define PIN_D0_M1PWM0_Mode              5
#define PIN_D0_WT2CCP0_Mode             7

#define PIN_D1_SSI3Fss_Mode             1
#define PIN_D1_SSI1Fss_Mode             2
#define PIN_D1_I2C3SDA_Mode             3
#define PIN_D1_M0PWM7_Mode              4
#define PIN_D1_M1PWM1_Mode              5
#define PIN_D1_WT2CCP1_Mode             7

#define PIN_D2_SSI3Rx_Mode              1
#define PIN_D2_SSI1Rx_Mode              2
#define PIN_D2_M0Fault_Mode             4
#define PIN_D2_WT3CCP0_Mode             7
#define PIN_D2_USB0epen_Mode            8

#define PIN_D3_SSI3Tx_Mode              1
#define PIN_D3_SSI1Tx_Mode              2
#define PIN_D3_IDX0_Mode                6
#define PIN_D3_WT3CCP1_Mode             7
#define PIN_D3_USB0pflt_Mode            8

#define PIN_D4_U6Rx_Mode                1
#define PIN_D4_WT4CCO0_Mode             7

#define PIN_D5_U6Tx_Mode                1
#define PIN_D5_WT4CCP1_Mode             7

#define PIN_D6_U2Rx_Mode                1
#define PIN_D6_M0Fault_Mode             4
#define PIN_D6_PhA0_Mode                6
#define PIN_D6_WT5CCP0_Mode             7

#define PIN_D7_U2Tx_Mode                1
#define PIN_D7_PhB0_Mode                6
#define PIN_D7_WT5CCP1_Mode             7
#define PIN_D7_NMI_Mode                 8

/*PORT E PINS MODE*/
#define PIN_E0_U7Rx_Mode                1

#define PIN_E1_U7Tx_Mode                1

#define PIN_E4_U5Rx_Mode                1
#define PIN_E4_I2C2SCL_Mode             3
#define PIN_E4_M0PWM4_Mode              4
#define PIN_E4_M1PWM2_Mode              5
#define PIN_E4_CAN0Rx_Mode              8

#define PIN_E5_U5Tx_Mode                1
#define PIN_E5_I2C2SDA_Mode             3
#define PIN_E5_M0PWM5_Mode              4
#define PIN_E5_M1PWM3_Mode              5
#define PIN_E5_CAN0Tx_Mode              8

/*PORT F PINS MODE*/
#define PIN_F0_U1RTS_Mode               1
#define PIN_F0_SSI1Rx_Mode              2
#define PIN_F0_CAN0Rx_Mode              3
#define PIN_F0_M1PWM4_Mode              5
#define PIN_F0_PhA0_Mode                6
#define PIN_F0_T0CCP0_Mode              7
#define PIN_F0_NMI_Mode                 8
#define PIN_F0_C0o_Mode                 9

#define PIN_F1_U1CTS_Mode               1
#define PIN_F1_SSI1Tx_Mode              2
#define PIN_F1_M1PWM5_Mode              5
#define PIN_F1_PhB0_Mode                6
#define PIN_F1_T0CCP1_Mode              7
#define PIN_F1_C1o_Mode                 9
#define PIN_F1_TRD1_Mode                14

#define PIN_F2_SSI1Clk_Mode             2
#define PIN_F2_M0Fault_Mode             4
#define PIN_F2_M1PWM6_Mode              5
#define PIN_F2_T1CCP0_Mode              7
#define PIN_F2_TRD0_Mode                14

#define PIN_F3_SSI1Fss_Mode             2
#define PIN_F3_CAN0Tx_Mode              3
#define PIN_F3_M1PWM7_Mode              5
#define PIN_F3_T1CCP1_Mode              7
#define PIN_F3_TRCLK_Mode               14

#define PIN_F4_M1Fault_Mode             5
#define PIN_F4_IDX0_Mode                6
#define PIN_F4_T2CCP0_Mode              7
#define PIN_F4_USB0epen_Mode            8



#define PIN_ANALOG_MODE            10U





#endif






















