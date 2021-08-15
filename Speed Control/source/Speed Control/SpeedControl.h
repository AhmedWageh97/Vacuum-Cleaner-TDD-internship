/**
 *  \file	SpeedControl.h
 *  \brief	This file is a driver for the Speed Control module.
 *  \author Ahmed Wageh.
 *  \details This module controls the speed of the motor depends 
 *  		 on the states of switches and the pressing duration
 *  		 of "P" switch.
 */
#ifndef SPEED_CONTROL_H_
#define SPEED_CONTROL_H_

/* Functions proto type */
/**
 *  \brief 	This function calculates the target new speed that 
 *  		should be assigned to the motor depend on switches 
 *  		states.
 *  \param	None.
 *  \return The new calculated speed.
 */
int SpeedControl_CalcNewSpeed(void);
#endif // !SPEED_CONTROL_H_
