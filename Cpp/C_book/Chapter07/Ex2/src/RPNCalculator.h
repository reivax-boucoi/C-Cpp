#ifndef __RPNCALCULATOR_H__
#define __RPNCALCULATOR_H__

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
using namespace std;

#include "MathFactory.h"


class RPNCalculator {
private:
	string strMathOperators;
	bool isMathOperator(string);
public:
	RPNCalculator();
	double evaluate (string);

};

#endif /* __RPNCALCULATOR_H__ */
