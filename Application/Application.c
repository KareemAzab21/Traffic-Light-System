/*
 * Application.c
 *
 * Created: 9/18/2022 1:15:17 AM
 *  Author: Kareem Azab
 */ 

#include "Application.h"
#include "std_types.h"
#include "../ECUAL/Button/Button.h"
#include "../ECUAL/TrafficLight/TrafficLight.h"
#include "../MCAL/Timer0/Timer0.h"
#include <util/delay.h>



/*
 * Description :
 * Startup the application with the normal traffic lights until the button is pressed
 */
uint8_t Application_startapp(void)
{
		Status status;
		status = TrafficLight_GreenCarOn();

		status = TrafficLight_RedPedOn();
		Timer0_Delay(5);
		status = TrafficLight_GreenCarOff();
		status = TrafficLight_RedPedOff();
		status = TrafficLight_YellowCarOn();
		

		status = TrafficLight_RedPedOn();
		status = TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status =TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status = TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status = TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status = TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status = TrafficLight_YellowCarOff();
		status = TrafficLight_RedPedOff();
		status = TrafficLight_RedCarOn();
		

		status= TrafficLight_GreenPedOn();
		Timer0_Delay(5);
		status =TrafficLight_RedCarOff();
		status =TrafficLight_GreenPedOff();
		
		status =TrafficLight_RedPedOn();
		status = TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status = TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status = TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status = TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status = TrafficLight_ToggleYellowCar();
		Timer0_Delay(1);
		status = TrafficLight_YellowCarOff();
		status = TrafficLight_RedPedOff();
		

	return status;
	
}
