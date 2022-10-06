/*
 * DIO.h
 *
 * Created: 9/16/2022 8:10:48 PM
 *  Author: Kareem Azab
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define num_of_ports           4
#define num_of_pins_per_port   8

#define portA_id               0
#define portB_id               1
#define portC_id               2
#define portD_id               3

#define pin0_id                0
#define pin1_id                1
#define pin2_id                2
#define pin3_id                3
#define pin4_id                4
#define pin5_id                5
#define pin6_id                6
#define pin8_id                7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}DIO_PinDirectionType;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
uint8_t DIO_setupPinDirection(uint8_t port_num, uint8_t pin_num, DIO_PinDirectionType direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
uint8_t DIO_writePin(uint8_t port_num, uint8_t pin_num, uint8_t value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8_t DIO_readPin(uint8_t port_num, uint8_t pin_num);


/*
 * Description :
 * Toggle the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
uint8_t DIO_togglePin(uint8_t port_num, uint8_t pin_num);





#endif /* DIO_H_ */