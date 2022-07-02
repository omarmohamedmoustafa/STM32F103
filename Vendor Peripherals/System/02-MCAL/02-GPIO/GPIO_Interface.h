/**********************************************************/
/*				Author	:	Omar						  */
/*				DATE	:	01 JULY 2022				  */
/*				VERSION	:	01							  */
/**********************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

void GPIO_voidSetPinDir(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinDir);
void GPIO_voidSetPortDir(u8 Copy_u8PortId, u8 Copy_u8PortDir);
void GPIO_voidSetPinVal(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinVal);
u8 GPIO_u8GetPinVal(u8 Copy_u8PortId, u8 Copy_u8PinId);
u32 GPIO_u8GetPortVal(u8 Copy_u8PortId);

#define GPIO_HIGH		1
#define GPIO_LOW		0

#define GPIO_PORT_OUT	0xFFFF
#define GPIO_PORT_IN	0x0000

#define GPIO_PORT_HIGH	0xFFFF
#define GPIO_PORT_LOW	0x0000

#define GPIOA 			0
#define GPIOB 			1
#define GPIOC 			2
	
#define GPIO_PIN0 		0
#define GPIO_PIN1 		1
#define GPIO_PIN2		2
#define GPIO_PIN3		3
#define GPIO_PIN4 		4
#define GPIO_PIN5		5
#define GPIO_PIN6		6
#define GPIO_PIN7 		7
#define GPIO_PIN8 		8
#define GPIO_PIN9 		9
#define GPIO_PIN10 		10
#define GPIO_PIN11 		11
#define GPIO_PIN12 		12
#define GPIO_PIN13		13
#define GPIO_PIN14 		14
#define GPIO_PIN15 		15



#endif
