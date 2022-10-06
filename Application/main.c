/*
 * main.c
 *
 * Created: 9/18/2022 2:23:33 AM
 *  Author: Kareem Azab
 */

#include "../ECUAL/Button/Button.h"
#include "../ECUAL/TrafficLight/TrafficLight.h"
#include "../MCAL/Timer0/Timer0.h "
#include "Application.h"
#include "avr/io.h"
#include "avr/interrupt.h"



int main()
{
	Status status;
	status = TrafficLight_init();
	Timer0_ConfigType Timer_Config = {NORMAL,CLK_1024,0,0};
	status= Timer0_init(&Timer_Config);
	status = Button_init();
	SREG|=(1<<7);
	
	
	
	while(1){
		status =Application_startapp();
	}
	
	
} 
