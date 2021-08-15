/**
 *  \file	fake_switch.c
 *  \brief	This file implementation of fake switch module.
 *  \author Ahmed Wageh.
 *  \details This file is used when the need to test switch module.
 *  		 We use "fake_switch" module instead of real module to give
 *  		 us the ability to manipulate the state of switches by using
 *  		 pure C functions to assume any needed test case by just calling
 *  		 switches state setters \ref FAKE_SW_setIncSwState, \ref FAKE_SW_setDecSwState,
 *  		 \ref FAKE_SW_setPSwState, and \ref FAKE_SW_setSwDuration.
 */
/* Include Header File */
#include "fake_switch.h"

/* Switches States */
/**
 *  Fake "+ve" switch state.
 */
static Switches_States_t IncSwitchState;
/**
 *  Fake "-ve" switch state.
 */
static Switches_States_t DecSwitchState;
/**
 *  Fake "p" switch state.
 */
static Switches_States_t PSwitchState;
/**
 *  Fake pressing durarion of "P" switch.
 */
static int P_Switch_Duration;

/* Functions definition */
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
void FAKE_SW_init(void)
{
    IncSwitchState = SWITCH_RELEASED;
    DecSwitchState = SWITCH_RELEASED;
    PSwitchState = SWITCH_RELEASED;
    P_Switch_Duration = 0;
}

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
void FAKE_SW_destroy(void)
{
    /* Nothing to destroy, Just Initialize everything again */
    IncSwitchState = SWITCH_RELEASED;
    DecSwitchState = SWITCH_RELEASED;
    PSwitchState = SWITCH_RELEASED;
    P_Switch_Duration = 0;
}

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
Switches_States_t FAKE_SW_getSwState(Switches_IDs_t ID)
{
	Switches_States_t retData = SWITCH_RELEASED;
	
	switch(ID)
	{
		case SWITCH_INCREMENT:
			retData = IncSwitchState;
		break;

		case SWITCH_DECREMENT:
			retData = DecSwitchState;
		break;

		case SWITCH_P:
			retData = PSwitchState;
		break;
		
		default:;
			/* Error */
	}
	
	return retData;
}

/**
 *  \brief Getting the pressing period of fake "P" switch.
 *  
 *  \param None
 *  \return Pressing duration of fake "P" switch.
 *  
 *  \details This function gets the pressing period of fake "P" switch.
 */
int FAKE_SW_getSwDuration(void)
{
    return P_Switch_Duration;
}

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
void FAKE_SW_setSwState(Switches_IDs_t ID, Switches_States_t state)
{
	switch(ID)
	{
		case SWITCH_INCREMENT:
			IncSwitchState = state;
		break;

		case SWITCH_DECREMENT:
			DecSwitchState = state;
		break;

		case SWITCH_P:
			PSwitchState = state;
		break;
			
		default:;
			/* Error */
	}
}

/**
 *  \brief	Assing pressing duration of the fake "P" switch.
 *  
 *  \param duration is the duration to be assigned.
 *  \return None.
 *  
 *  \details This function sets the duration of the 
 *  		 fake "P" switch to any int number.
 */
void FAKE_SW_setSwDuration(int duration)
{
    P_Switch_Duration = duration;
}