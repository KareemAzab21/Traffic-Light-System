/*
 * TrafficLight.h
 *
 * Created: 9/17/2022 12:01:16 AM
 *  Author: Kareem Azab
 */ 


#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

#include "std_types.h"
#include "../../MCAL/DIODriver/DIO.h"



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define cars_port					portA_id
#define pedestrian_port			    portB_id


#define green_pin					pin0_id
#define yellow_pin					pin1_id
#define red_pin						pin2_id





/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/



/*
 * Description :
 * Setup the direction of Traffic Lights Pins both the Cars and the Pedestrians .
 * If the input port number or pin number are not correct, The function will not handle the request.
 */

uint8_t TrafficLight_init(void);


/*
 * Description :
 * The function turn to pedestrian mode.
 * The function will be called when the button of the pedestrian is pressed
 */
uint8_t TrafficLight_PedestrainMode(void);


/*
 * Description :
 * Turn The light green of the car on
 */
uint8_t TrafficLight_GreenCarOn(void);
/*
 * Description :
 * Turn The light yellow of the car on
 */
uint8_t TrafficLight_YellowCarOn(void);
/*
 * Description :
 * Turn The light red of the car on
 */
uint8_t TrafficLight_RedCarOn(void);
/*
 * Description :
 * Turn The light green of the Pedestrian on
 */
uint8_t TrafficLight_GreenPedOn(void);
/*
 * Description :
 * Turn The light Yellow of the Pedestrian on
 */
uint8_t TrafficLight_YellowPedOn(void);
/*
 * Description :
 * Turn The light red of the Pedestrian on
 */
uint8_t TrafficLight_RedPedOn(void);
/*
 * Description :
 * Turn The light green of the car off
 */
uint8_t TrafficLight_GreenCarOff(void);
/*
 * Description :
 * Turn The light yellow of the car off
 */
uint8_t TrafficLight_YellowCarOff(void);
/*
 * Description :
 * Turn The light red of the car off
 */
uint8_t TrafficLight_RedCarOff(void);
/*
 * Description :
 * Turn The light green of the Pedestrian off
 */
uint8_t TrafficLight_GreenPedOff(void);
/*
 * Description :
 * Turn The light Yellow of the Pedestrian off
 */
uint8_t TrafficLight_YellowPedOff(void);
/*
 * Description :
 * Turn The light red of the Pedestrian off
 */
uint8_t TrafficLight_RedPedOff(void);
/*
 * Description :
 * It toggles the yellow car light
 */
uint8_t TrafficLight_ToggleYellowCar(void);
/*
 * Description :
 * It toggles the yellow pedestrian light
 */
uint8_t TrafficLight_ToggleYellowPed(void);
/*
 * Description :
 * return whether the green light is on or off
 */
uint8_t TrafficLight_IsGreenCarOn(void);
/*
 * Description :
 * return whether the red light is on or off
 */
uint8_t TrafficLight_IsRedCarOn(void);
/*
 * Description :
 * return whether the yellow light is on or off
 */
uint8_t TrafficLight_IsYellowCarOn(void);
/*
 * Description :
 * return whether the green light of the pedestrian is on or off
 */
uint8_t TrafficLight_IsGreenPedOn(void);
/*
 * Description :
 * return whether the red light of the pedestrian is on or off
 */
uint8_t TrafficLight_IsRedPedOn(void);
/*
 * Description :
 * return whether the yellow light is on or off
 */
uint8_t TrafficLight_IsYellowPedOn(void);


#endif /* TRAFFICLIGHT_H_ */