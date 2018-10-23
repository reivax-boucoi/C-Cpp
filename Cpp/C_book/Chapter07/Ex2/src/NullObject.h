/*
 * =====================================================================================
 *
 *       Filename:  NullObject.h
 *
 *    Description:  NullObject is a subclass of MathOperator abstract class.
 *    		    The purpose of this object is to offload all error handling logic
 *    		    into one single class for many subclasses.
 *
 *    		    This helps segregate business logic from error handling logic.
 *
 *        Version:  1.0
 *        Created:  01/09/2017 04:24:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan <jegan@tektutor.org> 
 *   Organization:  TekTutor http://www.tektutor.org
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;
#include "MathOperator.h"

class NullObject : public MathOperator {
public:
	double evaluate(int,int);
};
