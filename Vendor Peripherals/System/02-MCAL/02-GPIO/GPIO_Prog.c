/**********************************************************/
/*	Author	:	Omar									  */
/*	DATE	:	01 JULY 2022							  */
/*	VERSION	:	02										  */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
/*We have untill now 4 registers CRL - CRH - IDR - ODR */
/*CRL&CRH are registers to carry each port pins Mode and configuration */
/*for example pin0 in portA is asked to be input push-pull */
/*Input : 00 Push-pull : 00 so we need to right 0b0000 in CRL of portA*/
void GPIO_voidSetPinDir(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDir)
{
	if (Copy_u8PortId <= GPIOC)
	{
		switch(Copy_u8PortId)
		{
			case(GPIOA):
				if(Copy_u8PinId<=7)
				{	/*clear current PIN 4bits MODE first*/
					GPIOA_CRL &= ~((0b1111)<<(Copy_u8PinId*4));
					/*SET THE MODE SENT BY USER*/
					GPIOA_CRL |= (Copy_u8PinDir<<(Copy_u8PinId*4));
				}
				else if (Copy_u8PinId <=15)/*FOR UPPER 8 PINS of same PORT*/
				{
					/*clear current PIN 4bits MODE first*/
					GPIOA_CRH &= ~((0b1111)<<((Copy_u8PinId-8)*4));
					/*SET THE MODE SENT BY USER*/
					GPIOA_CRH |= (Copy_u8PinDir<<((Copy_u8PinId-8)*4));
				}
				break;
			case(GPIOB):
				if(Copy_u8PinId<=7)
				{	/*clear current (PIN 4bits) MODE first*/
					GPIOB_CRL &= ~((0b1111)<<(Copy_u8PinId*4));
					/*SET THE MODE SENT BY USER*/
					GPIOB_CRL |= (Copy_u8PinDir<<(Copy_u8PinId*4));
				}
				else if (Copy_u8PinId <=15)/*FOR UPPER 8 PINS of same PORT*/
				{
					/*clear current (PIN 4bits) MODE first*/
					GPIOB_CRH &= ~((0b1111)<<((Copy_u8PinId-8)*4));
					/*SET THE MODE SENT BY USER*/
					GPIOB_CRH |= (Copy_u8PinDir<<((Copy_u8PinId-8)*4));
				}
			
				break;
			case(GPIOC):
				if(Copy_u8PinId<=7)
				{	/*clear current (PIN 4bits) MODE first*/
					GPIOC_CRL &= ~((0b1111)<<(Copy_u8PinId*4));
					/*SET THE MODE SENT BY USER*/
					GPIOC_CRL |= (Copy_u8PinDir<<(Copy_u8PinId*4));
				}
				else if (Copy_u8PinId <=15)/*FOR UPPER 8 PINS of same PORT*/
				{
					/*clear current (PIN 4bits) MODE first*/
					GPIOC_CRH &= ~((0b1111)<<((Copy_u8PinId-8)*4));
					/*SET THE MODE SENT BY USER*/
					GPIOC_CRH |= (Copy_u8PinDir<<((Copy_u8PinId-8)*4));
				}
				
				break;

		}
		
	}
	
}

void GPIO_voidSetPortDir(u8 Copy_u8PortId, u8 Copy_u8PortDir)
{
	if(Copy_u8PortId <= GPIOC)
	{
		switch(Copy_u8PortId)
		{
			case(GPIOA):
				if(Copy_u8PortDir == GPIO_HIGH)
				{
					GPIOA_ODR = 0xFFFF;
				}
				else if(Copy_u8PortDir == GPIO_LOW)
				{
					GPIOA_ODR = 0x0000;
				}
			break;

			case(GPIOB):
				if(Copy_u8PortDir == GPIO_HIGH)
				{
					GPIOB_ODR = 0xFFFF;
				}
				else if(Copy_u8PortDir == GPIO_LOW)
				{
					GPIOB_ODR = 0x0000;
				}
			break;

			case(GPIOC):
				if(Copy_u8PortDir == GPIO_HIGH)
				{
					GPIOA_ODR = 0xFFFF;
				}
				else if(Copy_u8PortDir == GPIO_LOW)
				{
					GPIOA_ODR = 0x0000;
				}
			break;
		}
	}
}

void GPIO_voidSetPinVal(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinVal)
{	/*HERE WE ARE ASKED TO SET PIN VAL (HI-LO)*/
	/*so we will need to work with ODR*/
	if (Copy_u8PortId <= GPIOC)
	{
		switch(Copy_u8PortId)
		{
			case(GPIOA):
				if (Copy_u8PinVal == GPIO_HIGH)
				{
					SET_BIT(GPIOA_ODR,Copy_u8PinId);
				}
				else if(Copy_u8PinVal == GPIO_LOW)
				{
					CLR_BIT(GPIOA_ODR,Copy_u8PinId);
				}
				break;
			case(GPIOB):
				if (Copy_u8PinVal == GPIO_HIGH)
				{
					SET_BIT(GPIOB_ODR,Copy_u8PinId);
				}
				else if(Copy_u8PinVal == GPIO_LOW)
				{
					CLR_BIT(GPIOB_ODR,Copy_u8PinId);
				}
				break;
			case(GPIOC):
				if (Copy_u8PinVal == GPIO_HIGH)
				{
					SET_BIT(GPIOC_ODR,Copy_u8PinId);
				}
				else if(Copy_u8PinVal == GPIO_LOW)
				{
					CLR_BIT(GPIOC_ODR,Copy_u8PinId);
				}
				break;
		
		}
	}
}

		


u8 GPIO_u8GetPinVal(u8 Copy_u8PortId, u8 Copy_u8PinId)
{/*Since its a get fuction : we need to declare a local variable for return value*/
	/*******LOCAL VARIABLE MUST BE DECLARED********/
	/*we are reading pin value so we use IDR register*/
	u8 LOC_u8RETURN_VAL = 0;
	if(Copy_u8PortId <= GPIOC)
	{
		switch(Copy_u8PortId)
		{
			case(GPIOA):
			LOC_u8RETURN_VAL = GET_BIT(GPIOA_IDR,Copy_u8PinId);
			break;
			case(GPIOB):
			LOC_u8RETURN_VAL = GET_BIT(GPIOB_IDR,Copy_u8PinId);
			break;
			
			case(GPIOC):
			LOC_u8RETURN_VAL = GET_BIT(GPIOC_IDR,Copy_u8PinId);
			break;
			
		}
		
	}
	
	return LOC_u8RETURN_VAL;
}

//u32 GPIO_u8GetPortVal(u8 Copy_u8PortId)
//{
	
//}
