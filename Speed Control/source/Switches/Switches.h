/**
 *  \file	Switches.h
 *  \brief	This file is a driver for the switches.
 *  \author Ahmed Wageh.
 */
#ifndef SWITCHES_H_
#define SWITCHES_H_
/* Macros */
/**
 *  \defgroup Switches_text Switches text
 *  This is the text presented in input file text
 *  @{
 */
/** Pre Pressed state text */
#define PRE_PRESSED_TEXT	"pre_pressed"
/** Pressed state text */
#define PRESSED_TEXT		"pressed"
/** Released state text */
#define RELEASED_TEXT		"released"
/** Pre Released state text */
#define PRE_RELEASED_TEXT	"pre_released"
/**
 *  @}
 */

/* User-defined data types */
/**
 *  This enum is for the switch states for any used switch.
 */
enum Switches_IDs_t
{
	/** The ID of "+ve" switch */
	SWITCH_INCREMENT = 0,
	/** The ID of "-ve" switch */
	SWITCH_DECREMENT,
	/** The ID of "P" switch */
	SWITCH_P,
};
typedef enum Switches_IDs_t Switches_IDs_t;

/**
 *  This enum is for the switch states for any used switch.
 */
enum Switches_States_t
{
	/** Indicates that there is an  error in reading the switch state */
	SWITCH_ERROR = 0,
	/** The switch is in pre pressed state */
	SWITCH_PRE_PRESSED = 1,
	/** The switch is in pressed state */
	SWITCH_PRESSED = 2,
	/** The switch is in release state */
	SWITCH_RELEASED = 3,
	/** The switch is in pre release state */
	SWITCH_PRE_RELEASED = 4
};
typedef enum Switches_States_t Switches_States_t;

/**
 *  This enum is for updating switch state error codes.
 */
enum Switches_UpdateState_t
{
	/** There is an error in updating switches state */
	SWITCH_UPDATE_ERROR = 0,
	/** Updating state done successfully */
	SWITCH_UPDATE_OK = 1
};
typedef enum Switches_UpdateState_t Switches_UpdateState_t;

/* Fyunctions proto-type */
/**
 *  \brief This function for initializing all used switches.
 *  
 *  \param	None.
 *  \return None.
 *  
 *  \details This functions prepares the input file to be ready 
 *  		 for reading process, setting \ref Switches_GetIncrementSwitchState,
 *  		 \ref Switches_GetDecrementSwitchState, \ref Switches_GetPSwitchState,
 *  		 and \ref Switches_GetPDuration to the real functions that reads the data 
 *  		 from input text file.
 */
void Switches_Init(void);

/**
 *  \brief This function updates the redings of all used switches.
 *  
 *  \return \ref Switches_UpdateState_t type data
 *  
 *  \details This function get the reading of the switches from its
 *  		 assigned getter(real or fake getter) and afterthat you
 *  		 can get the \ref Switches_States_t from \ref Switches_GetIncrementSwitchState,
 *  		 \ref Switches_GetDecrementSwitchState, and ref Switches_GetPSwitchState or 
 *  		 get the duration of the pressing on "P" switch from 
 *  		 \ref Switches_GetPDuration.  		 
 */
Switches_UpdateState_t Switches_UpdateState(void);

/**
 *  \brief For getting the \ref Switches_States_t of any switch.
 *  
 *  \param ID : The \ref Switches_IDs_t of the needed switch 
 *  			to get \ref Switches_States_t.
 *  \return \ref Switches_States_t type data.
 *  
 *  \details It must be called after \ref Switches_UpdateState function.
 */
extern Switches_States_t (*Switches_GetState)(Switches_IDs_t ID);

/**
 *  \brief For getting the pressing duration of "P" switch.
 *  
 *  \param None.
 *  \return integer type data represents the duration of pressing.
 *  
 *  \details It must be called after \ref Switches_UpdateState function.
 */
extern int (*Switches_GetPDuration)(void);

#endif // !SWITCHES_H_
