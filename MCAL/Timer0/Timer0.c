/*
 * Timer0.c
 *
 * Created: 9/16/2022 9:55:04 PM
 *  Author: Kareem Azab
 */ 
#include "Timer0.h"
#include "avr/io.h"


uint8_t Timer0_init(const Timer0_ConfigType *Config_Ptr){
	if(Config_Ptr==NULL_PTR){
		return NOT_OK;
	}
	else{
		/*set the initialize value of the timer*/
		TCNT0=Config_Ptr->intialize_value;
		/*
		* Active FOCO bit to specify non-PWM mode
		* set the Wave Form Generation Mode
		* set the COM01 COM00  that controls the OC0 behavior
		* Clock Select
		* */
		TCCR0=(1<<FOC0)| (0xFF & (Config_Ptr->mode <<3)) | (0xFF & (Config_Ptr->mode<<4))  | (0xFF & (Config_Ptr->mode<<5)) | (0xFF & (Config_Ptr->clock));
		if(Config_Ptr->mode==CTC)
		{
			 OCR0=Config_Ptr->compare_value;
		}
		return OK;
	}
}

/*
 * Description: Disable Timer0.
 */
uint8_t Timer0_Deinit(void){
	/*Clear the value*/
	TCNT0=0;
	OCR0=0;

	/*Stop the clock*/
	TCCR0 = (TCCR0 & 0xF8);
	return OK;
}

void Timer0_Delay(uint32_t seconds){
	
	uint32_t s= seconds*2;	/* the flag rises every 1/2 seconds so we double the input variable*/
	uint32_t tick=0;
	while(tick<s){
		while((TIFR&0x01)==0); 
		TIFR = 0x1;  		/* Clear TOV0 flag*/
		tick++;
	}
}