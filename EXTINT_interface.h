/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     DIO                  *****************/
/**************       Version : 1.0                 *****************/
/**************       Date : 25/4/2022              *****************/

/* file guard */

#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_

											
#define _INT0       0
#define _INT1       1
#define _INT2       2

void EXTINT_voidINIT0(void);
void EXTINT_voidINIT1(void);
void EXTINT_voidINIT2(void);

/* callback take interrupt number , and pointer to function*/
void EXTINT_voidCallBackNotification(uint8 Copy_u8INTNum ,void (*ptr_Func)(void));

#endif