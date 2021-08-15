/**
 *  \file	Motor.c
 *  \brief	This file is the implementation of the driver
 *  		for the motor.
 *  \author Ahmed Wageh.
 */
/* Inclusion */
#include "Motor.h"
#include "../File If/FileIf.h"

/* Private Data */
/** Current motor speed */
static int motor_speed = MOTOR_MEDIUM_SPEED;

/* Private Functions */
/**
 *  \brief Setting speed of the motor to \p speed
 *
 *  \param [in] speed The target speed of the motor.
 *  \return None.
 *
 *  \details Setting the speed of the motor to \p speed with
 *  		 speed limitations to be greater than or equal
 *  		 to \ref MOTOR_MINIMUM_SPEED and less than or equal
 *  		 to \ref MOTOR_MAXIMUM_SPEED
 */
void Motor_SetSpeed(int speed);

/* Functions definition */
/* Private functions */
/**
 *  \brief Setting speed of the motor to \p speed
 *
 *  \param [in] speed The target speed of the motor.
 *  \return None.
 *
 *  \details Setting the speed of the motor to \p speed with
 *  		 speed limitations to be greater than or equal
 *  		 to \ref MOTOR_MINIMUM_SPEED and less than or equal
 *  		 to \ref MOTOR_MAXIMUM_SPEED
 */
void Motor_SetSpeed(int speed)
{
	/* Function logic */
	/* Speed limitations */
	if (speed >= MOTOR_MAXIMUM_SPEED)
	{
		motor_speed = MOTOR_MAXIMUM_SPEED;
	}
	else if (speed <= MOTOR_MINIMUM_SPEED)
	{
		motor_speed = MOTOR_MINIMUM_SPEED;
	}
	else
	{
		motor_speed = speed;
	}
}

/* Public functions */
/**
 *  \brief This function for initializing the motor
 *
 *  \return None.
 *
 *  \details This function prepare the output text, which
 *  		 represents the motor, for writing and setting
 *  		 the initial speed to \ref MOTOR_MEDIUM_SPEED.
 */
void Motor_Init(void)
{
	File_PrepareOutputFile();
	Motor_SetSpeed(MOTOR_MEDIUM_SPEED);
}

/**
 *  \brief Update the speed of motor to be \p new_speed
 *
 *  \param [in] new_speed The new target speed
 *  \return None
 *
 *  \details Updating the speed of the motor to target speed
 *  		 with speed limitation to be greater than or equal
 *  		 to \ref MOTOR_MINIMUM_SPEED and less than or equal
 *  		 to \ref MOTOR_MAXIMUM_SPEED.
 */
void Motor_UpdateSpeed(int new_speed)
{
	/* Function logic */
	/* Set new speed */
	Motor_SetSpeed(new_speed);
	/* Updating speed */
	File_WriteLine(Motor_GetSpeed());
}

/**
 *  \brief Gets the current speed of the motor
 *
 *  \return The current speed of the motor
 */
int Motor_GetSpeed(void)
{
	return motor_speed;
}
