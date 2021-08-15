/**
 *  \file	Parse.c
 *  \brief	This file includes the implementation of handling 
 *  		the parsing process of the text line.
 *  \author Ahmed Wageh.
 *  \details	It handles the parsing process of the text line to
 *  			get the input text of each switch and the duration of
 *  			pressing for "P" switch. It gets all this as a text.
 */
/* Inclusion */
#include <string.h>
#include "Parse.h"

/* Private functions proto-type */
/**
 *  \brief To prepare the line to be parsed for switch state.
 *  
 *  \param [in] text the text line
 *  \return integer which indecates the number of unhelpful
 *  		characters at the start of the text line
 *  
 *  \details This function gets the number of unhelpful characters
 *  		 at the start of the text line to be skipped when 
 *  		 parsing to get the switch state text.
 */
static int Parse_PrepareForSWState(char * text);

/**
 *  \brief To prepare the line to be parsed for switch duration.
 *  
 *  \param [in] text the text line
 *  \return integer which indecates the number of unhelpful
 *  		characters at the start of the text line
 *  
 *  \details This function gets the number of unhelpful characters
 *  		 at the start of the text line to be skipped when 
 *  		 parsing to get the pressing duration as a text.
 */
static int Parse_PrepareForDuration(char * text);

/**
 *  \brief To get a pure text from a specific line of text
 *  
 *  \param [out] ret_text the pure text extracted from the text line
 *  \param [in] text the whole text line
 *  \return None
 *  
 *  \details This function removes all unused characters from end of
 *  		 the text line to get the pure text input that can be parsed 
 *  		 to get the switch state or duration.
 */
static void Parse_GetText(char * ret_text, char * text);

/**
 *  \brief To get the \ref Switches_States_t from the input \p text line
 *  
 *  \param [in] text the text line
 *  \return None
 *  
 *  \details This function check the \p text to be equal to one of
 *  		 switch states as in \ref Switches_text and then returns
 *  		 the \ref Switches_States_t accoring to the equality check
 *  		 and returns #SWITCH_ERROR if it doesn't match any text.
 */
static Switches_States_t Parse_CheckText(char * text);

/* Functions definition */
/* Private functions definition */
/**
 *  \brief To prepare the line to be parsed for switch state.
 *  
 *  \param [in] text the text line
 *  \return integer which indecates the number of unhelpful
 *  		characters at the start of the text line
 *  
 *  \details This function gets the number of unhelpful characters
 *  		 at the start of the text line to be skipped when 
 *  		 parsing to get the switch state text.
 */
static int Parse_PrepareForSWState(char * text)
{
	/* Needed Variables */
	int offset = 0;

	/* Function logic */
	while (text[offset] != 'p' && text[offset] != 'r')
	{
		offset++;
	}

	return offset;
}

/**
 *  \brief To prepare the line to be parsed for switch duration.
 *  
 *  \param [in] text the text line
 *  \return integer which indecates the number of unhelpful
 *  		characters at the start of the text line
 *  
 *  \details This function gets the number of unhelpful characters
 *  		 at the start of the text line to be skipped when 
 *  		 parsing to get the pressing duration as a text.
 */
static int Parse_PrepareForDuration(char * text)
{
	/* Needed Variables */
	int offset = 0;

	/* Function logic */
	while ((text[offset] < '0' || text[offset] > '9') && text[offset] != '-')
	{
		offset++;
	}

	return offset;
}

/**
 *  \brief To get a pure text from a specific line of text
 *  
 *  \param [out] ret_text the pure text extracted from the text line
 *  \param [in] the whole text line
 *  \return None
 *  
 *  \details This function removes all unused characters from the 
 *  		 text line to get the pure text input that can be parsed 
 *  		 to get the switch state or duration.
 */
static void Parse_GetText(char * ret_text, char * text)
{
	/* Needed Variables */
	int index = 0;
	
	/* Function Logic */
	while ((text[index] >= 'a' && text[index] <= 'z') || text[index] == '_' || 
		(text[index] >= '0' && text[index] <= '9'))
	{
		ret_text[index] = text[index];
		index++;
	}
	ret_text[index] = 0;
}

/**
 *  \brief To get the \ref Switches_States_t from the input \p text line
 *  
 *  \param [in] text the text line
 *  \return None
 *  
 *  \details This function check the \p text to be equal to one of
 *  		 switch states as in \ref Switches_text and then returns
 *  		 the \ref Switches_States_t accoring to the equality check
 *  		 and returns #SWITCH_ERROR if it doesn't match any text.
 */
static Switches_States_t Parse_CheckText(char * text)
{
	/* Needed Variables */
	Switches_States_t retState = SWITCH_ERROR;

	/* Function Logic */
	if (strcmp(text, PRE_PRESSED_TEXT) == 0)
	{
		retState = SWITCH_PRE_PRESSED;
	}
	else if (strcmp(text, PRESSED_TEXT) == 0)
	{
		retState = SWITCH_PRESSED;
	}
	else if (strcmp(text, RELEASED_TEXT) == 0)
	{
		retState = SWITCH_RELEASED;
	}
	else if (strcmp(text, PRE_RELEASED_TEXT) == 0)
	{
		retState = SWITCH_PRE_RELEASED;
	}

	return retState;
}

/* Public functions */
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
void ParseLine(char * Line, char * inc_txt, char * dec_txt, char * p_txt, char * p_time)
{
	/* Function Logic */
	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line);
	Parse_GetText(inc_txt, Line);
	
	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line + strlen(inc_txt)) + strlen(inc_txt);
	Parse_GetText(dec_txt, Line);
	
	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line + strlen(dec_txt)) + strlen(dec_txt);
	Parse_GetText(p_txt, Line);
	
	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForDuration(Line + strlen(p_txt)) + strlen(p_txt);
	Parse_GetText(p_time, Line);
}

/**
 *  \brief To get the real \ref Switches_States_t of "+ve" switch
 *  	   from input text file.
 *  
 *  \param [in] Line "+ve" switch state as text
 *  \return \ref Switches_States_t type data.
 */
Switches_States_t ParseIncSwitch(char * Line)
{
	/* Needed Variables */
	char temp_text[13];
	Switches_States_t retState = SWITCH_ERROR;

	/* Function Logic */
	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line);
	Parse_GetText(temp_text, Line);
	retState = Parse_CheckText(temp_text);

	return retState;
}

/**
 *  \brief To get the real \ref Switches_States_t of "-ve" switch
 *  	   from input text file.
 *  
 *  \param [in] Line "-ve" switch state as text
 *  \return \ref Switches_States_t type data.
 */
Switches_States_t ParseDecSwitch(char * Line)
{
	/* Needed Variables */
	char temp_text[13];
	Switches_States_t retState = SWITCH_ERROR;

	/* Function logic */
	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line);
	Parse_GetText(temp_text, Line);

	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line + strlen(temp_text)) + strlen(temp_text);
	Parse_GetText(temp_text, Line);
	retState = Parse_CheckText(temp_text);

	return retState;
}

/**
 *  \brief To get the real \ref Switches_States_t of "P" switch
 *  	   from input text file.
 *  
 *  \param [in] Line "P" switch state as text
 *  \return \ref Switches_States_t type data.
 */
Switches_States_t ParsePSwitch(char * Line)
{
	/* Needed Variables */
	char temp_text[13];
	Switches_States_t retState = SWITCH_ERROR;

	/* Function Logic */
	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line);
	Parse_GetText(temp_text, Line);

	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line + strlen(temp_text)) + strlen(temp_text);
	Parse_GetText(temp_text, Line);

	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line + strlen(temp_text)) + strlen(temp_text);
	Parse_GetText(temp_text, Line);

	retState = Parse_CheckText(temp_text);

	return retState;
}

/**
 *  \brief To get the real pressing duration of "P" switch from 
 *  	   input text file.
 *  
 *  \param [in] Line duration of "P" switch as text
 *  \return The duration of pressing.
 */
int ParsePDuaration(char * Line)
{
	/* Needed Variables */
	char temp_text[13];
	int retduration = 0;

	/* Function Logic */
	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line);
	Parse_GetText(temp_text, Line);

	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line + strlen(temp_text)) + strlen(temp_text);
	Parse_GetText(temp_text, Line);

	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForSWState(Line + strlen(temp_text)) + strlen(temp_text);
	Parse_GetText(temp_text, Line);

	/* Remove all spaces "\t, while blanks, etc." */
	Line += Parse_PrepareForDuration(Line + strlen(temp_text)) + strlen(temp_text);

	retduration = atoi(Line);

	return retduration;
}