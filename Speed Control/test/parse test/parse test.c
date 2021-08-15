/**
 *  \file	parse_test.c
 *  \brief	This file includes test cases for parsing text files.
 *  \author Ahmed Wageh
 *  
 *  \details This file tests the parsing operations for text files
 *  		 to get the switches \ref Switches_States_t and "P" switch
 *  		 pressing duration from the text line.
 */
#include <stdio.h>
#include <string.h>

/* Include tested module header file */
#include "../../source/Parse/Parse.h"

/* Include Unity */
#include "../unity/unity_fixture.h"

/* Test group declaration */
TEST_GROUP(parseing_test);

/* parseing_test group setup and tear_down function */
TEST_SETUP(parseing_test)
{
	
}

TEST_TEAR_DOWN(parseing_test)
{

}

/* Test cases implementation */
/**
 *  \defgroup parsing_test Text parsing test
 *  This is for testing the functionality of parsing module
 *  
 *  \details It tests the following functionalities:
 *  	-	getting_inc_button_text_correctly: To get the \ref
 *  		Switches_States_t of "+ve" switch from text line correctly.
 *  	-	getting_dec_button_text_correctly: To get the \ref
 *  		Switches_States_t of "-ve" switch from text line correctly.
 *  	-	getting_p_duration_correctly: To get the pressing duration 
 *  		of "P" switch from text line correctly.
 *  	-	getting_p_duration_MULTI_DIGIT_NUMBER: To get the pressing duration 
 *  		of "P" switch from text line correctly, when it's more than 1 digit.
 *  	-	getting_p_duration_Negative_Number: To get the pressing duration 
 *  		of "P" switch from text line correctly, when it's negative number.
 *  @{
 */
/**
 *  \brief	Test case for parsing a text line to get "+ve" 
 *  		switch reading correctly
 *  
 *  \details Here we test the parsing operation by passing 
 *  		 simple text line with the same format as the 
 *  		 format of the input text line of switches text 
 *  		 file and try to parse it using parsing module
 *  		 to get the \ref Switches_States_t of "+ve" switch.
 *  		 We make the state to be "pre_released" and expect
 *  		 the result to be #SWITCH_PRE_RELEASED after parsing.
 */
TEST(parseing_test, getting_inc_button_text_correctly)
{
    /* Needed variables */
    Switches_States_t expected_state = SWITCH_PRE_RELEASED;
    char text[] = "pre_released			released			pre_pressed				0";    /* Creating a line of text */


    LONGS_EQUAL(expected_state, ParseIncSwitch(text));
}

/**
 *  \brief	Test case for parsing a text line to get "-ve" 
 *  		switch reading correctly
 *  
 *  \details Here we test the parsing operation by passing 
 *  		 simple text line with the same format as the 
 *  		 format of the input text line of switches text 
 *  		 file and try to parse it using parsing module
 *  		 to get the \ref Switches_States_t of "-ve" switch.
 *  		 We make the state to be "pre_released" and expect
 *  		 the result to be #SWITCH_PRE_RELEASED after parsing.
 */
TEST(parseing_test, getting_dec_button_text_correctly)
{
   /* Needed variables */
    Switches_States_t expected_state = SWITCH_RELEASED;
    char text[] = "pre_released			released			pre_pressed				0";    /* Creating a line of text */


    LONGS_EQUAL(expected_state, ParseDecSwitch(text));
}

/**
 *  \brief	Test case for parsing a text line to get "P" 
 *  		switch reading correctly
 *  
 *  \details Here we test the parsing operation by passing 
 *  		 simple text line with the same format as the 
 *  		 format of the input text line of switches text 
 *  		 file and try to parse it using parsing module
 *  		 to get the \ref Switches_States_t of "P" switch.
 *  		 We make the state to be "pre_released" and expect
 *  		 the result to be #SWITCH_PRE_RELEASED after parsing.
 */
TEST(parseing_test, getting_p_button_text_correctly)
{
   /* Needed variables */
    Switches_States_t expected_state = SWITCH_PRE_PRESSED;
    char text[] = "pre_released			released			pre_pressed				0";    /* Creating a line of text */


    LONGS_EQUAL(expected_state, ParsePSwitch(text));
}

/**
 *  \brief	Test case for parsing a text line to get pressing duration of 
 *  		"P" switch correctly
 *  
 *  \details Here we test the parsing operation by passing 
 *  		 simple text line with the same format as the 
 *  		 format of the input text line of switches text 
 *  		 file and try to parse it using parsing module.
 *  		 We make the pressing duration = 0 and expect the 
 *  		 result also to be 0 after parsing.
 */
TEST(parseing_test, getting_p_duration_correctly)
{
   /* Needed variables */
    int expected_duration = 0;
    char text[] = "pre_released			released			pre_pressed				0";    /* Creating a line of text */


    LONGS_EQUAL(expected_duration, ParsePDuaration(text));
}

/**
 *  \brief	Test case for parsing a text line to get pressing duration of 
 *  		"P" switch correctly(Multi digit input)
 *  
 *  \details Here we test the parsing operation by passing 
 *  		 simple text line with the same format as the 
 *  		 format of the input text line of switches text 
 *  		 file and try to parse it using parsing module.
 *  		 We make the pressing duration(multi digit number) 
 *  		 = 12 and expect the result also to be 12 after parsing.
 */
TEST(parseing_test, getting_p_duration_MULTI_DIGIT_NUMBER)
{
   /* Needed variables */
    int expected_duration = 12;
    char text[] = "pre_released			released			pre_pressed				12";    /* Creating a line of text */


    LONGS_EQUAL(expected_duration, ParsePDuaration(text));
}

/**
 *  \brief	Test case for parsing a text line to get pressing duration of 
 *  		"P" switch correctly(negative input number)
 *  
 *  \details Here we test the parsing operation by passing 
 *  		 simple text line with the same format as the 
 *  		 format of the input text line of switches text 
 *  		 file and try to parse it using parsing module.
 *  		 We make the pressing duration(multi digit number) 
 *  		 = -12754 and expect the result also to be -12754 
 *  		 after parsing.
 */
TEST(parseing_test, getting_p_duration_Negative_Number)
{
   /* Needed variables */
    int expected_duration = -12754;
    char text[] = "pre_released			released			pre_pressed				-12754";    /* Creating a line of text */


    LONGS_EQUAL(expected_duration, ParsePDuaration(text));
}
/**
 *  @}
 */

/**
 *  \brief Test code runner for all test techniques for parsing module.
 */
TEST_GROUP_RUNNER(parseing_test)
{
    printf("======================= Testing Parse Module =======================\n\n");
    RUN_TEST_CASE(parseing_test, getting_inc_button_text_correctly);
    RUN_TEST_CASE(parseing_test, getting_dec_button_text_correctly);
    RUN_TEST_CASE(parseing_test, getting_p_button_text_correctly);
    RUN_TEST_CASE(parseing_test, getting_p_duration_correctly);
    RUN_TEST_CASE(parseing_test, getting_p_duration_MULTI_DIGIT_NUMBER);
    RUN_TEST_CASE(parseing_test, getting_p_duration_Negative_Number);
    printf("\n==================== Testing Parse  Module Done ====================\n\n\n");
}
