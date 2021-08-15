/**
 *  \file	fake_switch_test.c
 *  \brief	This file includes the test cases of fake_switch module.
 *  \author Ahmed Wageh
 */
#include "fake_switch.h"
#include "../unity/unity_fixture.h"

/* Test group declaration */
TEST_GROUP(FakeSwitch);

/* FakeSwitch group setup and tear_down function */
TEST_SETUP(FakeSwitch)
{
    FAKE_SW_init();
}

TEST_TEAR_DOWN(FakeSwitch)
{
    FAKE_SW_destroy();
}

/* Fake switch test cases */
/**
 *  \defgroup	fake_switch_test_cases	Fake switch module test cases
 *  This is the test cases for fake switch module.
 *
 *  \details	This is for testing the functionality of fake switch module
 *  			(Switches \ref Switches_States_t getters and setters
 *  			and "P" switch pressing duration getter and setters)
 *  			It tests the following test cases for fake switches:
 *  				-	IncSwitchReleasedAfterInit: To make sure that the \ref
 *  					Switches_States_t of "+ve" switch is #SWITCH_RELEASED.
 *					-	DecSwitchReleasedAfterInit: To make sure that the \ref
 *  					Switches_States_t of "-ve" switch is #SWITCH_RELEASED.
 *  				-	PSwitchReleasedAfterInit: To make sure that the \ref
 *  					Switches_States_t of "P" switch is #SWITCH_RELEASED.
 *  				-	PDurationIsZeroAfterInit: To make sure that the pressing
 *  					duration of "P" switch is 0 after initialization.
 *					-	setIncSwState: To make sure that the \ref FAKE_SW_setIncSwState
 *  					functionality is working well.
 *  				-	setDecSwState: To make sure that the \ref FAKE_SW_setDecSwState
 *  					functionality is working well.
 *  				-	setPSwState: To make sure that the \ref FAKE_SW_setPSwState
 *  					functionality is working well.
 *  				-	setPSwDuration: To make sure that the \ref FAKE_SW_setSwDuration
 *  					functionality is working well.
 *  @{
 */

/**
 *  \brief To check the status of "+ve" switch after initialization.
 *
 *  \details This test case to make sure that the \ref Switches_States_t
 *  		 of "+ve" switch is #SWITCH_RELEASED after initialization.
 */
TEST(FakeSwitch, IncSwitchReleasedAfterInit)
{
    /* Note that init is called in TEST_SETUP() */
    LONGS_EQUAL(SWITCH_RELEASED, FAKE_SW_getSwState(SWITCH_INCREMENT));
}

/**
 *  \brief To check the status of "-ve" switch after initialization.
 *
 *  \details This test case to make sure that the \ref Switches_States_t
 *  		 of "-ve" switch is #SWITCH_RELEASED after initialization.
 */
TEST(FakeSwitch, DecSwitchReleasedAfterInit)
{
    /* Note that init is called in TEST_SETUP() */
    LONGS_EQUAL(SWITCH_RELEASED, FAKE_SW_getSwState(SWITCH_DECREMENT));
}

/**
 *  \brief To check the status of "P" switch after initialization.
 *
 *  \details This test case to make sure that the \ref Switches_States_t
 *  		 of "P" switch is #SWITCH_RELEASED after initialization.
 */
TEST(FakeSwitch, PSwitchReleasedAfterInit)
{
    /* Note that init is called in TEST_SETUP() */
    LONGS_EQUAL(SWITCH_RELEASED, FAKE_SW_getSwState(SWITCH_P));
}

/**
 *  \brief	To check the pressing duration of "P" switch
 *  		after initialization.
 *
 *  \details This test case to make sure that the pressing duration of "P" switch
 *  		after initialization is zero.
 */
TEST(FakeSwitch, PDurationIsZeroAfterInit)
{
    /* Note that init is called in TEST_SETUP() */
	LONGS_EQUAL(0, FAKE_SW_getSwDuration());
}

/**
 *  \brief	To check the functionality of "+ve" \ref Switches_States_t
 *  		setter.
 *
 *  \par Given:	"+ve" switch State is #SWITCH_RELEASED
 *  \par When: "+ve" state is set to #SWITCH_PRESSED
 *  \par Then: "+ve" state is #SWITCH_PRESSED
 */
TEST(FakeSwitch, setIncSwState)
{
	/*
	 *  "+ve" switch state is SWITCH_RELEASED after initialization
	 */
	FAKE_SW_setSwState(SWITCH_INCREMENT, SWITCH_PRESSED);
    LONGS_EQUAL(SWITCH_PRESSED, FAKE_SW_getSwState(SWITCH_INCREMENT));
}

/**
 *  \brief	To check the functionality of "-ve" \ref Switches_States_t
 *  		setter.
 *
 *  \par Given:	"-ve" switch State is #SWITCH_RELEASED
 *  \par When: "-ve" state is set to #SWITCH_PRESSED
 *  \par Then: "-ve" state is #SWITCH_PRESSED
 */
TEST(FakeSwitch, setDecSwState)
{
    /*
	 *  "-ve" switch state is SWITCH_RELEASED after initialization
	 */
	FAKE_SW_setSwState(SWITCH_DECREMENT, SWITCH_PRESSED);
    LONGS_EQUAL(SWITCH_PRESSED, FAKE_SW_getSwState(SWITCH_DECREMENT));
}

/**
 *  \brief	To check the functionality of "P" \ref Switches_States_t
 *  		setter.
 *
 *  \par Given:	"P" switch State is #SWITCH_RELEASED
 *  \par When: "P" state is set to #SWITCH_PRESSED
 *  \par Then: "P" state is #SWITCH_PRESSED
 */
TEST(FakeSwitch, setPSwState)
{
	/*
	 *  "P" switch state is SWITCH_RELEASED after initialization
	 */
    FAKE_SW_setSwState(SWITCH_P, SWITCH_PRESSED);
    LONGS_EQUAL(SWITCH_PRESSED, FAKE_SW_getSwState(SWITCH_P));
}

/**
 *  \brief	To check the functionality of "P" switch pressing duration
 *  		setter.
 *
 *  \par Given:	"P" pressing duration = 0 after initialization
 *  \par When: "P" pressing duration is set to 124
 *  \par Then: "P" pressing duration is 124
 */
TEST(FakeSwitch, setPSwDuration)
{
    /*
	 *  "P" switch pressing duration is 0 after initialization
	 */
    FAKE_SW_setSwDuration(124);
    LONGS_EQUAL(124, FAKE_SW_getSwDuration());
}
/**
 *  @}
 */

/**
 *  \brief Fake switch runner for all test techniques for fake switch module.
 */
TEST_GROUP_RUNNER(FakeSwitch)
{
    printf("======================= Testing Fake Switch Module =======================\n\n");
    RUN_TEST_CASE(FakeSwitch, IncSwitchReleasedAfterInit);
    RUN_TEST_CASE(FakeSwitch, DecSwitchReleasedAfterInit);
    RUN_TEST_CASE(FakeSwitch, PSwitchReleasedAfterInit);
    RUN_TEST_CASE(FakeSwitch, PDurationIsZeroAfterInit);
    RUN_TEST_CASE(FakeSwitch, setIncSwState);
    RUN_TEST_CASE(FakeSwitch, setDecSwState);
    RUN_TEST_CASE(FakeSwitch, setPSwState);
    RUN_TEST_CASE(FakeSwitch, setPSwDuration);
    printf("\n==================== Testing Fake Switch  Module Done ====================\n\n\n");
}

