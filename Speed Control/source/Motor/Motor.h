/**
 *  \file	Motor.h
 *  \brief	This file is a driver for the motor.
 *  \author Ahmed Wageh.
 */
#ifndef MOTOR_H_
#define MOTOR_H_
/* Macros */
/**
 *  \defgroup	Motor_Angle_Limitaion Motor angle limitations
 *  This is the Boundaries and normal angles of Motor
 *  @{
 */
/** The minimum motor speed(angle) */
#define MOTOR_MINIMUM_SPEED	10
/** The maximun motor speed(angle) */
#define MOTOR_MAXIMUM_SPEED	140
/** The default(normal) motor speed(angle) */
#define MOTOR_MEDIUM_SPEED	90
/**
 *  @}
 */

/* Functions prototypes */
/**
 *  \brief This function for initializing the motor
 *
 *  \return None.
 *
 *  \details This function prepare the output text, which
 *  		 represents the motor, for writing and setting
 *  		 the initial speed to \ref MOTOR_MEDIUM_SPEED.
 */
void Motor_Init(void);

/**
 *  \brief Update the speed of motor to be \p new_speed
 *
 *  \param [in] new_speed The new target speed
 *  \return None
 *
 *  \details Updating the speed of the motor to target speed
 *  		 with speed limitation to be greater than or equal
 *  		 to \ref MOTOR_MINIMUM_SPEED and less than or equal
 *  		 to \ref MOTOR_MAXIMUM_SPEED. It updates also the output
 *           text file with the target speed.
 */
void Motor_UpdateSpeed(int new_speed);

/**
 *  \brief Gets the current speed of the motor
 *
 *  \return The current speed of the motor
 */
int Motor_GetSpeed(void);
#endif // !MOTOR_H_
