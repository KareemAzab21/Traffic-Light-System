/*
 * Button.h
 *
 * Created: 9/17/2022 9:13:10 PM
 *  Author: Kareem Azab
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define button_port    portD_id
#define button_pin     pin2_id




/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/



/*
 * Description :
 * initialize the pin direction and and enable the external interrupt 
 */

uint8_t  Button_init(void);

#endif /* BUTTON_H_ */