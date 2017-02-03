/************************************************************************/
/*                                                                      */
/*    Board_Data.c -- Board Customization Data for Digilent chipKIT WF32*/
/*                                                                      */
/************************************************************************/
/*    Author: Gene Apperson                                             */
/*    Copyright 2011, Digilent. All rights reserved                     */
/************************************************************************/
/*  File Description:                                                   */
/*                                                                      */
/* This file contains the board specific declartions and data structure */
/* to customize the chipKIT MPIDE for use with the Digilent chipKIT     */
/* Uno32 board.                                                         */
/*                                                                      */
/* This code is based on earlier work:                                  */
/*        Copyright (c) 2010, 2011 by Mark Sproul                       */
/*        Copyright (c) 2005, 2006 by David A. Mellis                   */
/*                                                                       */
/************************************************************************/
/*  Revision History:                                                   */
/*                                                                      */
/*    11/28/2011(GeneA): Created by splitting data out of Board_Defs.h  */
//*	Feb 17, 2012	<KeithV> Added PPS support for MZ devices
/*                                                                      */
/************************************************************************/
//*    This library is free software; you can redistribute it and/or
//*    modify it under the terms of the GNU Lesser General Public
//*    License as published by the Free Software Foundation; either
//*    version 2.1 of the License, or (at your option) any later version.
//*    
//*    This library is distributed in the hope that it will be useful,
//*    but WITHOUT ANY WARRANTY; without even the implied warranty of
//*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//*    Lesser General Public License for more details.
//*    
//*    You should have received a copy of the GNU Lesser General
//*    Public License along with this library; if not, write to the
//*    Free Software Foundation, Inc., 59 Temple Place, Suite 330,
//*    Boston, MA  02111-1307  USA
/************************************************************************/

#if !defined(BOARD_DATA_C)
#define BOARD_DATA_C

#include <inttypes.h>

/* ------------------------------------------------------------ */
/*                    Data Tables                               */
/* ------------------------------------------------------------ */
/* The following declarations define data used in pin mapping.  */
/* ------------------------------------------------------------ */

#if defined(OPT_BOARD_DATA)

/* ------------------------------------------------------------ */
/* This table is used to map from port number to the address of
** the TRIS register for the port. This is used for setting the
** pin direction.
*/
const uint32_t port_to_tris_PGM[] = {
    NOT_A_PORT,                //index value 0 is not used

#if defined(_PORTA)
    (uint32_t)&TRISA,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTB)
    (uint32_t)&TRISB,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTC)
    (uint32_t)&TRISC,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTD)
    (uint32_t)&TRISD,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTE)
    (uint32_t)&TRISE,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTF)
    (uint32_t)&TRISF,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTG)
    (uint32_t)&TRISG,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTH)
    (uint32_t)&TRISH,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTJ)
    (uint32_t)&TRISJ,
#else
    NOT_A_PORT,
#endif

#if defined(_PORTK)
    (uint32_t)&TRISK,
#else
    NOT_A_PORT,
#endif

    NOT_A_PORT,
};

/* ------------------------------------------------------------ */
/* This table is used to map the digital pin number to the port
** containing that pin.
*/
const uint8_t digital_pin_to_port_PGM[] = {
    /* Long header at side of board */
    _IOPORT_PE,         // 0    RE1
    _IOPORT_PE,         // 1    RE2
    _IOPORT_PE,         // 2    RE9
    _IOPORT_PB,         // 3    RB3
    _IOPORT_PB,         // 4    RB2
    _IOPORT_PA,         // 5    RA10
    _IOPORT_PB,         // 6    RB15
    _IOPORT_PE,         // 7    RE0
    _IOPORT_PG,         // 8    RG1
    _IOPORT_PD,         // 9    RD13
    _IOPORT_PD,         // 10   RD12
    _IOPORT_PC,         // 11   RC13
    _IOPORT_PD,         // 12   RD9
    _IOPORT_PF,         // 13   RF8
    _IOPORT_PF,         // 14   RF5
    _IOPORT_PA,         // 15   RA6
    _IOPORT_PA,         // 16   RA4
    _IOPORT_PE,         // 17   RE7
    
    // LEDs
    _IOPORT_PE,         // 18   RE3     Red
    _IOPORT_PE,         // 19   RE4     Green
    _IOPORT_PE,         // 20   RE6     Yellow
    _IOPORT_PB,         // 21   RB5     RGB Red
    _IOPORT_PB,         // 22   RB1     RGB Green
    _IOPORT_PB,         // 23   RB0     RGB Blue

    // Switches
    _IOPORT_PG,         // 24   RG12

    // Clicker 1
    _IOPORT_PB,         // 25   RB4     AN
    _IOPORT_PA,         // 26   RA9     RST
    _IOPORT_PD,         // 27   RD4     CS
    _IOPORT_PD,         // 28   RD1     SCK
    _IOPORT_PD,         // 29   RD14    MISO
    _IOPORT_PD,         // 30   RD3     MOSI
    _IOPORT_PA,         // 31   RA15    SDA1
    _IOPORT_PA,         // 32   RA14    SCL1
    _IOPORT_PD,         // 33   RD15    TX
    _IOPORT_PD,         // 34   RD10    RX
    _IOPORT_PF,         // 35   RF13    INT
    _IOPORT_PE,         // 36   RE8     PWM

    // Clicker 2
    _IOPORT_PA,         // 37   RA1     AN
    _IOPORT_PA,         // 38   RA5     RST
    _IOPORT_PD,         // 39   RD5     SS2
    _IOPORT_PG,         // 40   RG6     SCK2
    _IOPORT_PG,         // 41   RG0     SDI2
    _IOPORT_PG,         // 42   RG7     SDO2
    _IOPORT_PA,         // 43   RA3     SDA2
    _IOPORT_PA,         // 44   RA2     SCL2
    _IOPORT_PC,         // 45   RC2     U2TX
    _IOPORT_PC,         // 46   RC3     U2RX
    _IOPORT_PF,         // 47   RF12    INT2
    _IOPORT_PF,         // 48   RF2     PWM
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to a bit mask
** for the corresponding bit within the port.
*/
const uint16_t digital_pin_to_bit_mask_PGM[] = 
{
    /* Long header at side of board */
    _BV( 1 ),           // 0    RE1
    _BV( 2 ),           // 1    RE2
    _BV( 9 ),           // 2    RE9
    _BV( 3 ),           // 3    RB3
    _BV( 2 ),           // 4    RB2
    _BV(10 ),           // 5    RA10
    _BV(15 ),           // 6    RB15
    _BV( 0 ),           // 7    RE0
    _BV( 1 ),           // 8    RG1
    _BV(13 ),           // 9    RD13
    _BV(12 ),           // 10   RD12
    _BV(13 ),           // 11   RC13
    _BV( 9 ),           // 12   RD9
    _BV( 8 ),           // 13   RF8
    _BV( 5 ),           // 14   RF5
    _BV( 6 ),           // 15   RA6
    _BV( 4 ),           // 16   RA4
    _BV( 7 ),           // 17   RE7
    
    // LEDs
    _BV( 3 ),           // 18   RE3     Red
    _BV( 4 ),           // 19   RE4     Green
    _BV( 6 ),           // 20   RE6     Yellow
    _BV( 5 ),           // 21   RB5     RGB Red
    _BV( 1 ),           // 22   RB1     RGB Green
    _BV( 0 ),           // 23   RB0     RGB Blue

    // Switches
    _BV(12 ),           // 24   RG12

    // Clicker 1
    _BV( 4 ),           // 25   RB4     AN
    _BV( 9 ),           // 26   RA9     RST
    _BV( 4 ),           // 27   RD4     CS
    _BV( 1 ),           // 28   RD1     SCK
    _BV(14 ),           // 29   RD14    MISO
    _BV( 3 ),           // 30   RD3     MOSI
    _BV(15 ),           // 31           SDA1
    _BV(14 ),           // 32           SCL1
    _BV(15 ),           // 33   RD15    TX
    _BV(10 ),           // 34   RD10    RX
    _BV(13 ),           // 35   RF13    INT
    _BV( 8 ),           // 36   RE8     PWM

    // Clicker 2
    _BV( 1 ),           // 37   RA1     AN
    _BV( 5 ),           // 38   RA5     RST
    _BV( 5 ),           // 39   RD5     SS2
    _BV( 6 ),           // 40   RG6     SCK2
    _BV( 0 ),           // 41   RG0     SDI2
    _BV( 7 ),           // 42   RG7     SDO2
    _BV( 3 ),           // 43   RA3     SDA2
    _BV( 2 ),           // 44   RA2     SCL2
    _BV( 2 ),           // 45   RC2     U2TX
    _BV( 3 ),           // 46   RC3     U2RX
    _BV(12 ),           // 47   RF12    INT2
    _BV( 2 ),           // 48   RF2     PWM
};

/* ------------------------------------------------------------ */
/* This table is used to map from digital pin number to the output
** compare number, input capture number, and timer external clock
** input associated with that pin.
*/
const uint16_t digital_pin_to_timer_PGM[] =
{
    /* Long header at side of board */
    NOT_ON_TIMER,       // 0    RE1
    NOT_ON_TIMER,       // 1    RE2
    NOT_ON_TIMER,       // 2    RE9
    NOT_ON_TIMER,       // 3    RB3
    NOT_ON_TIMER,       // 4    RB2
    NOT_ON_TIMER,       // 5    RA10
    NOT_ON_TIMER,       // 6    RB15
    NOT_ON_TIMER,       // 7    RE0
    NOT_ON_TIMER,       // 8    RG1
    NOT_ON_TIMER,       // 9    RD13
    NOT_ON_TIMER,       // 10   RD12
    NOT_ON_TIMER,       // 11   RC13
    NOT_ON_TIMER,       // 12   RD9
    NOT_ON_TIMER,       // 13   RF8
    NOT_ON_TIMER,       // 14   RF5
    NOT_ON_TIMER,       // 15   RA6
    NOT_ON_TIMER,       // 16   RA4
    NOT_ON_TIMER,       // 17   RE7
    
    // LEDs
    NOT_ON_TIMER,       // 18   RE3     Red
    NOT_ON_TIMER,       // 19   RE4     Green
    NOT_ON_TIMER,       // 20   RE6     Yellow
    NOT_ON_TIMER,       // 21   RB5     RGB Red
    NOT_ON_TIMER,       // 22   RB1     RGB Green
    NOT_ON_TIMER,       // 23   RB0     RGB Blue

    // Switches
    NOT_ON_TIMER,       // 24   RG12

    // Clicker 1
    NOT_ON_TIMER,       // 25   RB4     AN
    NOT_ON_TIMER,       // 26   RA9     RST
    NOT_ON_TIMER,       // 27   RD4     CS
    NOT_ON_TIMER,       // 28   RD1     SCK
    NOT_ON_TIMER,       // 29   RD14    MISO
    NOT_ON_TIMER,       // 30   RD3     MOSI
    NOT_ON_TIMER,       // 31           SDA1
    NOT_ON_TIMER,       // 32           SCL1
    NOT_ON_TIMER,       // 33   RD15    TX
    NOT_ON_TIMER,       // 34   RD10    RX
    NOT_ON_TIMER,       // 35   RF13    INT
    NOT_ON_TIMER,       // 36   RE8     PWM

    // Clicker 2
    NOT_ON_TIMER,       // 37   RA1     AN
    NOT_ON_TIMER,       // 38   RA5     RST
    NOT_ON_TIMER,       // 39   RD5     SS2
    NOT_ON_TIMER,       // 40   RG6     SCK2
    NOT_ON_TIMER,       // 41   RG0     SDI2
    NOT_ON_TIMER,       // 42   RG7     SDO2
    NOT_ON_TIMER,       // 43           SDA2
    NOT_ON_TIMER,       // 44           SCL2
    NOT_ON_TIMER,       // 45   RC2     U2TX
    NOT_ON_TIMER,       // 46   RC3     U2RX
    NOT_ON_TIMER,       // 47   RF12    INT2
    NOT_ON_TIMER,       // 48   RF2     PWM
};

/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** analog pin number.
*/
const uint8_t digital_pin_to_analog_PGM[] = {
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
    NOT_ANALOG_PIN, 
};


/* ------------------------------------------------------------ */
/* This table is used to map from the analog pin number to the
** actual A/D converter channel used for that pin.
*/
const uint8_t analog_pin_to_channel_PGM[] =
{
                //*    chipKIT Pin        PIC32 Analog channel
    45,         //*    A0                       AN45
    49,         //*    A1                       AN49
    21,         //*    A2                       AN21
    10,         //*    A3                       AN10
    13,         //*    A4                       AN13
    12,         //*    A5                       AN12
    3,          //*    A6                       AN3
    2,          //*    A7                       AN2
    4,          //*    A8                       AN4
    1,          //*    A9                       AN1
    48,         //*    A10                      AN48
    0,          //*    A11                      AN00
    8,          //*    A12                      AN8
    7,          //*    A13                      AN7
};


/* ------------------------------------------------------------ */
/*                PPS Mappings                                    */
/* ------------------------------------------------------------ */


/* ------------------------------------------------------------ */
/* This table maps from a digital pin number to the corresponding
** PPS register. This register is used to select the peripheral output
** connected to the pin. The register is set to 0 to disconnedt the
** pin from any peripheral so it can be used as GPIO.
** For PIC32MX1xx/2xx series devices, the PPS output select registers
** are arranged as a contiguous series of 32 bit registers. This table
** treats these registers as an array of DWORDs an stores the index
** to the register.
*/
const uint8_t digital_pin_to_pps_out_PGM[] = {
    _PPS_OUT(_PPS_RPF2R),       //  0   RF02    EBIRDY3/RPF2/SDA3/RF2 
    _PPS_OUT(_PPS_RPF8R),       //  1   RF08    EBIRDY2/RPF8/SCL3/RF8
    _PPS_OUT(_PPS_RPE8R),       //  2   RE08    AN25/AERXD0/RPE8/RE8
    _PPS_OUT(_PPS_RPD0R),       //  3   RD00    EMDIO/AEMDIO/RPD0/RTCC/INT0/RD0
    NOT_PPS_PIN,                //  4   RA03    EBIRDY1/SDA2/RA3
    _PPS_OUT(_PPS_RPD1R),       //  5   RD01    RPD1/SCK1/RD1
    _PPS_OUT(_PPS_RPD2R),       //  6   RD02    EBID14/ETXEN/RPD2/PMD14/RD2    
    _PPS_OUT(_PPS_RPE9R),       //  7   RE09    AN26/AERXD1/RPE9/RE9  
    _PPS_OUT(_PPS_RPA14R),      //  8   RA14    AETXCLK/RPA14/SCL1/RA14 
    _PPS_OUT(_PPS_RPD3R),       //  9   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3   
    _PPS_OUT(_PPS_RPG9R),       //  10  RG09    EBIA2/AN11/C2INC/ERXCLK/EREFCLK/AERXCLK/AEREFCLK/RPG9/PMA2/RG9  
    _PPS_OUT(_PPS_RPD11R),      //  11  RD11    EMDC/AEMDC/RPD11/RD11
    _PPS_OUT(_PPS_RPF0R),       //  12  RF00    EBID11/ETXD1/RPF0/PMD11/RF0
    _PPS_OUT(_PPS_RPG6R),       //  13  RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6                   (User LED1)
    _PPS_OUT(_PPS_RPB5R),       //  14  RB05    AN45/C1INA/RPB5/RB5                             (AN0)   
    _PPS_OUT(_PPS_RPB9R),       //  15  RB09    EBIA7/AN49/RPB9/PMA7/RB9                        (AIN1)  
    _PPS_OUT(_PPS_RPC2R),       //  16  RC02    EBIA12/AN21/RPC2/PMA12/RC2                      (AIN2)  
    _PPS_OUT(_PPS_RPB15R),      //  17  RB15    EBIA0/AN10/ERXD3/AETXD2/RPB15/OCFB/PMA0/RB15    (AIN3)  
    _PPS_OUT(_PPS_RPG7R),       //  18  RG07    EBIA4/AN13/C1INC/ECRS/RPG7/SDA4/PMA4/RG7        (AIN4 / SDA)         
    _PPS_OUT(_PPS_RPG8R),       //  19  RG08    EBIA3/AN12/C2IND/ERXDV/ECRSDV/AERXDV/AECRSDV/RPG8/SCL4/PMA3/RG8 (AIN5 / SCL)   
    _PPS_OUT(_PPS_RPB3R),       //  20  RB03    AN3/C2INA/RPB3/RB3                              (AIN6)
    _PPS_OUT(_PPS_RPB2R),       //  21  RB02    AN2/C2INB/RPB2/RB2                              (AIN7)  
    NOT_PPS_PIN,                //  22  RB04    AN4/C1INB/RB4                                   (AIN8)  
    _PPS_OUT(_PPS_RPB1R),       //  23  RB01    PGEC1/AN1/RPB1/RB1                              (AIN9)
    _PPS_OUT(_PPS_RPB8R),       //  24  RB08    EBIA10/AN48/RPB8/PMA10/RB8                      (AIN10) 
    _PPS_OUT(_PPS_RPB0R),       //  25  RB00    PGED1/AN0/RPB0/RB0                              (AIN11) 
    NOT_PPS_PIN,                //  26  RE00    EBID0/PMD0/RE0
    NOT_PPS_PIN,                //  27  RE01    EBID1/PMD1/RE1  
    NOT_PPS_PIN,                //  28  RE02    EBID2/PMD2/RE2
    _PPS_OUT(_PPS_RPE3R),       //  29  RE03    EBID3/RPE3/PMD3/RE3   
    NOT_PPS_PIN,                //  30  RE04    EBID4/AN18/PMD4/RE4  
    _PPS_OUT(_PPS_RPE5R),       //  31  RE05    EBID5/AN17/RPE5/PMD5/RE5
    NOT_PPS_PIN,                //  32  RE06    EBID6/AN16/PMD6/RE6
    NOT_PPS_PIN,                //  33  RE07    EBID7/AN15/PMD7/RE7 
    _PPS_OUT(_PPS_RPD5R),       //  34  RD05    SQICS1/RPD5/RD5
    _PPS_OUT(_PPS_RPC1R),       //  35  RC01    EBIA6/AN22/RPC1/PMA6/RC1
    _PPS_OUT(_PPS_RPF1R),       //  36  RF01    EBID10/ETXD0/RPF1/PMD10/RF1
    NOT_PPS_PIN,                //  37  RA02    EBICS0/SCL2/RA2
    _PPS_OUT(_PPS_RPD12R),      //  38  RD12    EBID12/ETXD2/RPD12/PMD12/RD12
    _PPS_OUT(_PPS_RPD14R),      //  39  RD14    AN32/AETXD0/RPD14/RD14
    _PPS_OUT(_PPS_RPD15R),      //  40  RD15    AN33/AETXD1/RPD15/SCK6/RD15
    NOT_PPS_PIN,                //  41  RA09    VREF-/CVREF-/AN27/AERXD2/RA9
    NOT_PPS_PIN,                //  42  RA10    VREF+/CVREF+/AN28/AERXD3/RA10               (Pin A; VREF+)
    _PPS_OUT(_PPS_RPD4R),       //  43  RD04    SQICS0/RPD4/RD4                             (User LED2)
    NOT_PPS_PIN,                //  44  RB11    AN6/ERXERR/AETXERR/RB11                     (User LED3)
    NOT_PPS_PIN,                //  45  RG15    AN23/AERXERR/RG15                           (User LED4)                       
    NOT_PPS_PIN,                //  46  RA05    EBIA5/AN34/PMA5/RA5                         (BTN1)
    NOT_PPS_PIN,                //  47  RA04    EBIA14/PMCS1/PMA14/RA4                      (BTN2)
    NOT_PPS_PIN,                //  48  RB13    AN8/ERXD1/AECOL/RB13                        (AIN12 / POT)
    NOT_PPS_PIN,                //  49  RB12    EBIA11/AN7/ERXD0/AECRS/PMA11/RB12           (AIN13 / Power Supply Monitor)
    NOT_PPS_PIN,                //  50  RD13    EBID13/ETXD3/PMD13/RD13                     (5V Power Enable)
    _PPS_OUT(_PPS_RPB14R),      //  51  RB14    EBIA1/AN9/ERXD2/AETXD3/RPB14/SCK3/PMA1/RB14 (SD SCK)
    _PPS_OUT(_PPS_RPC3R),       //  52  RC03    EBIWE/AN20/RPC3/PMWR/RC3                    (SD SS)
    _PPS_OUT(_PPS_RPB10R),      //  53  RB10    EBIA13/CVREFOUT/AN5/RPB10/PMA13/RB10        (SD SDI)
    _PPS_OUT(_PPS_RPC4R),       //  54  RC04    EBIOE/AN19/RPC4/PMRD/RC4                    (SD SDO)
    _PPS_OUT(_PPS_RPD10R),      //  55  RD10    RPD10/SCK4/RD10                             (MRF24 SCK)
    _PPS_OUT(_PPS_RPD9R),       //  56  RD09    EBIA15/RPD9/PMCS2/PMA15/RD9                 (MRF24 SS)
    _PPS_OUT(_PPS_RPF5R),       //  57  RF05    EBIA8/RPF5/SCL5/PMA8/RF5                    (MRF24 SDI)   
    _PPS_OUT(_PPS_RPG0R),       //  58  RG00    EBID8/RPG0/PMD8/RG0                         (MRF24 SDO)  
    _PPS_OUT(_PPS_RPA15R),      //  59  RA15    AETXEN/RPA15/SDA1/RA15                      (MRF24 INT)
    _PPS_OUT(_PPS_RPG1R),       //  60  RG01    EBID9/ETXERR/RPG1/PMD9/RG1                  (MRF24 HIBERNATE)
    _PPS_OUT(_PPS_RPF4R),       //  61  RF04    EBIA9/RPF4/SDA5/PMA9/RF4                    (MRF24 RESET)
    NOT_PPS_PIN,                //  62  RA01    TCK/EBIA19/AN29/RA1                         (JTAG TCK)
    NOT_PPS_PIN,                //  63  RA00    TMS/EBIA16/AN24/RA0                         (JTAG TMS)
    _PPS_OUT(_PPS_RPF12R),      //  64  RF12    TDO/EBIA17/AN31/RPF12/RF12                  (JTAG TDO)
    _PPS_OUT(_PPS_RPF13R),      //  65  RF13    TDI/EBIA18/AN30/RPF13/SCK5/RF13             (JTAG TDI)
    NOT_PPS_PIN,                //  66  RA06    TRCLK/SQICLK/RA6                            (TRACE TRCLK)
    NOT_PPS_PIN,                //  67  RG13    TRD0/SQID0/RG13                             (TRACE TRD0)
    NOT_PPS_PIN,                //  68  RG12    TRD1/SQID1/RG12                             (TRACE TRD1)
    NOT_PPS_PIN,                //  69  RG14    TRD2/SQID2/RG14                             (TRACE TRD2)
    NOT_PPS_PIN,                //  70  RA07    TRD3/SQID3/RA7                              (TRACE TRD3)
 };

/* ------------------------------------------------------------ */
/* This table maps from the digital pin number to the value to be
** loaded into a PPS input select register to select that pin.
** It also maps from digital pin number to input/output pin set to 
** which the pin belongs. The set mask is in the high four bits,
** the select value is in the low four bits.
** Note: if the PIC32 device has more than four pin sets, or more than
** 16 pin mapping choices per input function, then this table will have
** to be redefined as a table of uint16_t values and the macros used to
** access the table redefined as well.
*/
const uint8_t digital_pin_to_pps_in_PGM[] = {
    _PPS_IN(_PPS_RPF2),         //  0   RF02    EBIRDY3/RPF2/SDA3/RF2 
    _PPS_IN(_PPS_RPF8),         //  1   RF08    EBIRDY2/RPF8/SCL3/RF8
    _PPS_IN(_PPS_RPE8),         //  2   RE08    AN25/AERXD0/RPE8/RE8
    _PPS_IN(_PPS_RPD0),         //  3   RD00    EMDIO/AEMDIO/RPD0/RTCC/INT0/RD0
    NOT_PPS_PIN,                //  4   RA03    EBIRDY1/SDA2/RA3
    _PPS_IN(_PPS_RPD1),         //  5   RD01    RPD1/SCK1/RD1
    _PPS_IN(_PPS_RPD2),         //  6   RD02    EBID14/ETXEN/RPD2/PMD14/RD2    
    _PPS_IN(_PPS_RPE9),         //  7   RE09    AN26/AERXD1/RPE9/RE9  
    _PPS_IN(_PPS_RPA14),        //  8   RA14    AETXCLK/RPA14/SCL1/RA14 
    _PPS_IN(_PPS_RPD3),         //  9   RD03    EBID15/ETXCLK/RPD3/PMD15/RD3   
    _PPS_IN(_PPS_RPG9),         //  10  RG09    EBIA2/AN11/C2INC/ERXCLK/EREFCLK/AERXCLK/AEREFCLK/RPG9/PMA2/RG9  
    _PPS_IN(_PPS_RPD11),        //  11  RD11    EMDC/AEMDC/RPD11/RD11
    _PPS_IN(_PPS_RPF0),         //  12  RF00    EBID11/ETXD1/RPF0/PMD11/RF0
    _PPS_IN(_PPS_RPG6),         //  13  RG06    AN14/C1IND/ECOL/RPG6/SCK2/RG6                   (User LED1)
    _PPS_IN(_PPS_RPB5),         //  14  RB05    AN45/C1INA/RPB5/RB5                             (AN0)   
    _PPS_IN(_PPS_RPB9),         //  15  RB09    EBIA7/AN49/RPB9/PMA7/RB9                        (AIN1)  
    _PPS_IN(_PPS_RPC2),         //  16  RC02    EBIA12/AN21/RPC2/PMA12/RC2                      (AIN2)  
    _PPS_IN(_PPS_RPB15),        //  17  RB15    EBIA0/AN10/ERXD3/AETXD2/RPB15/OCFB/PMA0/RB15    (AIN3)  
    _PPS_IN(_PPS_RPG7),         //  18  RG07    EBIA4/AN13/C1INC/ECRS/RPG7/SDA4/PMA4/RG7        (AIN4 / SDA)         
    _PPS_IN(_PPS_RPG8),         //  19  RG08    EBIA3/AN12/C2IND/ERXDV/ECRSDV/AERXDV/AECRSDV/RPG8/SCL4/PMA3/RG8 (AIN5 / SCL)   
    _PPS_IN(_PPS_RPB3),         //  20  RB03    AN3/C2INA/RPB3/RB3                              (AIN6)
    _PPS_IN(_PPS_RPB2),         //  21  RB02    AN2/C2INB/RPB2/RB2                              (AIN7)  
    NOT_PPS_PIN,                //  22  RB04    AN4/C1INB/RB4                                   (AIN8)  
    _PPS_IN(_PPS_RPB1),         //  23  RB01    PGEC1/AN1/RPB1/RB1                              (AIN9)
    _PPS_IN(_PPS_RPB8),         //  24  RB08    EBIA10/AN48/RPB8/PMA10/RB8                      (AIN10) 
    _PPS_IN(_PPS_RPB0),         //  25  RB00    PGED1/AN0/RPB0/RB0                              (AIN11) 
    NOT_PPS_PIN,                //  26  RE00    EBID0/PMD0/RE0
    NOT_PPS_PIN,                //  27  RE01    EBID1/PMD1/RE1  
    NOT_PPS_PIN,                //  28  RE02    EBID2/PMD2/RE2
    _PPS_IN(_PPS_RPE3),         //  29  RE03    EBID3/RPE3/PMD3/RE3   
    NOT_PPS_PIN,                //  30  RE04    EBID4/AN18/PMD4/RE4  
    _PPS_IN(_PPS_RPE5),         //  31  RE05    EBID5/AN17/RPE5/PMD5/RE5
    NOT_PPS_PIN,                //  32  RE06    EBID6/AN16/PMD6/RE6
    NOT_PPS_PIN,                //  33  RE07    EBID7/AN15/PMD7/RE7 
    _PPS_IN(_PPS_RPD5),         //  34  RD05    SQICS1/RPD5/RD5
    _PPS_IN(_PPS_RPC1),         //  35  RC01    EBIA6/AN22/RPC1/PMA6/RC1
    _PPS_IN(_PPS_RPF1),         //  36  RF01    EBID10/ETXD0/RPF1/PMD10/RF1
    NOT_PPS_PIN,                //  37  RA02    EBICS0/SCL2/RA2
    _PPS_IN(_PPS_RPD12),        //  38  RD12    EBID12/ETXD2/RPD12/PMD12/RD12
    _PPS_IN(_PPS_RPD14),        //  39  RD14    AN32/AETXD0/RPD14/RD14
    _PPS_IN(_PPS_RPD15),        //  40  RD15    AN33/AETXD1/RPD15/SCK6/RD15
    NOT_PPS_PIN,                //  41  RA09    VREF-/CVREF-/AN27/AERXD2/RA9
    NOT_PPS_PIN,                //  42  RA10    VREF+/CVREF+/AN28/AERXD3/RA10               (Pin A; VREF+)
    _PPS_IN(_PPS_RPD4),         //  43  RD04    SQICS0/RPD4/RD4                             (User LED2)
    NOT_PPS_PIN,                //  44  RB11    AN6/ERXERR/AETXERR/RB11                     (User LED3)
    NOT_PPS_PIN,                //  45  RG15    AN23/AERXERR/RG15                           (User LED4)                       
    NOT_PPS_PIN,                //  46  RA05    EBIA5/AN34/PMA5/RA5                         (BTN1)
    NOT_PPS_PIN,                //  47  RA04    EBIA14/PMCS1/PMA14/RA4                      (BTN2)
    NOT_PPS_PIN,                //  48  RB13    AN8/ERXD1/AECOL/RB13                        (AIN12 / POT)
    NOT_PPS_PIN,                //  49  RB12    EBIA11/AN7/ERXD0/AECRS/PMA11/RB12           (AIN13 / Power Supply Monitor)
    NOT_PPS_PIN,                //  50  RD13    EBID13/ETXD3/PMD13/RD13                     (5V Power Enable)
    _PPS_IN(_PPS_RPB14),        //  51  RB14    EBIA1/AN9/ERXD2/AETXD3/RPB14/SCK3/PMA1/RB14 (SD SCK)
    _PPS_IN(_PPS_RPC3),         //  52  RC03    EBIWE/AN20/RPC3/PMWR/RC3                    (SD SS)
    _PPS_IN(_PPS_RPB10),        //  53  RB10    EBIA13/CVREFIN/AN5/RPB10/PMA13/RB10        (SD SDI)
    _PPS_IN(_PPS_RPC4),         //  54  RC04    EBIOE/AN19/RPC4/PMRD/RC4                    (SD SDO)
    _PPS_IN(_PPS_RPD10),        //  55  RD10    RPD10/SCK4/RD10                             (MRF24 SCK)
    _PPS_IN(_PPS_RPD9),         //  56  RD09    EBIA15/RPD9/PMCS2/PMA15/RD9                 (MRF24 SS)
    _PPS_IN(_PPS_RPF5),         //  57  RF05    EBIA8/RPF5/SCL5/PMA8/RF5                    (MRF24 SDI)   
    _PPS_IN(_PPS_RPG0),         //  58  RG00    EBID8/RPG0/PMD8/RG0                         (MRF24 SDO)  
    _PPS_IN(_PPS_RPA15),        //  59  RA15    AETXEN/RPA15/SDA1/RA15                      (MRF24 INT)
    _PPS_IN(_PPS_RPG1),         //  60  RG01    EBID9/ETXERR/RPG1/PMD9/RG1                  (MRF24 HIBERNATE)
    _PPS_IN(_PPS_RPF4),         //  61  RF04    EBIA9/RPF4/SDA5/PMA9/RF4                    (MRF24 RESET)
    NOT_PPS_PIN,                //  62  RA01    TCK/EBIA19/AN29/RA1                         (JTAG TCK)
    NOT_PPS_PIN,                //  63  RA00    TMS/EBIA16/AN24/RA0                         (JTAG TMS)
    _PPS_IN(_PPS_RPF12),        //  64  RF12    TDO/EBIA17/AN31/RPF12/RF12                  (JTAG TDO)
    _PPS_IN(_PPS_RPF13),        //  65  RF13    TDI/EBIA18/AN30/RPF13/SCK5/RF13             (JTAG TDI)
    NOT_PPS_PIN,                //  66  RA06    TRCLK/SQICLK/RA6                            (TRACE TRCLK)
    NOT_PPS_PIN,                //  67  RG13    TRD0/SQID0/RG13                             (TRACE TRD0)
    NOT_PPS_PIN,                //  68  RG12    TRD1/SQID1/RG12                             (TRACE TRD1)
    NOT_PPS_PIN,                //  69  RG14    TRD2/SQID2/RG14                             (TRACE TRD2)
    NOT_PPS_PIN,                //  70  RA07    TRD3/SQID3/RA7                              (TRACE TRD3)
};

/* ------------------------------------------------------------ */
/* This table maps from an output compare number as stored in the
** digital_pin_to_timer_PGM table to the digital pin number of the
** pin that OC is connected to. This table is only required for
** devices that support peripheral pin select (PPS), i.e. PIC32MX1xx/2xx
** devices.
*/

const uint8_t output_compare_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,
    PIN_OC1,                  
    PIN_OC2,            
    PIN_OC3,            
    PIN_OC4,            
    PIN_OC5,            
    PIN_OC6,            
};

/* ------------------------------------------------------------ */
/* This table maps from an external interrupt number to the digital
** pin for that interrupt.
*/

const uint8_t external_int_to_digital_pin_PGM[] = {
    NOT_PPS_PIN,        
    PIN_INT1,            
    PIN_INT2,            
    PIN_INT3,            
    PIN_INT4            
};



/* ------------------------------------------------------------ */
/*                Board Customization Functions                    */
/* ------------------------------------------------------------ */
/*                                                                */
/* The following can be used to customize the behavior of some    */
/* of the core API functions. These provide hooks that can be    */
/* used to extend or replace the default behavior of the core    */
/* functions. To use one of these functions, add the desired    */
/* code to the function skeleton below and then set the value    */
/* of the appropriate compile switch above to 1. This will        */
/* cause the hook function to be compiled into the build and    */
/* to cause the code to call the hook function to be compiled    */
/* into the appropriate core function.                            */
/*                                                                */
/* ------------------------------------------------------------ */
/***    _board_init
**
**    Parameters:
**        none
**
**    Return Value:
**        none
**
**    Errors:
**        none
**
**    Description:
**        This function is called from the core init() function.
**        This can be used to perform any board specific init
**        that needs to be done when the processor comes out of
**        reset and before the user sketch is run.
*/
#if    (OPT_BOARD_INIT != 0)

void _board_init(void) {
    
}

#endif

/* ------------------------------------------------------------ */
/***    _board_pinMode
**
**    Parameters:
**        pin        - digital pin number to configure
**        mode    - mode to which the pin should be configured
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the pinMode
**        function. It can perform any special processing needed
**        when setting the pin mode. If this function returns zero,
**        control will pass through the normal pinMode code. If
**        it returns a non-zero value the normal pinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_pinMode(uint8_t pin, uint8_t mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_getPinMode
**
**    Parameters:
**        pin        - digital pin number
**        mode    - pointer to variable to receive mode value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the getPinMode
**        function. It can perform any special processing needed
**        when getting the pin mode. If this function returns zero,
**        control will pass through the normal getPinMode code. If
**        it returns a non-zero value the normal getPinMode code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_getPinMode(uint8_t pin, uint8_t * mode) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalWrite
**
**    Parameters:
**        pin        - digital pin number
**        val        - value to write to the pin
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal digitalWrite code. If
**        it returns a non-zero value the normal digitalWrite code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalWrite(uint8_t pin, uint8_t val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_digitalRead
**
**    Parameters:
**        pin        - digital pin number
**        val        - pointer to variable to receive pin value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the digitalRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal digitalRead code. If
**        it returns a non-zero value the normal digitalRead code isn't
**        executed.
*/
#if    (OPT_BOARD_DIGITAL_IO != 0)

int    _board_digitalRead(uint8_t pin, uint8_t * val) {
    
    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogRead
**
**    Parameters:
**        pin        - analog channel number
**        val        - pointer to variable to receive analog value
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogRead
**        function. It can perform any special processing needed
**        in reading from the pin. If this function returns zero,
**        control will pass through the normal analogRead code. If
**        it returns a non-zero value the normal analogRead code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogRead(uint8_t pin, int * val) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogReference
**
**    Parameters:
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogReference
**        function. It can perform any special processing needed
**        to set the reference voltage. If this function returns zero,
**        control will pass through the normal analogReference code. If
**        it returns a non-zero value the normal analogReference code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_READ != 0)

int    _board_analogReference(uint8_t mode) {

    return 0;

}

#endif

/* ------------------------------------------------------------ */
/***    _board_analogWrite
**
**    Parameters:
**        pin        - pin number
**        val        - analog value to write
**
**    Return Value:
**        Returns 0 if not handled, !0 if handled.
**
**    Errors:
**        none
**
**    Description:
**        This function is called at the beginning of the analogWrite
**        function. It can perform any special processing needed
**        in writing to the pin. If this function returns zero,
**        control will pass through the normal analogWrite code. If
**        it returns a non-zero value the normal analogWrite code isn't
**        executed.
*/
#if (OPT_BOARD_ANALOG_WRITE != 0)

int    _board_analogWrite(uint8_t pin, int val) {

    return 0;

}

#endif

#endif // OPT_BOARD_DATA

/* ------------------------------------------------------------ */

#endif    // BOARD_DATA_C

/************************************************************************/
