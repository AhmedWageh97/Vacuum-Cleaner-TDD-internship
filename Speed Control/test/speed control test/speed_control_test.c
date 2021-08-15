/**
 *  \file	speed_control_test.c
 *  \brief	This file includes test cases for testing speed control
 *  		module.
 *  \author Ahmed Wageh
 */
#include "../../source/Motor/Motor.h"
#include "../fake switch/fake_switch.h"
#include "../../source/Speed Control/SpeedControl.h"
#include "../unity/unity_fixture.h"

/* Test group declaration */
TEST_GROUP(speed_control_test);
TEST_GROUP(default_speed_control_test);
TEST_GROUP(priority_speed_control_test);
TEST_GROUP(EP_BVA_speed_control_test);
TEST_GROUP(ONE_SWIICH_COVERAGE_speed_control_test);

/* motor_test group setup and tear_down function */
TEST_SETUP(speed_control_test)
{
    Motor_Init();
    FAKE_SW_init();
    UT_PTR_SET(Switches_GetState, FAKE_SW_getSwState);
    UT_PTR_SET(Switches_GetPDuration, FAKE_SW_getSwDuration);
}


TEST_TEAR_DOWN(speed_control_test)
{
    FAKE_SW_destroy();
}

/* motor_test group setup and tear_down function */
TEST_SETUP(default_speed_control_test)
{
    Motor_Init();
    FAKE_SW_init();
    UT_PTR_SET(Switches_GetState, FAKE_SW_getSwState);
    UT_PTR_SET(Switches_GetPDuration, FAKE_SW_getSwDuration);
}


TEST_TEAR_DOWN(default_speed_control_test)
{
    FAKE_SW_destroy();
}

/* motor_test group setup and tear_down function */
TEST_SETUP(priority_speed_control_test)
{
    Motor_Init();
    FAKE_SW_init();
    UT_PTR_SET(Switches_GetState, FAKE_SW_getSwState);
    UT_PTR_SET(Switches_GetPDuration, FAKE_SW_getSwDuration);
}


TEST_TEAR_DOWN(priority_speed_control_test)
{
    FAKE_SW_destroy();
}

/* motor_test group setup and tear_down function */
TEST_SETUP(EP_BVA_speed_control_test)
{
    Motor_Init();
    FAKE_SW_init();
    UT_PTR_SET(Switches_GetState, FAKE_SW_getSwState);
    UT_PTR_SET(Switches_GetPDuration, FAKE_SW_getSwDuration);
}


TEST_TEAR_DOWN(EP_BVA_speed_control_test)
{
    FAKE_SW_destroy();
}

/* motor_test group setup and tear_down function */
TEST_SETUP(ONE_SWIICH_COVERAGE_speed_control_test)
{
    Motor_Init();
    FAKE_SW_init();
    UT_PTR_SET(Switches_GetState, FAKE_SW_getSwState);
    UT_PTR_SET(Switches_GetPDuration, FAKE_SW_getSwDuration);
}


TEST_TEAR_DOWN(ONE_SWIICH_COVERAGE_speed_control_test)
{
    FAKE_SW_destroy();
}

/**
 *  \defgroup speed_control_test Speed control test
 *  This is the testing of speed control module. It uses several testing techniques.
 *  
 *  @{
 */


/**
 *  \defgroup default_speed_control_test Default speed control test
 *  This is the testing of speed control module in the default cases.
 *  
 *  \ingroup speed_control_test
 *  
 *  \details	It tests the module behaviour in the default
 *  		 	states without concedering any priorty in the
 *  		 	test cases. It tests the following test cases:
 *  			- 	AllSwitchesAreReleasedAndDurationIsZeroAndSpeedIsMediumSpeed:
 *  				For testing the state of switches to make sure that 
 *					it's released after initialization and the duration
 *					is equal to 0 after initialization.
 *				-	OnlyIncSwitchIsPrePressedAndOthersAreReleased: To test
 *					when only "+ve" switch is pre pressed and the other are
 *					released.
 *				-	OnlyDecSwitchIsPrePressedAndOthersAreReleased: To test
 *					when only "-ve" switch is pre pressed and the other are
 *					released.
 *				-	OnlyPSwitchIsPressedAndOthersAreReleasedAndPeriodIsEqualTo30Seconds:
 *					To test when only "p" switch is pressed and the other are
 *					released and the pressing duration is equal to 30 seconds.
 *			
 *
 *	@{
 */

/**
 *  \brief	Test case for making sure that all switches are
 *  		released and duration is = 0 after initialization.

 *  \param Given : Start of the program.
 *  \param When	 : Calling the fake function of \ref Switches_Init.
 *  \param Then  : All switches are released and p pressing duration is 0.
 *  
 *  \details This test case for making sure that switch module initialization 
 *  		 went well.
 */
TEST(default_speed_control_test, AllSwitchesAreReleasedAndDurationIsZeroAndSpeedIsMediumSpeed)
{
    LONGS_EQUAL(SWITCH_RELEASED, FAKE_SW_getSwState(SWITCH_INCREMENT));
    LONGS_EQUAL(SWITCH_RELEASED, FAKE_SW_getSwState(SWITCH_DECREMENT));
    LONGS_EQUAL(SWITCH_RELEASED, FAKE_SW_getSwState(SWITCH_P));
    LONGS_EQUAL(0, FAKE_SW_getSwDuration());
    LONGS_EQUAL(MOTOR_MEDIUM_SPEED, Motor_GetSpeed());
}

/**
 *  \brief	Test case for making sure that "+ve" switch modifing
 *  		The speed as expected.
 *  
 *  \param Given : Start of the program.
 *  \param When	 : "+ve" switch is pre_pressed,
 *  			   Calling \ref SpeedControl_CalcNewSpeed, and 
 *  			   updating motor speed with the result.
 *  \param Then  : Motor speed incremented by 1 step.
 *  
 *  \details This test case for making sure that "+ve" switch 
 *  		 is working well.
 */
TEST(default_speed_control_test, OnlyIncSwitchIsPrePressedAndOthersAreReleased)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_INCREMENT, SWITCH_PRE_PRESSED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed + 1, Motor_GetSpeed());
}

/**
 *  \brief	Test case for making sure that "-ve" switch modifing
 *  		The speed as expected.
 *  
 *  \param Given : Start of the program.
 *  \param When	 : "-ve" switch is pre_pressed,
 *  			   Calling \ref SpeedControl_CalcNewSpeed, and 
 *  			   updating motor speed with the result.
 *  \param Then  : Motor speed decremented by 1 step.
 *  
 *  \details This test case for making sure that "-ve" switch 
 *  		 is working well.
 */
TEST(default_speed_control_test, OnlyDecSwitchIsPrePressedAndOthersAreReleased)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_DECREMENT, SWITCH_PRE_PRESSED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 1, Motor_GetSpeed());
}

/**
 *  \brief	Test case for making sure that "P" switch modifing
 *  		The speed as expected.
 *  
 *  \param Given : Start of the program.
 *  \param When	 : "P" switch is pressed for 30 seconds,
 *  			   Calling \ref SpeedControl_CalcNewSpeed, and 
 *  			   updating motor speed with the result.
 *  \param Then  : Motor speed decremented by 1 step.
 *  
 *  \details This test case for making sure that "P" switch 
 *  		 is working well.
 */
TEST(default_speed_control_test, OnlyPSwitchIsPressedAndOthersAreReleasedAndPeriodIsEqualTo30Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(30000);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 1, Motor_GetSpeed());
}

/* default_speed_control_test closure */
/**
 *  @}
 */


/**
 *  \defgroup priority_speed_control_test Priority speed control test
 *  This is the testing of the priority of switches in speed control module.
 *  
 *  \ingroup speed_control_test
 *  
 *  \details	It tests the module behaviour with taking the priority
 *  			in concederation . It tests the following test cases:
 *  			- 	PSwitchIsPressedAndOthersArePrePressedAndDurationIs30s:
 *  				Making sure that "P" switch is the highest priority.
 *				-	PSwitchIsReleasedAndOthersArePrePressed: for making
					sure that "-ve" switch is the second in priority after 
					"P" switch.
 *	@{
 */

/**
 *  \brief	Test case for making sure that "P" switch is the
 *  		highest priority.
 *  
 *  \param Given : "P" switch is pressed for 30 seconds, 
 *  			   "-ve" switch is pre_pressed, and
 *  			   "+ve" switch is pre_pressed.
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed and updating motor speed with the result to 
 *  			   update motor speed.
 *  \param Then  : Motor speed decremented by 1 step.
 *  
 *  \details This test case for making sure that "P" switch 
 *  		 is is the highest priority when it's pre_pressed 
 *  		 for >= 30 seconds and the other are pre_pressed.
 */
TEST(priority_speed_control_test, PSwitchIsPressedAndOthersArePrePressedAndDurationIs30s)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwState(SWITCH_INCREMENT, SWITCH_PRE_PRESSED);
    FAKE_SW_setSwState(SWITCH_DECREMENT, SWITCH_PRE_PRESSED);
    FAKE_SW_setSwDuration(30000);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 1, Motor_GetSpeed());
}

/**
 *  \brief	Test case for making sure that "-ve" switch is the
 *  		second in priority after "P" switch.
 *  
 *  \param Given : "P" switch is released, 
 *  			   "-ve" switch is pre_pressed, and
 *  			   "+ve" switch is pre_pressed.
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed and 
 *  			   updating motor speed with the result.
 *  \param Then  : Motor speed decremented by 1 step.
 *  
 *  \details This test case for making sure that "-ve" switch 
 *  		 is the second in priority after "P" switch.
 */
TEST(priority_speed_control_test, PSwitchIsReleasedAndOthersArePrePressed)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_RELEASED);
    FAKE_SW_setSwState(SWITCH_INCREMENT, SWITCH_PRE_PRESSED);
    FAKE_SW_setSwState(SWITCH_DECREMENT, SWITCH_PRE_PRESSED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 1, Motor_GetSpeed());
}

/* priority_speed_control_test closure */
/**
 *  @}
 */

/**
 *  \defgroup EP_BVA_speed_control_test EP + BVA test
 *  It applies the Equivalence Partitioning and Boundary values analysis techniques for "P" switch pressing duration when "P" switch is pressed.
 *  \ingroup speed_control_test
 *  
 *  \details	It applies the Equivalence Partitioning 
 *  			and Boundary values analysis techniques 
 *  			for "P" switch pressing duration when "P" 
 *  			switch is pressed. It tests the following 
 *  			test cases:
 *  			-	PSwitchIsPressedAndDurationIsZero: when
 *  				"P" switch is pressed for 0 seconds.
 *  			-	PSwitchIsPressedAndDurationIs15Seconds: when
 *  				"P" switch is pressed for 15 seconds.
 *  			-	PSwitchIsPressedAndDurationIsJustLessThan30Seconds: when
 *  				"P" switch is pressed for less than 30 seconds by 
 *  				1 milli seconds.
 *  			-	PSwitchIsPressedAndDurationIs30Seconds: when
 *  				"P" switch is pressed for 30 seconds.
 *  			-	PSwitchIsPressedAndDurationIsJustGreaterThan30Seconds: when
 *  				"P" switch is pressed for greater than 30 seconds by 
 *  				1 milli seconds.
 *  			-	PSwitchIsPressedAndDurationIsJustLessThan60Seconds: when
 *  				"P" switch is pressed for less than 60 seconds by 
 *  				1 milli seconds.
 *  			-	PSwitchIsPressedAndDurationIs60Seconds: when
 *  				"P" switch is pressed for 60 seconds.
 *  			-	PSwitchIsPressedAndDurationIsJustGreaterThan60Seconds: when
 *  				"P" switch is pressed for greater than 60 seconds by 
 *  				1 milli seconds.
 *  			-	PSwitchIsPressedAndDurationIsJustLessThan90Seconds: when
 *  				"P" switch is pressed for less than 90 seconds by 
 *  				1 milli seconds.
 *  			-	PSwitchIsPressedAndDurationIs90Seconds: when
 *  				"P" switch is pressed for 90 seconds.
 *  			-	PSwitchIsPressedAndDurationIsJustGreaterThan90Seconds: when
 *  				"P" switch is pressed for greater than 90 seconds by 
 *  				1 milli seconds.
 *  			
 *	@{
 */

/**
 *  \brief	It tests the boundary values for P duration
 *  		"Testing at 0 boundary"
 *  
 *  \param Given : "P" switch is pressed for 0 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed still unchanged.
 *  
 *  \details 
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsZero)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(0);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
}

/**
 *  \brief	It tests the less-than-30-seconds partition 
 *  		for P duration.
 *  
 *  \param Given : "P" switch is pressed for 15 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed still unchanged.
 *  
 *  \details 
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIs15Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(15000);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
}

/**
 *  \brief	It tests the just-below-30-seconds boundary for 
 *  		P duration.
 *  
 *  \param Given : "P" switch is pressed for just less than 30 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed still unchanged.
 *  
 *  \details 
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustLessThan30Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(29999);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
}

/**
 *  \brief	It tests the 30 seconds boundary for P duration.
 *  
 *  \param Given : "P" switch is pressed for 30 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed decreases by 1 step.
 *  
 *  \details 
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIs30Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(30000);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 1, Motor_GetSpeed());
}

/**
 *  \brief	It tests the just-above-30-seconds boundary for 
 *  		P duration.
 *  
 *  \param Given : "P" switch is pressed for just greater than 30 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed decreases by 1 step.
 *  
 *  \details 
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustGreaterthan30Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(30001);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 1, Motor_GetSpeed());
}

/**
 *  \brief	It tests the just-below-60-seconds boundary for 
 *  		P duration.
 *  
 *  \param Given : "P" switch is pressed for just less than 60 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed decreases by 1 step.
 *  
 *  \details 
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustLessThan60Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(59999);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 1, Motor_GetSpeed());
}

/**
 *  \brief	It tests a mixed test case(BVA and multiple 
 *  		decrement) for P duration.
 *  
 *  \param Given : "P" switch is pressed for 60 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed decreases by 2 step.
 *  
 *  \details It tests the action of P duration if the switch is
 *  		 pressed for 60 seconds (Boundary for multiples of (30 seconds),
 *  		 a greater that 30 second partition)
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIs60Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(60000);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 2, Motor_GetSpeed());
}

/**
 *  \brief	It tests the just-above-60-seconds boundary for 
 *  		P duration.
 *  
 *  \param Given : "P" switch is pressed for just greater than 60 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed decreases by 2 step.
 *  
 *  \details 
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustGreaterthan60Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(60001);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 2, Motor_GetSpeed());
}

/**
 *  \brief	It tests the just-below-90-seconds boundary for 
 *  		P duration.
 *  
 *  \param Given : "P" switch is pressed for just less than 90 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed decreases by 2 step.
 *  
 *  \details 
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustLessThan90Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(89999);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 2, Motor_GetSpeed());
}

/**
 *  \brief	It tests a mixed test case(BVA and multiple 
 *  		decrement) for P duration.
 *  
 *  \param Given : "P" switch is pressed for 90 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed decreases by 3 step.
 *  
 *  \details It tests the action of P duration if the switch is
 *  		 pressed for 90 seconds (Boundary for multiples of (30 seconds),
 *  		 a greater that 30 second partition)
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIs90Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(90000);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 3, Motor_GetSpeed());
}

/**
 *  \brief	It tests the just-above-90-seconds boundary for 
 *  		P duration.
 *  
 *  \param Given : "P" switch is pressed for just greater than 90 seconds
 *  \param When	 : Calling \ref SpeedControl_CalcNewSpeed 
 *  			   and updating motor speed with the result
 *  \param Then  : Motor speed decreases by 3 step.
 *  
 *  \details 
 */
TEST(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustGreaterthan90Seconds)
{
    /* Needed variables */
    int previous_speed;

    /* Act */
    previous_speed = Motor_GetSpeed();
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    FAKE_SW_setSwDuration(90001);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 3, Motor_GetSpeed());
}

/* EP_BVA_speed_control_test closure */
/**
 *  @}
 */
 
/**
 *  \defgroup ONE_SWIICH_COVERAGE_speed_control_test 1-Switch coverage
 *  It performs 1-switch coverage testing techniques for the transition of switches state.
 *  
 *  \ingroup speed_control_test
 *  
 *  \details	It performs 1-switch coverage testing techniques for 
 *  			the transition of switches state. It applies the 
 *  			following test cases:
 *  			-	IncSwitchCoverageTest: Transformation of the state of 
 *  				"+ve" switch from #SWITCH_RELEASED -> #SWITCH_PRE_PRESSED ->
 *  				#SWITCH_PRESSED -> #SWITCH_PRE_RELEASED -> #SWITCH_RELEASED.
 *  			-	DecSwitchCoverageTest: Transformation of the state of 
 *  				"-ve" switch from #SWITCH_RELEASED -> #SWITCH_PRE_PRESSED ->
 *  				#SWITCH_PRESSED -> #SWITCH_PRE_RELEASED -> #SWITCH_RELEASED.
 *  			
 *	@{
 */

/**
 *  \brief	It performs the transformation of the state of "+ve" switch 
 *  		from #SWITCH_RELEASED -> #SWITCH_PRE_PRESSED -> 
 *  		#SWITCH_PRESSED -> #SWITCH_PRE_RELEASED -> 
 *  		#SWITCH_RELEASED. And track the change in motor speed after every transition.
 *  
 *  \details It's expected that the motor speed increments only when 
 *  		 the switch in pre_pressed state and still the same on the 
 *  		 other states.
 */
TEST(ONE_SWIICH_COVERAGE_speed_control_test, IncSwitchCoverageTest)
{
	/* Needed variables */
    int previous_speed;

    /* Initial speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Released state, Released in initialization */
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pre_pressed state */
	FAKE_SW_setSwState(SWITCH_INCREMENT, SWITCH_PRE_PRESSED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed + 1, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pressed state */
	FAKE_SW_setSwState(SWITCH_INCREMENT, SWITCH_PRESSED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pre_released state */
	FAKE_SW_setSwState(SWITCH_INCREMENT, SWITCH_PRE_RELEASED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Released state */
	FAKE_SW_setSwState(SWITCH_INCREMENT, SWITCH_RELEASED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());	
}
 
/**
 *  \brief	It performs the transformation of the state of "-ve" switch 
 *  		from #SWITCH_RELEASED -> #SWITCH_PRE_PRESSED -> 
 *  		#SWITCH_PRESSED -> #SWITCH_PRE_RELEASED -> 
 *  		#SWITCH_RELEASED. And track the change in motor speed after every transition.
 *  
 *  \details It's expected that the motor speed decrements only when 
 *  		 the switch in pre_pressed state and still the same on the 
 *  		 other states.
 */
TEST(ONE_SWIICH_COVERAGE_speed_control_test, DecSwitchCoverageTest)
{
	/* Needed variables */
    int previous_speed;

    /* Initial speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Released state, Released in initialization */
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pre_pressed state */
	FAKE_SW_setSwState(SWITCH_DECREMENT, SWITCH_PRE_PRESSED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 1, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pressed state */
	FAKE_SW_setSwState(SWITCH_DECREMENT, SWITCH_PRESSED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pre_released state */
	FAKE_SW_setSwState(SWITCH_DECREMENT, SWITCH_PRE_RELEASED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Released state */
	FAKE_SW_setSwState(SWITCH_DECREMENT, SWITCH_RELEASED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());	
}

/**
 *  \brief	It performs the transformation of the state of "P" switch 
 *  		from #SWITCH_RELEASED -> #SWITCH_PRE_PRESSED -> 
 *  		#SWITCH_PRESSED -> #SWITCH_PRE_RELEASED -> 
 *  		#SWITCH_RELEASED. And track the change in motor speed after every transition.
 *  
 *  \details It's expected that the motor speed decrements only when 
 *  		 the switch in pressed state for more than or equal to
 *  		 30 seconds and still the same on the other states.
 *  		 We did the state transition and tested for several
 *  		 pressing duration(0, 30, 60, and 90 seconds) when it's 
 *  		 pressed and test the motor speed at each pressing duration.
 */
TEST(ONE_SWIICH_COVERAGE_speed_control_test, PSwitchCoverageTest)
{
	/* Needed variables */
    int previous_speed;

    /* Initial speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Released state, Released in initialization */
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pre_pressed state */
	FAKE_SW_setSwState(SWITCH_P, SWITCH_PRE_PRESSED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pressed state, with 0 pressing duration */
	FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pressed state, with 30 pressing duration */
	FAKE_SW_setSwDuration(30000);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 1, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pressed state, with 60 pressing duration */
	FAKE_SW_setSwDuration(60000);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 2, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pressed state, with 90 pressing duration */
	FAKE_SW_setSwDuration(90000);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed - 3, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Pre_released state */
	FAKE_SW_setSwState(SWITCH_P, SWITCH_PRE_RELEASED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());
	
	/* Update speed */
	previous_speed = Motor_GetSpeed();
    /* Act */
	/* Released state */
	FAKE_SW_setSwState(SWITCH_P, SWITCH_RELEASED);
    Motor_SetSpeed(SpeedControl_CalcNewSpeed());

    /* Assertion */
    LONGS_EQUAL(previous_speed, Motor_GetSpeed());	
}

/* ONE_SWIICH_COVERAGE_speed_control_test closure */
/**
 *  @}
 */
 
/* speed_control_test closure */
/**
 *  @}
 */

/* default_speed_control_test runner */
TEST_GROUP_RUNNER(default_speed_control_test)
{
    printf("\n\t======================= Default Test Cases =======================\n\n");
    printf("\t");
	RUN_TEST_CASE(default_speed_control_test, AllSwitchesAreReleasedAndDurationIsZeroAndSpeedIsMediumSpeed);
    printf("\t");
    RUN_TEST_CASE(default_speed_control_test, OnlyIncSwitchIsPrePressedAndOthersAreReleased);
    printf("\t");
    RUN_TEST_CASE(default_speed_control_test, OnlyDecSwitchIsPrePressedAndOthersAreReleased);
    printf("\t");
    RUN_TEST_CASE(default_speed_control_test, OnlyPSwitchIsPressedAndOthersAreReleasedAndPeriodIsEqualTo30Seconds);
	printf("\t======================= Default Test  Done =======================\n\n");
	
}

/* priority_speed_control_test runner */
TEST_GROUP_RUNNER(priority_speed_control_test)
{
	printf("\n\t======================= Priority Test Cases =======================\n\n");
    printf("\t");
	RUN_TEST_CASE(priority_speed_control_test, PSwitchIsPressedAndOthersArePrePressedAndDurationIs30s);
	printf("\t");
	RUN_TEST_CASE(priority_speed_control_test, PSwitchIsReleasedAndOthersArePrePressed);
	printf("\n\t======================= Priority Test  Done =======================\n\n");	
}

/* EP_BVA_speed_control_test runner */
TEST_GROUP_RUNNER(EP_BVA_speed_control_test)
{
	printf("\n\t======================= EP_BVA Test Cases =======================\n\n");
    printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsZero);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIs15Seconds);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustLessThan30Seconds);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIs30Seconds);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustGreaterthan30Seconds);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustLessThan60Seconds);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIs60Seconds);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustGreaterthan60Seconds);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustLessThan90Seconds);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIs90Seconds);
	printf("\t");
	RUN_TEST_CASE(EP_BVA_speed_control_test, PSwitchIsPressedAndDurationIsJustGreaterthan90Seconds);
	printf("\n\t======================= EP_BVA Test  Done =======================\n\n");	
}



/* ONE_SWIICH_COVERAGE_speed_control_test runner */
TEST_GROUP_RUNNER(ONE_SWIICH_COVERAGE_speed_control_test)
{
	printf("\n\t======================= 1-Switch coverage Test Cases =======================\n\n");
	printf("\t");
	RUN_TEST_CASE(ONE_SWIICH_COVERAGE_speed_control_test, IncSwitchCoverageTest);
	printf("\t");
	RUN_TEST_CASE(ONE_SWIICH_COVERAGE_speed_control_test, DecSwitchCoverageTest);
	printf("\t");
	RUN_TEST_CASE(ONE_SWIICH_COVERAGE_speed_control_test, PSwitchCoverageTest);
	printf("\n\t======================= 1-Switch coverage Test  Done =======================\n\n");	
}


/* speed_control_test runner */
TEST_GROUP_RUNNER(speed_control_test)
{
    printf("======================= Testing Speed Control Module =======================\n\n");
    RUN_TEST_GROUP(default_speed_control_test);
    RUN_TEST_GROUP(priority_speed_control_test);
    RUN_TEST_GROUP(EP_BVA_speed_control_test);
    RUN_TEST_GROUP(ONE_SWIICH_COVERAGE_speed_control_test);
    printf("\n==================== Testing Speed Control  Module Done ====================\n\n\n");
}

