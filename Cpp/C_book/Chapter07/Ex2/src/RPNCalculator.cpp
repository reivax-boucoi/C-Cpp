#include "RPNCalculator.h"

RPNCalculator::RPNCalculator() {
	strMathOperators = "+-*/";
}

bool RPNCalculator::isMathOperator(string strMathOperator) {
	return strMathOperators.find(strMathOperator) != string::npos;
}

double RPNCalculator::evaluate( string rpnMathExpression ) {

	MathOperator *pMathOperator = MathFactory::getMathObject();
	double firstNumber, secondNumber, result;
	stack<double> numberStack;

	stringstream rpnMathTokens(rpnMathExpression);
	istream_iterator<string> begin(rpnMathTokens);
	istream_iterator<string> end;

	vector<string> rpnTokens( begin, end );
	vector<string>::iterator pos = rpnTokens.begin();

	while ( pos != rpnTokens.end() ) {

		if ( isMathOperator( *pos ) ) {
			secondNumber = numberStack.top();
			numberStack.pop();
			firstNumber = numberStack.top();
			numberStack.pop();

			pMathOperator = MathFactory::getMathObject ( *pos );
			result = pMathOperator->evaluate ( firstNumber, secondNumber );
			numberStack.push ( result );
		}
		else
			numberStack.push( stod( *pos ) );
		++pos;
	}

	result = numberStack.top();
	return result;
}
