#include "led.h"

struct gpio_register *  gpio_port_array[5] =
{
		(struct gpio_register *) 0x40020000UL,
		(struct gpio_register *) 0x40020400UL,
		(struct gpio_register *) 0x40020800UL,
		(struct gpio_register *) 0x40020C00UL,
		(struct gpio_register *) 0x40020100UL,
};



void gpio_setup_init()
{
	RCC_AHB1ENR = RCC_AHB1ENR |0x00000001UL;
	RCC_AHB1ENR = RCC_AHB1ENR |0x00000008;

	gpio_port_array[PORT_A]->GPIOx_MODER = gpio_port_array[PORT_A]->GPIOx_MODER |(0x000000A0UL);
	gpio_port_array[PORT_A]->GPIOx_AFRL = 0x00007700UL;

	gpio_port_array[PORT_D]->GPIOx_MODER = gpio_port_array[PORT_D]->GPIOx_MODER |(0x55000000UL);
	gpio_port_array[PORT_D]->GPIOx_ODR = gpio_port_array[PORT_D]->GPIOx_ODR& ~(0x0000FF00UL);
}

void gpio_led_on()
{
	gpio_port_array[PORT_D]->GPIOx_ODR = gpio_port_array[PORT_D]->GPIOx_ODR  |(0x0000FF00UL);
}

void gpio_led_off()
{
	gpio_port_array[PORT_D]->GPIOx_ODR = gpio_port_array[PORT_D]->GPIOx_ODR & ~(0x0000FF00UL);
}
// (single definitions of gpio_led_on/gpio_led_off above)