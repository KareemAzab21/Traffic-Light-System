/*
 * Button.c
 *
 * Created: 9/17/2022 9:13:57 PM
 *  Author: Kareem Azab
 */ 

#include "Button.h"
#include "../TrafficLight/TrafficLight.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>





uint8_t click=0;
/*
 * Description :
 * initialize the pin direction and and enable the external interrupt 
 */

ISR(INT0_vect)

{
	click++;
	_delay_ms(300);
	if(DIO_readPin(button_port,button_pin)==LOGIC_LOW)
	{
		//do nothing because long press
	}
	else
	{
			if(click==1){
				Status status =TrafficLight_PedestrainMode();
			}
			
	}
	click=0;
					
}



uint8_t Button_init(void)
{
	DDRD&=(~(1<<PD2));
	PORTD|=(1<<PD2);
	MCUCR|=(1<<ISC01);
	MCUCR&=(~(1<<ISC00));
	GICR|=(1<<INT0);
	return OK;

		
}






