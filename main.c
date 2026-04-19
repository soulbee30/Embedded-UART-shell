
#include <stdint.h>
#include<string.h>

#include "led.h"
#include "uart.h"

void state_machine(char rxbuffer[]);
static char rxbuffer[20];
int main(void)
{
	gpio_setup_init();
	usart_setup_init();
	

	int i = 0;
	

	/* Loop forever */
	while(1)
	{
		//	blocking CPU from doing other task
		if(receive_uart())
		{
			if (data == '\r')  // end of string
			{
				rxbuffer[i] = '\0';  // terminate
				state_machine(rxbuffer);
				i = 0; // reset buffer
			}
			else
			{
				transmit_uart();
				
				if (i < sizeof(rxbuffer) - 1)
				{
					rxbuffer[i++] = data;
				}
			}
		}
	}
}

void state_machine( char rxbuffer[])
{
	if(strcmp(rxbuffer,"LEDON") == 0)
	{
		gpio_led_on();
	}
	else if(strcmp(rxbuffer,"LEDOFF") == 0)
	{
		gpio_led_off();
	}
	else
	{
		print_invalid_command();
	}


}
