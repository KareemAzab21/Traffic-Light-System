/*
 * TrafficLight.c
 *
 * Created: 9/17/2022 12:02:08 AM
 *  Author: Kareem Azab
 */ 
#include "TrafficLight.h"
#include "../../MCAL/Timer0/Timer0.h"





/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
uint8_t TrafficLight_init(void){
	Status status;
	// adjusting Pin directions;
	status= DIO_setupPinDirection( cars_port,green_pin,PIN_OUTPUT );
	status =DIO_setupPinDirection( cars_port,yellow_pin,PIN_OUTPUT );
	status= DIO_setupPinDirection( cars_port,red_pin,PIN_OUTPUT );
	status = DIO_setupPinDirection( pedestrian_port,green_pin,PIN_OUTPUT );
	status = DIO_setupPinDirection( pedestrian_port,yellow_pin,PIN_OUTPUT );
	status =DIO_setupPinDirection( pedestrian_port,red_pin,PIN_OUTPUT );
	
	//initialize the lights off
	status =DIO_writePin( cars_port,green_pin,LOGIC_HIGH );
	status =DIO_writePin( cars_port,yellow_pin,LOGIC_HIGH );
	status =DIO_writePin( cars_port,red_pin,LOGIC_HIGH);
	status =DIO_writePin( pedestrian_port,green_pin,LOGIC_HIGH) ;
	status = DIO_writePin( pedestrian_port,yellow_pin,LOGIC_HIGH );
	status = DIO_writePin( pedestrian_port,red_pin,LOGIC_HIGH );
	
	return status;
		
}


/*
 * Description :
 * Turn The light green of the car on
 */
uint8_t TrafficLight_GreenCarOn(void){
	
	Status status = DIO_writePin( cars_port,green_pin,LOGIC_LOW );
	return status;
	
}

/*
 * Description :
 * Turn The light yellow of the car on
 */
uint8_t TrafficLight_YellowCarOn(void){
	
	Status status =DIO_writePin( cars_port,yellow_pin,LOGIC_LOW );
	return status;
}

/*
 * Description :
 * Turn The light red of the car on
 */
uint8_t TrafficLight_RedCarOn(void){
	Status status = DIO_writePin( cars_port,red_pin,LOGIC_LOW );
	return status;
	
}


/*
 * Description :
 * Turn The light green of the Pedestrian on
 */
uint8_t TrafficLight_GreenPedOn(void){
	
	Status status = DIO_writePin( pedestrian_port,green_pin,LOGIC_LOW );
	return status;
	
}

/*
 * Description :
 * Turn The light Yellow of the Pedestrian on
 */

uint8_t TrafficLight_YellowPedOn(void){
	
	Status status = DIO_writePin( pedestrian_port,yellow_pin,LOGIC_LOW );
	return status;
}


/*
 * Description :
 * Turn The light red of the Pedestrian on
 */
uint8_t TrafficLight_RedPedOn(void){
	Status status =DIO_writePin( pedestrian_port,red_pin,LOGIC_LOW );
	return status;
	
}


/*
 * Description :
 * Turn The light green of the car off
 */
uint8_t TrafficLight_GreenCarOff(void){
	Status status =DIO_writePin( cars_port,green_pin,LOGIC_HIGH );
	return status;
	
}


/*
 * Description :
 * Turn The light yellow of the car off
 */
uint8_t TrafficLight_YellowCarOff(void){
	Status status =DIO_writePin( cars_port,yellow_pin,LOGIC_HIGH );
	return status;
}

/*
 * Description :
 * Turn The light red of the car off
 */
uint8_t TrafficLight_RedCarOff(void){
	Status status =DIO_writePin( cars_port,red_pin,LOGIC_HIGH );
	return status;
}


/*
 * Description :
 * Turn The light green of the Pedestrian off
 */
uint8_t TrafficLight_GreenPedOff(void){
	Status status =DIO_writePin( pedestrian_port,green_pin,LOGIC_HIGH );
	return status;
}


/*
 * Description :
 * Turn The light Yellow of the Pedestrian off
 */
uint8_t TrafficLight_YellowPedOff(void){
	
	Status status = DIO_writePin( pedestrian_port,yellow_pin,LOGIC_HIGH );
	return status;
}

/*
 * Description :
 * Turn The light red of the Pedestrian off
 */
uint8_t TrafficLight_RedPedOff(void){
	Status status = DIO_writePin( pedestrian_port,red_pin,LOGIC_HIGH );
	return status;
}

/*
 * Description :
 * return whether the green light is on or off
 */
uint8_t TrafficLight_IsGreenCarOn(void)
{
	
	uint8_t result=DIO_readPin(cars_port,green_pin);
	return result;
}
/*
 * Description :
 * return whether the red light is on or off
 */
uint8_t TrafficLight_IsRedCarOn(void)
{
	uint8_t result= DIO_readPin(cars_port,red_pin);
	return result;
}
/*
 * Description :
 * return whether the yellow light is on or off
 */
uint8_t TrafficLight_IsYellowCarOn(void)
{
	uint8_t result= DIO_readPin(cars_port,yellow_pin);
	return result;
}
/*
 * Description :
 * return whether the green light of the pedestrian is on or off
 */
uint8_t TrafficLight_IsGreenPedOn(void)
{
	uint8_t result= DIO_readPin(pedestrian_port,green_pin);
	return result;
}
/*
 * Description :
 * return whether the red light of the pedestrian is on or off
 */
uint8_t TrafficLight_IsRedPedOn(void)
{
	uint8_t result =DIO_readPin(pedestrian_port,red_pin);
	return result;
}
/*
 * Description :
 * return whether the yellow light is on or off
 */
uint8_t TrafficLight_IsYellowPedOn(void)
{
	uint8_t result= DIO_readPin(pedestrian_port,yellow_pin);
	
}

/*
 * Description :
 * It toggles the yellow car light
 */
uint8_t TrafficLight_ToggleYellowCar(void)
{
	Status status = DIO_togglePin(cars_port,yellow_pin);
	return status;
}
/*
 * Description :
 * It toggles the yellow pedestrian light
 */
uint8_t TrafficLight_ToggleYellowPED(void)
{
	Status status =DIO_togglePin(pedestrian_port,yellow_pin);
	return status;
}

uint8_t TrafficLight_PedestrainMode(void){
	if(TrafficLight_IsRedCarOn()==LOGIC_LOW)
	{
		
		TrafficLight_GreenCarOff();
		TrafficLight_YellowCarOff();
		TrafficLight_GreenPedOn();
		TrafficLight_YellowPedOff();
		TrafficLight_RedPedOff();
		Timer0_Delay(5);//delay 5 seconds
		
		
		
		

		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_YellowCarOff();
		TrafficLight_YellowPedOff();
		
		TrafficLight_RedCarOff();
		TrafficLight_GreenPedOff();
		TrafficLight_GreenCarOn();
		TrafficLight_RedPedOn();
		
		
		
		return OK;
		
	}
	else if((TrafficLight_IsGreenCarOn()==LOGIC_LOW) || (TrafficLight_IsYellowCarOn()==LOGIC_LOW) || ((TrafficLight_IsGreenCarOn()==LOGIC_HIGH)&& (TrafficLight_IsYellowCarOn()==LOGIC_HIGH)))
	{
		TrafficLight_RedPedOn();
		TrafficLight_GreenCarOff();
		TrafficLight_RedCarOff();
		TrafficLight_YellowCarOff();
		TrafficLight_YellowPedOff();
		TrafficLight_GreenPedOff();
		
		
		//toggles both yellow lights
		
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_YellowCarOff();
		TrafficLight_YellowPedOff();
		TrafficLight_RedPedOff();
		
		
		
		TrafficLight_GreenPedOn();
		TrafficLight_RedCarOn();
		Timer0_Delay(5);
		TrafficLight_RedCarOff();
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_ToggleYellowCar();
		TrafficLight_ToggleYellowPED();
		Timer0_Delay(1);
		TrafficLight_YellowCarOff();
		TrafficLight_YellowPedOff();
		
		TrafficLight_GreenCarOn();
		TrafficLight_GreenPedOff();
		
		TrafficLight_RedPedOn();
		return OK;
		
		
	}
	else
	{
		return NOT_OK;
	}
	
}

