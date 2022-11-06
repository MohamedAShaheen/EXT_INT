/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     EXT_INT                  *****************/
/**************       Version : 1.0                 *****************/
/**************       Date : 22/8/2022              *****************/


/* External Interrupt file guard  */

#ifndef EXTINT_REGISTER_H_ 
#define EXTINT_REGISTER_H_

/*Control Register*/
#define _MCUCR			    *((volatile uint8 *) 0x55 )
/*INT1 Control sense */
#define _MCUCR_ISC11         3        
#define _MCUCR_ISC10		 2

/*INT0 Control sense */
#define _MCUCR_ISC01		 1
#define _MCUCR_ISC00		 0

/*Control Status  Register*/
#define _MCUCSR		    	*((volatile uint8 *) 0x54 )

/*INT2 Control sense */  
#define _MCUCSR_ISC2	    6

/*General Interrupt Control Register */   
#define _GICR				*((volatile uint8 *) 0x5B )

/*Specific Interrupt Enable */
#define _GICR_INT1		   7		
#define _GICR_INT0		   6	
#define _GICR_INT2		   5	

/*General Interrupt Flag Register – GIFR */
#define _GIFR				*((volatile uint8 *) 0x5A )

/*Interrupt flags */
#define _GIFR_INTF1		   7
#define _GIFR_INTF0		   6
#define _GIFR_INTF2		   5
											
											

   
#endif