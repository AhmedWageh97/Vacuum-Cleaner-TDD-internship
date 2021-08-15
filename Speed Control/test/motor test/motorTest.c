/**
 *  \file	motorTest.c
 *  \brief	This file includes test cases for testing motor module.
 *  \author Ahmed Wageh
 */
#include "../../source/Motor/Motor.h"
#include "../unity/unity_fixture.h"

/* Test group declaration */
TEST_GROUP(motor_test);
TEST_GROUP(motor_boundary_value_analysis_test);
TEST_GROUP(motor_equivalence_partitioning_test);

/* motor_test group setup and tear_down function */
TEST_SETUP(motor_test)
{
    Motor_Init();
}


TEST_TEAR_DOWN(motor_test)
{

}

/* BVA group setup and tear_down function */
TEST_SETUP(motor_boundary_value_analysis_test)
{
    Motor_Init();
}


TEST_TEAR_DOWN(motor_boundary_value_analysis_test)
{

}

/* Equivalence_partitioning group setup and tear_down function */
TEST_SETUP(motor_equivalence_partitioning_test)
{
    Motor_Init();
}


TEST_TEAR_DOWN(motor_equivalence_partitioning_test)
{

}

/* Test cases implementation */
/* Basic test case definition */
/**
 *  \defgroup motor_tests Motor test
 *  It's for making sure that motor functionality is going well
 *  @{
 */

/**
 *  \defgroup motor_default_tests Default motor test
 *  It's for making sure that motor initialization went well
 *  \ingroup motor_tests
 *  \details It tests basic test cases for motor angle such as:
 *  	-	MotorSpeedIsMediumSpeedAfterInit: Make sure that
 *  		motor speed = #MOTOR_MEDIUM_SPEED after init.
 *  @{
 */


/**
 *  \brief 	Test case for testing motor speed after the
 *  		initialization of motor module.
 *
 *  \details When applying this test case(Initializing the motor module)
 *  		 we expect that the new speed is equal to
 *  		 \ref MOTOR_MEDIUM_SPEED.
 */
TEST(motor_test, MotorSpeedIsMediumSpeedAfterInit)
{
    /* Init function is called in TEST_SETUP */
	LONGS_EQUAL(MOTOR_MEDIUM_SPEED, Motor_GetSpeed());
}
/**
 *  @}
 */

/**
 *  \defgroup motor_speed_boundary_test Motor speed boundary value analysis test
 *  It's performing the boundary value analysis technique
 *  \ingroup motor_tests
 *  \details It tests the following values for motor speed:
 *  	-	MotorSpeedIsMinimum: To apply the test when motor speed
 *  		is \ref MOTOR_MINIMUM_SPEED.
 *  	-	MotorSpeedIsAboveMinimum: To apply the test case when
 *  		motor speed is just above \ref MOTOR_MINIMUM_SPEED(we choose here
 *  		to be \ref MOTOR_MINIMUM_SPEED + 1).
 *  	-	MotorSpeedIsNominal: To apply the test case when motor
 *  		speed is between \ref MOTOR_MINIMUM_SPEED and
 *  		\ref MOTOR_MAXIMUM_SPEED (we choose here to be equal
 *  		to \ref MOTOR_MEDIUM_SPEED).
 *  	-	MotorSpeedIsBelowMaximum: To apply the testcase when motor
 *  		speed is jus below \ref MOTOR_MAXIMUM_SPEED(we choose here
 *  		to be \ref MOTOR_MAXIMUM_SPEED - 1).
 *  	-	MotorSpeedIsMaximum: To apply the test when motor speed
 *  		is \ref MOTOR_MAXIMUM_SPEED.
 *  @{
 */

/**
 *  \brief 	Test case for applying motor angle is equal to
 *  		\ref MOTOR_MINIMUM_SPEED
 *
 *  \details When applying this test case(setting the motor
 *  		 angle to \ref MOTOR_MINIMUM_SPEED) we expect that
 *  		 the new speed is equal to \ref MOTOR_MINIMUM_SPEED.
 */
TEST(motor_boundary_value_analysis_test, MotorSpeedIsMinimum)
{
    /* Note that init is called in TEST_SETUP() */
    Motor_SetSpeed(MOTOR_MINIMUM_SPEED);
    LONGS_EQUAL(MOTOR_MINIMUM_SPEED, Motor_GetSpeed());
}

/**
 *  \brief 	Test case for applying motor angle is just above
 *  		\ref MOTOR_MINIMUM_SPEED value
 *
 *  \details When applying this test case(setting the motor
 *  		 angle to \ref MOTOR_MINIMUM_SPEED + 1) we expect that
 *  		 the new speed is equal to (\ref MOTOR_MINIMUM_SPEED + 1).
 */
TEST(motor_boundary_value_analysis_test, MotorSpeedIsAboveMinimum)
{
    /* Note that init is called in TEST_SETUP() */
    Motor_SetSpeed(MOTOR_MINIMUM_SPEED + 1);
    LONGS_EQUAL(MOTOR_MINIMUM_SPEED + 1, Motor_GetSpeed());
}

/**
 *  \brief 	Test case for applying motor angle is a nominal value(
 *          between \ref MOTOR_MINIMUM_SPEED and \ref MOTOR_MAXIMUM_SPEED)
 *  		and here we choose it to be equal to \ref MOTOR_MEDIUM_SPEED.
 *
 *  \details When applying this test case(setting the motor
 *  		 angle to \ref MOTOR_MEDIUM_SPEED) we expect that
 *  		 the new speed is equal to ( \ref MOTOR_MEDIUM_SPEED).
 */
TEST(motor_boundary_value_analysis_test, MotorSpeedIsNominal)
{
    /* Note that init is called in TEST_SETUP() */
    Motor_SetSpeed(MOTOR_MEDIUM_SPEED);
    LONGS_EQUAL(MOTOR_MEDIUM_SPEED, Motor_GetSpeed());
}

/**
 *  \brief 	Test case for applying motor angle is a to be
 *  		just below \ref MOTOR_MAXIMUM_SPEED.
 *
 *  \details When applying this test case(setting the motor
 *  		 angle to be \ref MOTOR_MAXIMUM_SPEED - 1)
 *  		 we expect that the new speed is equal to ( \ref MOTOR_MEDIUM_SPEED - 1).
 */
TEST(motor_boundary_value_analysis_test, MotorSpeedIsBelowMaximum)
{
    /* Note that init is called in TEST_SETUP() */
    Motor_SetSpeed(MOTOR_MAXIMUM_SPEED - 1);
    LONGS_EQUAL(MOTOR_MAXIMUM_SPEED - 1, Motor_GetSpeed());
}

/**
 *  \brief 	Test case for applying motor angle is equal to
 *  		\ref MOTOR_MAXIMUM_SPEED
 *
 *  \details When applying this test case(setting the motor
 *  		 angle to \ref MOTOR_MAXIMUM_SPEED) we expect that
 *  		 the new speed is equal to \ref MOTOR_MAXIMUM_SPEED.
 */
TEST(motor_boundary_value_analysis_test, MotorSpeedIsMaximum)
{
    /* Note that init is called in TEST_SETUP() */
    Motor_SetSpeed(MOTOR_MAXIMUM_SPEED);
    LONGS_EQUAL(MOTOR_MAXIMUM_SPEED, Motor_GetSpeed());
}
/**
 *  @}
 */

/**
 *  \defgroup motor_equivalence_partitioning_test Motor speed equivalence partitioning test
 *  It's performing the equivalence partitioning technique
 *  \ingroup motor_tests
 *  \details It tests the following values for motor speed:
 *  	-	BelowMinimumPartition: To apply the test when motor speed
 *  		is lower than \ref MOTOR_MINIMUM_SPEED(we choose here to be equal
 *  		to \ref MOTOR_MINIMUM_SPEED - 5).
 *  	-	OrdinaryPartition: To apply the test case when motor
 *  		speed is between \ref MOTOR_MINIMUM_SPEED and
 *  		\ref MOTOR_MAXIMUM_SPEED (we choose here to be equal
 *  		to 120).
 *  	-	AboveMaximimPartition: To apply the test case when motor
 *  		speed is greater than \ref MOTOR_MAXIMUM_SPEED (we choose here to be equal
 *  		to \ref MOTOR_MAXIMUM_SPEED + 100).
 *  @{
 */

/**
 *  \brief 	Test case for applying motor angle is less than
 *  		\ref MOTOR_MINIMUM_SPEED
 *
 *  \details When applying this test case(setting the motor
 *  		 angle to be  \ref MOTOR_MINIMUM_SPEED - 5) we expect that
 *  		 the new speed is equal to \ref MOTOR_MINIMUM_SPEED.
 */
TEST(motor_equivalence_partitioning_test, BelowMinimumPartition)
{
    /* Note that init is called in TEST_SETUP() */
    Motor_SetSpeed(MOTOR_MINIMUM_SPEED - 5);
    LONGS_EQUAL(MOTOR_MINIMUM_SPEED, Motor_GetSpeed());
}

/**
 *  \brief 	Test case for applying motor angle is between
 *  		\ref MOTOR_MINIMUM_SPEED and \ref MOTOR_MAXIMUM_SPEED
 *
 *  \details When applying this test case(setting the motor
 *  		 angle to be between \ref MOTOR_MINIMUM_SPEED and
 *  		\ref MOTOR_MAXIMUM_SPEED (we choose here to be equal
 *  		to 120) we expect that the new speed is equal to 120.
 */
TEST(motor_equivalence_partitioning_test, OrdinaryPartition)
{
    /* Note that init is called in TEST_SETUP() */
    Motor_SetSpeed(120);
    LONGS_EQUAL(120, Motor_GetSpeed());
}

/**
 *  \brief 	Test case for applying motor angle is more than
 *  		\ref MOTOR_MAXIMUM_SPEED
 *
 *  \details When applying this test case(setting the motor
 *  		 angle to be greater than \ref MOTOR_MAXIMUM_SPEED
 *  		(we choose here to be equal \ref MOTOR_MAXIMUM_SPEED + 100)
 *  		we expect that the new speed is equal to \ref MOTOR_MAXIMUM_SPEED.
 */
TEST(motor_equivalence_partitioning_test, AboveMaximimPartition)
{
    /* Note that init is called in TEST_SETUP() */
    Motor_SetSpeed(MOTOR_MAXIMUM_SPEED + 100);
    LONGS_EQUAL(MOTOR_MAXIMUM_SPEED, Motor_GetSpeed());
}
/**
 *  @}
 */

/**
 *  @}
 */

/**
 *  \brief Test code runner for BVA test for motor module
 */
TEST_GROUP_RUNNER(motor_boundary_value_analysis_test)
{
    printf("\t================= Boundary Value Analysis Test =================\n");
    printf("\t");
    RUN_TEST_CASE(motor_boundary_value_analysis_test, MotorSpeedIsMinimum);
    printf("\t");
    RUN_TEST_CASE(motor_boundary_value_analysis_test, MotorSpeedIsAboveMinimum);
    printf("\t");
    RUN_TEST_CASE(motor_boundary_value_analysis_test, MotorSpeedIsNominal);
    printf("\t");
    RUN_TEST_CASE(motor_boundary_value_analysis_test, MotorSpeedIsBelowMaximum);
    printf("\t");
    RUN_TEST_CASE(motor_boundary_value_analysis_test, MotorSpeedIsMaximum);
    printf("\t============== Boundary Value  Analysis Test Done ==============\n\n\n");
}


/**
 *  \brief Test code runner for equivalence partitioning test for motor module
 */
TEST_GROUP_RUNNER(motor_equivalence_partitioning_test)
{
    printf("\t================= Equivalence Partitioning Test =================\n");
    printf("\t");
    RUN_TEST_CASE(motor_equivalence_partitioning_test, BelowMinimumPartition);
    printf("\t");
    RUN_TEST_CASE(motor_equivalence_partitioning_test, OrdinaryPartition);
    printf("\t");
    RUN_TEST_CASE(motor_equivalence_partitioning_test, AboveMaximimPartition);
    printf("\t============== Equivalence  Partitioning Test Done ==============\n\n\n");
}

/**
 *  \brief Test code runner for all test techniques for motor module.
 */
TEST_GROUP_RUNNER(motor_test)
{
    printf("======================= Testing Motor Module =======================\n\n");

	printf("\t================= Motor initialization Test =================\n");
    printf("\t");
    RUN_TEST_CASE(motor_test, MotorSpeedIsMediumSpeedAfterInit);
    printf("\t================= Motor initialization Done =================\n\n\n");

	RUN_TEST_GROUP(motor_boundary_value_analysis_test);
    RUN_TEST_GROUP(motor_equivalence_partitioning_test);
    printf("==================== Testing Motor  Module Done ====================\n\n\n");
}

