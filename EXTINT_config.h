/********************************************************************/
/********************************************************************/
/**************       Author : Moahmed A Shaheen     *****************/
/**************       Layer : MCAL                  *****************/
/**************       SWC:     EXTINT               *****************/
/**************       Version : 1.0                 *****************/
/**************       Date : 25/4/2022              *****************/

#ifndef  EXTINT_CONFIG_H_
#define  EXTINT_CONFIG_H_

/*CONTROL SENSE */
/*Select 
  LOW_LEVEL  or   HIGH_LEVEL  or  FALLING_EDGE  or  RISING_EDGE 
    */
#define  INT1_SENSE_CONTROL     RISING_EDGE

#define  INT0_SENSE_CONTROL     FALLING_EDGE

/*Select 
LOW_LEVEL or  FALLING_EDGE  or  RISING_EDGE  or   ON_CHANGE
*/

#define  INT2_SENSE_CONTROL     FALLING_EDGE

#endif