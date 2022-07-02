/*****************************************/
/*	Author	:	Omar 					 */
/* 	Date	:	26 JUN 2022				 */
/*	Version	: 	01 						 */
/*****************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(reg,bit) 		reg |= (1<<(bit))
#define CLR_BIT(reg,bit)		reg &=~(1<<(bit))
#define GET_BIT(reg,bit)		((reg>>bit) & 1 )
#define TOG_BIT(reg,bit)		reg ^= (1<<(bit))

#endif