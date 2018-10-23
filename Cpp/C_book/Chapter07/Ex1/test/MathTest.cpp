/*
 * =====================================================================================
 *
 *       Filename:  MathTest.cpp
 *
 *    Description:  This class holds all Math test cases.
 *
 *        Version:  1.0
 *        Created:  12/09/2016 09:37:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan <jegan@tektutor.org>
 *   Organization:  TekTutor <www.tektutor.org>
 *
 * =====================================================================================
 */
#include <gtest/gtest.h>
#include "Math.h"

TEST( MathTest, testAddition ) {
	Math math;

	int expectedResult = 100;
	int actualResult   = math.add ( 70, 30 );

	EXPECT_EQ ( expectedResult, actualResult );
}

