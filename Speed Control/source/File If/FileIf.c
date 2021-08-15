/**
 *  \file	FileIf.c
 *  \brief	This file includes the implementation of handling
 *  		the interfacing with input text file and output
 *  		text file.
 *  \author Ahmed Wageh
 */
/* Inclusion */
#include "FileIf.h"
#include <string.h>

/* Private variables */
/** For holding the input file handler */
static FILE * File_Input_File_Handler = NULL;
/** For holding the output file handler */
static FILE * File_Output_File_Handler = NULL;

/* Functions definition */
/**
 *  \brief 		This is considered as initialization function
 *				for output file.
 *	\param		None.
 *	\return		None.
 *  \details	It creates the file if it doesn't exist or
 *  			clear it to be ready for writing if it exists.
 */
void File_PrepareOutputFile(void)
{
	if (File_Output_File_Handler == NULL)	/* The file haven't been opened ever */
	{
		File_Output_File_Handler = fopen(FILE_IF_OUTPUT_FILE_FULL_PATH, "w");	/* Create and open the file */
		fprintf(File_Output_File_Handler, "Motor angle\n");	/* Print file header */
		fclose(File_Output_File_Handler);
	}
}

/**
 *  \brief 		This is considered as initialization function
 *				for input file.
 *	\param		None.
 *	\return		None.
 *	\details	It opens the file and read its header to be
 *				ready for reading process.
 */
void File_PrepareInputFile(void)
{
	/* Needed Variables */
	char tempdata;
	int tempRet;

	/* Function Logic */
	if (File_Input_File_Handler == NULL)	/* The file haven't been opened ever */
	{
		File_Input_File_Handler = fopen(FILE_IF_INPUT_FILE_FULL_PATH, "r");	/* Open the file */
		do /* Read the header */
		{
			tempRet = fscanf(File_Input_File_Handler, "%c", &tempdata);
		} while (tempdata != '\n' && tempRet != EOF);	/* If line ends or file ends */
	}
}

/**
 *  \brief 	This function used to read a line of text from
 *  		input file.
 *
 *  \param [out] 	Return_Reference char * for holding the
 *  				return text line.
 *
 *  \return \ref FileIf_Error_t type data.
 *
 *  \details 	It reads the next line from the input file text
 *  			and return an error code:
 *  			- #FILE_IF_ERROR_OK: Reading done successfully
 *  			- #FILE_IF_ERROR_CAN_NOT_OPEN: Can't open the
 *  											input file.
 *  			- #FILE_IF_ERROR_CAN_NOT_READ: Can't read from the
 *  											input file.
 *  			- #FILE_IF_ERROR_END_OF_FILE:	Reaches the end of file.
 *
 */
FileIf_Error_t File_ReadLine(char * Return_Reference)
{
    /* Needed data types */
    FileIf_Error_t retData = FILE_IF_ERROR_OK;
    char tempdata;
    int index = 0;
	int tempRet;

	/* Function Logic */
	if(File_Input_File_Handler == NULL)	/* If the file couldn't open */
    {
        retData = FILE_IF_ERROR_CAN_NOT_OPEN;
        //printf("Can't Open The File\n");
    }
	else
	{
		tempRet = fscanf(File_Input_File_Handler, "%c", &tempdata);	/* Read the first character */
		if (tempRet == EOF)	/* Check End Of File (EOF) */
		{
			retData = FILE_IF_ERROR_END_OF_FILE;
			//printf("End Of File\n");
			fclose(File_Input_File_Handler);
		}
		else
		{
			do /* Continue Reading */
			{
				Return_Reference[index] = tempdata;
				index++;
				tempRet = fscanf(File_Input_File_Handler, "%c", &tempdata);
			} while (tempdata != '\n' && tempRet != EOF);	/* If line ends or file ends */

			Return_Reference[index] = 0;	/* End the string with Null terminator */
			if (tempRet == EOF)	/* Close the file if it ends */
			{
				//printf("End Of File\n");
				fclose(File_Input_File_Handler);
			}
		}
	}

    return retData;
}

/**
 *  \brief This function used to write calculated data to output file.
 *
 *  \param [in] Data the data needed to be written to output file.
 *  \return \ref FileIf_Error_t type data.
 *
 *  \details It writes a calculated data to output file text
 *  			and return an error code:
 *  			- #FILE_IF_ERROR_OK: Reading done successfully
 *  			- #FILE_IF_ERROR_CAN_NOT_OPEN: Can't open the
 *  											output file.
 *  			- #FILE_IF_ERROR_CAN_NOT_WRITE: Can't write to
 *  											 the output file.
 *
 */
FileIf_Error_t File_WriteLine(int Data)
{
	/* Needed variables */
	FileIf_Error_t retData = FILE_IF_ERROR_OK;	/* For returning error identification */

	/* Function Logic */
	File_Output_File_Handler = fopen(FILE_IF_OUTPUT_FILE_FULL_PATH, "a");
	if (fprintf(File_Output_File_Handler, "%d\n", Data) < 0)	/* Error in writing */
	{
		retData = FILE_IF_ERROR_CAN_NOT_WRITE;
	}
	fclose(File_Output_File_Handler);

	return retData;
}
