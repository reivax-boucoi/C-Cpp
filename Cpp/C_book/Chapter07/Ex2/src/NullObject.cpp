/*
 * =====================================================================================
 *
 *       Filename:  NullObject.cpp
 *
 *    Description:  NullObject is a subclass of MathOperator abstract class.
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

#include "NullObject.h"

double NullObject::evaluate(int firstInput,int secondInput) {
	cerr << "Choose a valid math operator - Error occurred" << endl;
	return 0.0;
}
