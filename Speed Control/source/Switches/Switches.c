/**
 *  \file	Switches.c
 *  \brief	This file is the implementation of the driver
 *  		for the switches.
 *  \author Ahmed Wageh.
 */
/* Inclusion */
#include <stdio.h>
#include <string.h>
#include "Switches.h"
#include "../File If/FileIf.h"
#include "../Parse/Parse.h"

/* Private variables */
/** The state of "+ve" switch, initially it's released */
static Switches_States_t Switch_Inc = SWITCH_RELEASED;
/** The state of "-ve" switch, initially it's released */
static Switches_States_t Switch_Dec = SWITCH_RELEASED;
/** The state of "P" switch, initially it's released */
static Switches_States_t Switch_P = SWITCH_RELEASED;
/** The pressing duration "p" switch, initially it's zero */
static int Switch_P_Duration = 0;

/* Private functions prototype */
/**
 *  \brief	Gets the \ref Switches_States_t of all switches
 *  		and pressing duration of "P" switch from input
 *  		text line.
 *
 *  \param [in] Input_Line input text line to be parsed
 *  \param [out] Inc_Switch the \ref Switches_States_t of "+ve" switch
 *  \param [out] Dec_Switch the \ref Switches_States_t of "-ve" switch
 *  \param [out] P_Switch the \ref Switches_States_t of "P" switch
 *  \param [out] P_Duaration The duration of "P" switch
 *  \return None
 *
 *  \details It parsed the input text line and assign the result to
 *  		 out parameter: \p Inc_Switch, \p Dec_Switch, \p P_Switch
 *  		 and \p P_Duaration.
 */
static void Switches_GetSwitchesState(char * Input_Line, Switches_States_t * Inc_Switch,
	Switches_States_t * Dec_Switch, Switches_States_t * P_Switch,
	int * P_Duaration);

/**
 *  \brief	The real function for getting the state from a
 *  		switch with \ref Switches_IDs_t = \p ID.
 *  
 *  \param ID :	The \ref Switches_IDs_t of switch you need to 
 *  			get state.
 *
 *  \return \ref Switches_States_t type data
 */
Switches_States_t Switches_GetSwitchState_real(Switches_IDs_t ID);

/**
 *  \brief  The real getting function of pressing duration of
 *  		"P" switch that gets the real duration from input
 *  		text file.
 *
 *  \return pressing duration
 */
int Switches_GetPDuration_real(void);

Switches_States_t (*Switches_GetState)(Switches_IDs_t ID);
int (*Switches_GetPDuration)(void);


/* Functions definition */
/* Private functions */
/**
 *  \brief	Gets the \ref Switches_States_t of all switches
 *  		and pressing duration of "P" switch from input
 *  		text line.
 *
 *  \param [in] Input_Line input text line to be parsed
 *  \param [out] Inc_Switch the \ref Switches_States_t of "+ve" switch
 *  \param [out] Dec_Switch the \ref Switches_States_t of "-ve" switch
 *  \param [out] P_Switch the \ref Switches_States_t of "P" switch
 *  \param [out] P_Duaration The duration of "P" switch
 *  \return None
 *
 *  \details It parsed the input text line and assign the result to
 *  		 out parameter: \p Inc_Switch, \p Dec_Switch, \p P_Switch
 *  		 and \p P_Duaration.
 */
static void Switches_GetSwitchesState(char * Input_Line, Switches_States_t * Inc_Switch,
	Switches_States_t * Dec_Switch, Switches_States_t * P_Switch,
	int * P_Duaration)
{
	*Inc_Switch = ParseIncSwitch(Input_Line);
	*Dec_Switch = ParseDecSwitch(Input_Line);
	*P_Switch = ParsePSwitch(Input_Line);
	*P_Duaration = ParsePDuaration(Input_Line);
}

/**
 *  \brief	The real function for getting the state from a
 *  		switch with \ref Switches_IDs_t = \p ID.
 *  
 *  \param ID :	The \ref Switches_IDs_t of switch you need to 
 *  			get state.
 *
 *  \return \ref Switches_States_t type data
 */
Switches_States_t Switches_GetSwitchState_real(Switches_IDs_t ID)
{
	Switches_States_t retData = SWITCH_RELEASED;

	switch(ID)
	{
		case SWITCH_INCREMENT:
			retData = Switch_Inc;
		break;

		case SWITCH_DECREMENT:
			retData = Switch_Dec;
		break;

		case SWITCH_P:
			retData = Switch_P;
		break;

		default:;
			/* Error */
	}

	return retData;
}

/**
 *  \brief  The real getting function of pressing duration of
 *  		"P" switch that gets the real duration from input
 *  		text file.
 *
 *  \return pressing duration
 */
int Switches_GetPDuration_real(void)
{
	return Switch_P_Duration;
}

/* Public functions */
/**
 *  \brief This function for initializing all used switches.
 *
 *  \param	None.
 *  \return None.
 *
 *  \details This functions prepares the input file to be ready
 *  		 for reading process, setting \ref Switches_GetState,
 *  		 and \ref Switches_GetPDuration to the real functions 
 *  		 that reads the data from input text file.
 */
void Switches_Init(void)
{
	File_PrepareInputFile();
	Switches_GetState = Switches_GetSwitchState_real;
	Switches_GetPDuration = Switches_GetPDuration_real;
}

/**
 *  \brief This function updates the redings of all used switches.
 *
 *  \return \ref Switches_UpdateState_t type data
 *
 *  \details This function get the reading of the switches from its
 *  		 assigned getter(real or fake getter) and afterthat you
 *  		 can get the \ref Switches_States_t from \ref Switches_GetState and
 *  		 get the duration of the pressing on "P" switch from
 *  		 \ref Switches_GetPDuration.
 */
Switches_UpdateState_t Switches_UpdateState(void)
{
	/* Needed variables */
	char txt[84];
	Switches_UpdateState_t retState = SWITCH_UPDATE_OK;

	/* Function logic */
	if (File_ReadLine(txt) == FILE_IF_ERROR_OK)
	{
		Switches_GetSwitchesState(txt, &Switch_Inc, &Switch_Dec, &Switch_P, &Switch_P_Duration);
	}
	else
	{
		retState = SWITCH_UPDATE_ERROR;
	}

	return retState;
}
