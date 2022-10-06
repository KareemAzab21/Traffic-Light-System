/*
 * DIO.c
 *
 * Created: 9/16/2022 8:11:05 PM
 *  Author: Kareem Azab
 */ 


#include "DIO.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "avr/io.h" /* To use the IO Ports Registers */





/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
uint8_t DIO_setupPinDirection(uint8_t port_num, uint8_t pin_num, DIO_PinDirectionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= num_of_pins_per_port) || (port_num >= num_of_ports))
	{
		return NOT_OK;
	}
	else
	{
		/* Setup the pin direction as required */
		switch(port_num)
		{
		case portA_id:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			return OK;
			break;
		case portB_id:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			return OK;
			break;
		case portC_id:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			return OK;
			break;
		case portD_id:
			if(direction == PIN_OUTPUT)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			return OK;
			break;
		}
	}
}




/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
uint8_t DIO_writePin(uint8_t port_num, uint8_t pin_num, uint8_t value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= num_of_pins_per_port) || (port_num >= num_of_ports))
	{
		return NOT_OK;
	}
	else
	{
		/* Write the pin value as required */
		switch(port_num)
		{
		case portA_id:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			return OK;
			break;
		case portB_id:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			return OK;
			break;
		case portC_id:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			return OK;
			break;
		case portD_id:
			if(value == LOGIC_HIGH)
			{
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			return OK;
			break;
		}
	}
}




/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8_t DIO_readPin(uint8_t port_num, uint8_t pin_num)
{
	uint8_t pin_value = LOGIC_LOW;

	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if((pin_num >= num_of_pins_per_port) || (port_num >= num_of_ports))
	{
		return NOT_OK;
	}
	else
	{
		/* Read the pin value as required */
		switch(port_num)
		{
		case portA_id:
			if(BIT_IS_SET(PINA,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case portB_id:
			if(BIT_IS_SET(PINB,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case portC_id:
			if(BIT_IS_SET(PINC,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		case portD_id:
			if(BIT_IS_SET(PIND,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
			{
				pin_value = LOGIC_LOW;
			}
			break;
		}
	}

	return pin_value;
}




/*
 * Description :
 * Toggle the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
uint8_t DIO_togglePin(uint8_t port_num, uint8_t pin_num)
{
	/*
	* Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	* Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	* In this case the input is not valid port/pin number
	*/
	if((pin_num >= num_of_pins_per_port) || (port_num >= num_of_ports))
	{
		return NOT_OK;
	}
	else
	{
	/* Toggle the pin value as required */
	switch(port_num)
	{
	case portA_id:
		TOGGLE_BIT(PORTA,pin_num);
		return OK;
		break;
	case portB_id:
		TOGGLE_BIT(PORTB,pin_num);
		return OK;
		break;
	case portC_id:
		TOGGLE_BIT(PORTC,pin_num);
		return OK;
		break;
	case portD_id:
		TOGGLE_BIT(PORTD,pin_num);
		return OK;
		break;
	}
 }
}