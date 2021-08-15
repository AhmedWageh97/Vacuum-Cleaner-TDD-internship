/**
 *  \file	main.c
 *  \brief	This is the main code for the project.
 *  \author Ahmed Wageh.
 */
/* Inclusion */
#include <stdio.h>
#include <stdlib.h>
#include "File If/FileIf.h"
#include "Motor/Motor.h"
#include "Switches/Switches.h"
#include "Speed Control/SpeedControl.h"
/* Include Unity */
#include "../test/unity/unity_fixture.h"

#define MAKE_UNITY_VERBOSE	argc = 2; argv[1] = "-v"


/* Test Groups Runner */
 /**
 *  \brief This is all needed test cases to test our modules.
 */
 void RunAllTests(void)
{
    RUN_TEST_GROUP(parseing_test);
    RUN_TEST_GROUP(FakeSwitch);
    RUN_TEST_GROUP(motor_test);
    RUN_TEST_GROUP(speed_control_test);
}

/** New speed to be applied to the motor */
int newSpeed;

/**
 *  \brief Main program body
 *
 *  \details This is the main code to run.
 */
int main(int argc, char * argv[])
{
    /* Manipulate argc & argv to make unity verbose*/
    MAKE_UNITY_VERBOSE;

    /* Call Unity Main */
    UnityMain(argc, argv, RunAllTests);

    printf("App is running..\n");

	/* Program initialization */
    Motor_Init();	/* Init the motor */
	Switches_Init();	/* Init the Switches */

	/* 	Continue updating the state of switches until it's not
		available (Until the end of file here)*/
	while (Switches_UpdateState() == SWITCH_UPDATE_OK)
	{
		/* Calculate new speed depend on switchs state and current speed */
		newSpeed = SpeedControl_CalcNewSpeed();
		/* Assign new speed to the motor */
		Motor_UpdateSpeed(newSpeed);
	}

	/* End of project */
	printf("Done\n");
    return 0;
}
/**
 *  \mainpage Vacuum Cleaner  Project
 *  
 *  \section project_description_section Project description
 *  This project simulates the vacuum cleaner using C language. It assumes
 *  that we have 3 switch: #SWITCH_INCREMENT, #SWITCH_DECREMENT, and 
 *  #SWITCH_P. Every switch has a certain job as follows:
 *  -	#SWITCH_P: If it's pressed for more than 30 seconds, it decreases the 
 *  	speed of the motor for 1 ster for each 30 seconds. (It's the highest
 *  	priority event)
 *  -	#SWITCH_DECREMENT: If it's pre_pressed, it decreases the motor speed
 *  	by 1 step. (It's the next in priority)
 *  -	#SWITCH_INCREMENT: If it's pre_pressed, it decreases the motor speed
 *  	by 1 step. (It's the lowest priority event)
 *  
 *  We have 3 main modules:
 *  -	\b Switch \b Module: It's updates the states of 3 switches.
 *  -	\b Speed \b Control \b Module: It takes the states of the 3 switches and the current speed 
 *  	of the motor to update the speed of the motor.
 *  -	\b Motor \b Module: It takes the speed from the \b Speed \b control \b module and 
 *  	updates the angle of the motor.
 *  
 *  We have added extra modules:
 *  -	\b File \b Interface \b Module: It interacts with I/P "switch.txt" and O/P "motor.txt" files.
 *  -	\b Parse \b Module: It parses the text from input file and passed it to \b switch \b module
 *  	to simulate the switches hardware on PC.
 *  
 *  \section assumptions_section Assumptions section
 *  We have made some assumptions:
 *  -	The inpur file \b must have a header.
 *  -	The input text file could be separated by \t, \\n, spaces, or any special character other than "-"
 *  -	Motor speed is represented as motor angle in output text file, so thy are the same.
 *  -	Motor minimum speed is #MOTOR_MINIMUM_SPEED, motor maximum speed is #MOTOR_MAXIMUM_SPEED, and motor default speed is #MOTOR_MEDIUM_SPEED.
 *  
 *  \subsection motor_limitations Motor speed limitations
 *  Motor speed will be always between #MOTOR_MINIMUM_SPEED and #MOTOR_MAXIMUM_SPEED even if you try
 *  to pass a value out of these boundaries, it'll make the less than #MOTOR_MINIMUM_SPEED values to be
 *  #MOTOR_MINIMUM_SPEED and more than #MOTOR_MAXIMUM_SPEED to be #MOTOR_MAXIMUM_SPEED.
 *  
 *  \section testing_section Testing
 *  We use many testing techniques to test the functionality of operation of our project. We use
 *  different techniques for different modules such as:
 *  -	\b Eqivalence \b Partitioning: To divide the values to partitions and every partition treats the data in the same way.
 *  -	\b Boundary \b Values \b Analysis: To check the boundary for each partition.
 *  -	\b 1-Switch \b coverage: To move through the transition of every state until you get to a state you have already passed by before.
 *  	You must go through all transitions of every state.
 *  \subsection testing_module Testing Modules:
 *  Every module is tested using different technique according to its specification to make sure
 *  that it's working correctly as follows:
 *  -	\b Parse \b Module: It's tested using brute force method. We tested it using every possible input to make sure
 *  	that it parses it correctly.
 *  -	\b Motor \b Module: It's tested using BVA + EP techniques.
 *  -	\b Switch \b Module: It's tested by just setting and getting the \ref Switches_States_t of each switch.
 *  -	\b Speed \b Control \b Module: It's tested using 1-Switch coverage technique(transition state of switches) + 
 *  	EP + BVA (pressing duration of "P" switch).
 *  
 *  \section project_operation	Project Operation
 *  The project first runs the selected test cases of each module and shows the result
 *  of all test cases in console window, then runs the project itself(reading the states of 
 *  switches "switches.txt" from text file, calculates the new speed, update motor angle, 
 *  and output it to text file "motor.txt").
 */