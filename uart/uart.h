#ifndef UART_H
#define UART_H

#include<stdint.h>

#define USART1_BASE 0x40011000UL
#define USART2_BASE 0x40004400UL
#define USART6_BASE 0x40011400UL

#define RCC_BASE       0x40023800UL
#define RCC_APB1ENR   *(volatile uint32_t *) (RCC_BASE + 0x40UL )
#define RCC_APB2ENR   *(volatile uint32_t *) (RCC_BASE + 0x44UL )
#define RCC_AHB1ENR   *((volatile uint32_t *)(RCC_BASE + 0x30UL)) //3 bit

/* Declare shared variables; define them in uart/uart.c */
extern char tx_buffer[];
extern char data;

typedef struct
{
	volatile uint32_t USART_SR;
	volatile uint32_t USART_DR;
	volatile uint32_t USART_BRR;
	volatile uint32_t USART_CR1;
	volatile uint32_t USART_CR2;
	volatile uint32_t USART_CR3;
	volatile uint32_t USART_GTPR;
}reg_usart_t;


typedef enum
{
	USART_1,
	USART_2,
	USART_6,
}usart_t;
extern reg_usart_t * type_usart_t[3];
extern void print_invalid_command();
extern uint8_t receive_uart();
extern void transmit_uart();
extern void usart_setup_init();


























#endif