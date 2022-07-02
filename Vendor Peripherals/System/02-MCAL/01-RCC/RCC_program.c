/***********************************************/
/*	Author	:	Omar						   */
/*	Date	:	26 JUN 2022					   */
/*	Version	:	01							   */
/***********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSysClock(void)
{/*	H3ml if condition 3la el choice bta3
	 *	el developer zmily elly hwa e5taro mn config.h
	 *	w h3ml el if mn no3 el prepocessor directive
	 *	34an mta5od4 space zy el if el3adya l2n el
	 *	preprocessor directive 3obara 3n text replacement
	*/

	#if	RCC_CLOCK_TYPE 	==	RCC_HSE_CRYSTAL
		RCC_CR 		 = 0x00010000;
		RCC_CFGR	 = 0x00000001;
	#elif RCC_CLOCK_TYPE==	RCC_HSE_RC
		RCC_CR 		 = 0x00050000;
		RCC_CFGR	 = 0x00000001;
	#elif RCC_CLOCK_TYPE	==	RCC_HSI
		RCC_CR 		 = 0x00000081;
		RCC_CFGR	 = 0x00000000;
	#elif RCC_CLOCK_TYPE	==	RCC_PLL
		#if RCC_PLL_INPUT	==	RCC_PLL_IN_HSI_DIV_2
			RCC_CR 		 = 0x01000000;
			RCC_CFGR	 = 0x00000002;
		#elif RCC_PLL_INPUT 	== 	RCC_PLL_IN_HSE
			RCC_CR 		 = 0x01000000;
			RCC_CFGR	 = 0x00010002;
		#elif RCC_PLL_INPUT 	== 	RCC_PLL_IN_HSE_DIV_2
			RCC_CR 		 = 0x01000000;
			RCC_CFGR	 = 0x00020002;
	#endif
	#else
		#error("You DidNot Choose Right type of Clock")
	
	#endif
}


void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB	:	SET_BIT(RCC_AHBENR	,Copy_u8PerId);	break;
			case RCC_APB1	:	SET_BIT(RCC_APB1ENR	,Copy_u8PerId);	break;
			case RCC_APB2	:	SET_BIT(RCC_APB2ENR	,Copy_u8PerId);	break;
		}
	}
	else
	{
		/*Report Error*/
	}
}


void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			case RCC_AHB	:	CLR_BIT(RCC_AHBENR	,Copy_u8PerId);	break;
			case RCC_APB1	:	CLR_BIT(RCC_APB1ENR	,Copy_u8PerId);	break;
			case RCC_APB2	:	CLR_BIT(RCC_APB2ENR	,Copy_u8PerId);	break;
		}
	}
	else
	{
		/*Report Error*/
	}
}
