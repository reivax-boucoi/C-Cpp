/*
 * =====================================================================================
 *
 *       Filename:  Multiply.cpp
 *
 *    Description:  Multiply is a subclass of MathOperator abstract class.
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

#include "Multiply.h"

double Multiply::evaluate(int firstInput,int secondInput) {
	return firstInput * secondInput;
}
