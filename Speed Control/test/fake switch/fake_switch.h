/**
 *  \file	fake_switch.h
 *  \brief	This file provides function to fake the state of switches
 *  		and the pressing duration of "P" switch.
 *  \author Ahmed Wageh.
 *  \details This file is used when the need to test switch module.
 *  		 We use "fake_switch" module instead of real module to give
 *  		 us the ability to manipulate the state of switches by using
 *  		 pure C functions to assume any needed test case by just calling
 *  		 switches state setters \ref FAKE_SW_setIncSwState, \ref FAKE_SW_setDecSwState,
 *  		 \ref FAKE_SW_setPSwState, and \ref FAKE_SW_setSwDuration.
 */
#ifndef FAKE_SWITCH_H_
#define FAKE_SWITCH_H_
/* Include Real Switch module header file to expose Types */
#include "../../source/Switches/Switches.h"

/**
 *  \brief Initializing the fake switch module
 *
 *  \param None.
 *  \return None.
 *
 *  \details This function initializes fake switch module by
 *  		 setting the state of all switches to be #SWITCH_RELEASED
 *  		 and making the pressing duration to be 0.
 */
void       FAKE_SW_init(void);

/**
 *  \brief Destroying the fake switch module
 *
 *  \param None.
 *  \return None.
 *
 *  \details This function destroies fake switch module by
 *  		 setting the state of all switches to be #SWITCH_RELEASED
 *  		 and making the pressing duration to be 0.
 */
void       FAKE_SW_destroy(void);

/**
 *  \brief	Getting the fake \ref Switches_States_t of 
 *  		switch with ID = \ref ID.
 *  
 *  \param ID : The \ref Switches_IDs_t of the needed switch 
 *  			to get \ref Switches_States_t.
 *
 *  \return \ref Switches_States_t type data
 *
 *  \details This function gets the state of fake switch with
 *  		 \ref Switches_IDs_t = \ref ID.
 */
Switches_States_t FAKE_SW_getSwState(Switches_IDs_t ID);

/**
 *  \brief Getting the pressing period of fake "P" switch.
 *
 *  \param None
 *  \return Pressing duration of fake "P" switch.
 *
 *  \details This function gets the pressing period of fake "P" switch.
 */
int FAKE_SW_getSwDuration(void);

/**
 *  \brief	Assigning a \ref Switches_States_t to the fake
 *  		switch with \ref Switches_IDs_t = \ref ID.
 *
 *  \param state :	is the state to be assigned.
 *  \param ID : The \ref Switches_IDs_t of the needed switch 
 *  			to set \ref Switches_States_t.
 *  \return None.
 *
 *  \details This function sets the state of fake switch with
 *  		 \ref Switches_IDs_t of \ref ID to any 
 *  		 \ref Switches_States_t state.
 */
void FAKE_SW_setSwState(Switches_IDs_t ID, Switches_States_t state);

/**
 *  \brief	Assigning pressing duration of the fake "P" switch.
 *
 *  \param duration is the duration to be assigned.
 *  \return None.
 *
 *  \details This function sets the duration of the
 *  		 fake "P" switch to any int number.
 */
void FAKE_SW_setSwDuration(int duration);
#endif /* FAKE_SWITCH_H_ */
