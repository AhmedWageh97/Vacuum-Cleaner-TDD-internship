/**
 *  \file	SpeedControl.c
 *  \brief	This file is implementation of the Speed Control module.
 *  \author Ahmed Wageh.
 *  \details This module controls the speed of the motor depends
 *  		 on the states of switches and the pressing duration
 *  		 of "P" switch.
 */
/* Inclusion */
#include "../Switches/Switches.h"
#include "../Motor/Motor.h"
#include "SpeedControl.h"

/**
 *  \brief 	This function calculates the target new speed that
 *  		should be assigned to the motor depend on switches
 *  		states.
 *  \param	None.
 *  \return The new calculated speed.
 */
int SpeedControl_CalcNewSpeed(void)
{
	/* Needed variables */
	Switches_States_t IncSwitch = SWITCH_RELEASED;
	Switches_States_t DecSwitch = SWITCH_RELEASED;
	Switches_States_t PSwitch = SWITCH_RELEASED;
	int PDuration = 0;
	int MotorSpeed = MOTOR_MEDIUM_SPEED;

	/* Function Logic */
	/* Get switches states */
	IncSwitch = Switches_GetState(SWITCH_INCREMENT);
	DecSwitch = Switches_GetState(SWITCH_DECREMENT);
	PSwitch = Switches_GetState(SWITCH_P);
	PDuration = Switches_GetPDuration();

	/* Get current motor speed */
	MotorSpeed = Motor_GetSpeed();

	/* Calculating new speed */
	if (PSwitch == SWITCH_PRESSED && PDuration >= 30000)
	{
		if (MotorSpeed >= MOTOR_MINIMUM_SPEED)
		{
			do{
                MotorSpeed--;
                PDuration -= 30000;
			}while(PDuration >= 30000 && MotorSpeed >= MOTOR_MINIMUM_SPEED);
		}
	}
	else if(DecSwitch == SWITCH_PRE_PRESSED)
	{
		if (MotorSpeed >= MOTOR_MINIMUM_SPEED)
		{
			MotorSpeed--;
		}
	}
	else if(IncSwitch == SWITCH_PRE_PRESSED)
	{
		if (MotorSpeed <= MOTOR_MAXIMUM_SPEED)
		{
			MotorSpeed++;
		}
	}

	/* Return new calculated speed */
	return MotorSpeed;
}
