/**
 *  \file	FileIf.h
 *  \brief	This file handles the interfacing with input 
 *  		text file and output text file.
 *  \author Ahmed Wageh.
 *  \details	It handles the reading and writing operations.
 */
#ifndef FILE_IF_H_
#define FILE_IF_H_
/* Inclusion */
#include <stdio.h>

/* Macros */
/**	This is the full path of input text file */
#define FILE_IF_INPUT_FILE_FULL_PATH	"switches.txt"
/**	This is the full path of output text file */
#define FILE_IF_OUTPUT_FILE_FULL_PATH	"motor.txt"


/* User-defined Data Types */
/**	
 *  This enum for error types that could happens when
 *  interacting with any text file
 */
enum FileIf_Error_t{
	/** Interaction done correctly */
    FILE_IF_ERROR_OK = 0,
	/** Can't open the file */
    FILE_IF_ERROR_CAN_NOT_OPEN = 1,
	/** Can't read data from the file */
    FILE_IF_ERROR_CAN_NOT_READ = 2,
	/** Can't write data to the file */
    FILE_IF_ERROR_CAN_NOT_WRITE = 3,
	/** Reaches the end of file */
	FILE_IF_ERROR_END_OF_FILE = 4
};
typedef enum FileIf_Error_t FileIf_Error_t;

/* Functions prototypes */
/**	
 *  \brief 		This is considered as initialization function 
 *				for output file.
 *	\param		None.
 *	\return		None.
 *  \details	It creates the file if it doesn't exist or 
 *  			clear it to be ready for writing if it exists.
 */
void File_PrepareOutputFile(void);

/**	
 *  \brief 		This is considered as initialization function 
 *				for input file. 
 *	\param		None.
 *	\return		None.
 *	\details	It opens the file and read its header to be 
 *				ready for reading process.
 */
void File_PrepareInputFile(void);

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
FileIf_Error_t File_ReadLine(char * Return_Reference);
 
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
FileIf_Error_t File_WriteLine(int Data);
#endif // FILE_IF_H_
