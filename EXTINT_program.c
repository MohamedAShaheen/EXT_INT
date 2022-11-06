/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     DIO                  *****************/
/**************       Version : 1.0                 *****************/
/**************       Date : 25/4/2022              *****************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTINT_interface.h"
#include "EXTINT_register.h"
#include "EXTINT_private.h"
#include "EXTINT_config.h"

/*global pointer to function */
static void (*Global_pvFunc0)(void);
static void (*Global_pvFunc1)(void);
static void (*Global_pvFunc2)(void);


void EXTINT_voidINIT0(void){
	
	/*Control Sense : LOW_LEVEL*/
	#if   INT1_SENSE_CONTROL == LOW_LEVEL
	  CLR_BIT(_MCUCR , _MCUCR_ISC00);
	  CLR_BIT(_MCUCSR, _MCUCR_ISC01);
	
	/*Control Sense : ON_CHANGE*/
	#elif INT1_SENSE_CONTROL == ON_CHANGE
	  SET_BIT(_MCUCR , _MCUCR_ISC00);
	  CLR_BIT(_MCUCSR, _MCUCR_ISC01);
	
	/*Control Sense : FALLING_EDGE*/
	#elif INT1_SENSE_CONTROL == FALLING_EDGE
	  CLR_BIT(_MCUCR , _MCUCR_ISC00);
	  SET_BIT(_MCUCSR, _MCUCR_ISC01);
	
	/*Control Sense : RISING Edge*/
	#elif INT1_SENSE_CONTROL == RISING_EDGE
	  SET_BIT(_MCUCR , _MCUCR_ISC00);
	  SET_BIT(_MCUCSR, _MCUCR_ISC01);
	
	#endif
	
	/*ENABLE PIE */
	SET_BIT(_GICR, _GICR_INT0);
	
}

void EXTINT_voidINIT1(void){
	
	/*Control Sense : LOW_LEVEL*/
	#if   INT1_SENSE_CONTROL == LOW_LEVEL
	   CLR_BIT(_MCUCR , _MCUCR_ISC11);
	   CLR_BIT(_MCUCSR, _MCUCR_ISC10);
	   
	/*Control Sense : HIGH_LEVEL*/
	#elif INT1_SENSE_CONTROL == HIGH_LEVEL
	   CLR_BIT(_MCUCR , _MCUCR_ISC11);
	   SET_BIT(_MCUCSR, _MCUCR_ISC10);
	   
	/*Control Sense : FALLING_EDGE*/
	#elif INT1_SENSE_CONTROL == FALLING_EDGE
	    SET_BIT(_MCUCR , _MCUCR_ISC11);
	    CLR_BIT(_MCUCSR, _MCUCR_ISC10);
	
	/*Control Sense : RISING Edge*/
	#elif INT1_SENSE_CONTROL == RISING_EDGE
	    SET_BIT(_MCUCR , _MCUCR_ISC11);
	    SET_BIT(_MCUCSR, _MCUCR_ISC10);
		
	#endif
	
	/*ENABLE  PRIPHERAL INT1 */
	SET_BIT(_GICR, _GICR_INT1);
}

void EXTINT_voidINIT2(void){
	/*Control Sense : RISING Edge*/
	#if INT1_SENSE_CONTROL == RISING_EDGE
	
	/*Control Sense : FALLING Edge*/
	#elif INT1_SENSE_CONTROL == FALLING_EDGE
	
	#endif
	
	/*ENABLE PE */
	SET_BIT(_GICR, _GICR_INT2);
}

/* CALL BACK FUNC */
void EXTINT_voidCallBackNotification(uint8 Copy_u8INTNum , void (*ptr_Func)(void)){
	
	/*prebuild config */
	if (Copy_u8INTNum==_INT0)
	{
		Global_pvFunc0=ptr_Func;
	} 
	else if (Copy_u8INTNum==_INT1)
	{
		Global_pvFunc1=ptr_Func;
	}
	
	else if (Copy_u8INTNum==_INT2)
	{
		Global_pvFunc2=ptr_Func;
	}
	
}


/*ISR FOR EXTINT0*/
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void){
	
	Global_pvFunc0();
	
}

/*ISR FOR EXTINT2*/
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	
	Global_pvFunc2();
}

/*ISR FOR EXTINT1*/
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	
	Global_pvFunc1();
}