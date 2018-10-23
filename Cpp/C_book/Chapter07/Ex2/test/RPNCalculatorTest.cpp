#include "RPNCalculatorTest.h"

TEST(RPNCalculatorTest, testSimpleAddition) {

	RPNCalculator calculator;

	double expectedResult = 25.0;
	double actualResult = calculator.evaluate("10 15 +");

	ASSERT_EQ ( expectedResult, actualResult );

}

TEST(RPNCalculatorTest, testSimpleSubtraction) {

	RPNCalculator calculator;

	double expectedResult = 15.0;
	double actualResult = calculator.evaluate("25 10 -");

	ASSERT_EQ ( expectedResult, actualResult );

}

TEST(RPNCalculatorTest, testSimpleMultiplication) {

	RPNCalculator calculator;

	double expectedResult = 250.0;
	double actualResult = calculator.evaluate("25 10 *");

	ASSERT_EQ ( expectedResult, actualResult );

}

TEST(RPNCalculatorTest, testSimpleDivision) {

	RPNCalculator calculator;

	double expectedResult = 25.0;
	double actualResult = calculator.evaluate("250 10 /");

	ASSERT_EQ ( expectedResult, actualResult );

}

TEST(RPNCalculatorTest, testComplexRPNExpression) {

	RPNCalculator calculator;

	double expectedResult = 2.33333;
	double actualResult = calculator.evaluate("2 5 * 4 + 7 2 - 1 + /");

	ASSERT_NEAR( expectedResult, actualResult, 4 );

}

