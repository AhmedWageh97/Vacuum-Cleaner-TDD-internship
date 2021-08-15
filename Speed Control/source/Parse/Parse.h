/**
 *  \file	Parse.h
 *  \brief	This file handles the parsing process of the text line.
 *  \author Ahmed Wageh.
 *  \details	It handles the parsing process of the text line to
 *  			get the input text of each switch and the duration of
 *  			pressing for "P" switch. It gets all this as a text.
 */
#ifndef PARSE_H_
#define PARSE_H_
/* Inclusion */
#include "../Switches/Switches.h"

/* User-defined data types */
/**	
 *  This enum for error types that could happens when
 *  parsing any text line
 */
enum Parse_Error_t
{
	/** Parsing done sucessfully */
	PARSE_ERROR_OK = 0,
	/** There is unexpected string in the text line */
	PARSE_ERROR_UNEXPECTED_STRING = 1
};
typedef enum Parse_Error_t Parse_Error_t;

/* Functions prototype */
/**
 *  \brief This function for parsing any text line.
 *  
 *  \param [in] Line The line needed to be parsed 
 *  \param [out] inc_txt the "+ve" switch state as a text
 *  \param [out] dec_txt the "-ve" switch state as a text
 *  \param [out] p_txt the "P" switch state as a text
 *  \param [out] p_time the "P" switch pressing duration as a text
 *  \return \ref Parse_Error_t type data
 *  
 *  \details This function parsing the \p Line which has the form of:
 *  		 "+ve" sw state    "-ve" sw state  "p" sw state P sw duration
 *  		 and gets the states of switches and duration as a text in
 *  		 \p inc_txt, \p dec_txt, \p p_txt, and \p p_time. Afterthat
 *  		 you need to call \ref ParseIncSwitch , or \ref ParseDecSwitch,
 *  		 \ref ParsePSwitch, or \ref ParsePDuaration to get the real state
 *  		 in \ref Switches_States_t type or duration in  integer form.
 */
void ParseLine(char * Line, char * inc_txt, char * dec_txt, 
			char * p_txt, char * p_time);

/**
 *  \brief To get the real \ref Switches_States_t of "+ve" switch
 *  	   from input text file.
 *  
 *  \param [in] Line "+ve" switch state as text
 *  \return \ref Switches_States_t type data.
 */
Switches_States_t ParseIncSwitch(char * Line);

/**
 *  \brief To get the real \ref Switches_States_t of "-ve" switch
 *  	   from input text file.
 *  
 *  \param [in] Line "-ve" switch state as text
 *  \return \ref Switches_States_t type data.
 */
Switches_States_t ParseDecSwitch(char * Line);

/**
 *  \brief To get the real \ref Switches_States_t of "P" switch
 *  	   from input text file.
 *  
 *  \param [in] Line "P" switch state as text
 *  \return \ref Switches_States_t type data.
 */
Switches_States_t ParsePSwitch(char * Line);

/**
 *  \brief To get the real pressing duration of "P" switch from 
 *  	   input text file.
 *  
 *  \param [in] Line duration of "P" switch as text
 *  \return The duration of pressing.
 */
int ParsePDuaration(char * Line);

#endif // !PARSE_H_
