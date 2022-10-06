/*
 * Timer0.h
 *
 * Created: 9/16/2022 9:54:42 PM
 *  Author: Kareem Azab
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_types.h"



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/



typedef enum{
	NORMAL,CTC
}Timer0_Mode;

typedef enum{
	NO_CLOCK,CLK_1,CLK_8,CLK_64,CLK_256,CLK_1024
}Timer0_Clock;

typedef struct{
	Timer0_Mode mode;
	Timer0_Clock clock;
	uint8_t intialize_value;
	uint8_t compare_value;
}Timer0_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description: Initialize the timer0 with the configured mode.
 */
uint8_t Timer0_init(const Timer0_ConfigType *Config_Ptr);


/*
 * Description: Disable Timer0.
 */
uint8_t Timer0_Deinit(void);
/*
 * Description: Delay Function
 * it takes the number of seconds as an input of the function
 */
void Timer0_Delay(uint32_t seconds);




#endif /* TIMER0_H_ */