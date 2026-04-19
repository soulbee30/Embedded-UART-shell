#include"uart.h"

/* Define shared variables declared in uart.h */
char tx_buffer[] = "INVALID COMMAND";
char data = '\0';

reg_usart_t * type_usart_t[3] =
{
	(volatile reg_usart_t *)USART1_BASE,
	(volatile reg_usart_t *)USART2_BASE,
	(volatile reg_usart_t *)USART6_BASE,
};

void usart_setup_init()
{

	RCC_APB1ENR |= (1UL << 17);

	type_usart_t[USART_2]->USART_CR1 |= 0x0000200CUL;
	type_usart_t[USART_2]->USART_BRR = 0x008BUL;
	type_usart_t[USART_2]->USART_DR |= 0x0UL;
	type_usart_t[USART_2]->USART_CR1 |= 0x00000000UL;
}


void print_invalid_command()
{
  for (int j = 0; tx_buffer[j] != '\0'; j++)
		{
			while (!(type_usart_t[USART_2]->USART_SR & (1U << 7)));
			type_usart_t[USART_2]->USART_DR = tx_buffer[j];
		}
    
}

uint8_t receive_uart()
{
    while((type_usart_t[USART_2]->USART_SR & (1U << 5)))
	{
		data = type_usart_t[USART_2]->USART_DR;
		return 1;
	}
	return 0;
}

void transmit_uart()
{
    while (!(type_usart_t[USART_2]->USART_SR & (1U << 7)));
				type_usart_t[USART_2]->USART_DR = data;
}