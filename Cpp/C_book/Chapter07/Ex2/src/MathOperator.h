/*
 * =====================================================================================
 *
 *       Filename:  MathOperator.h
 *
 *    Description:  An abstract math operation class that helps us invoke evaluate method
 *                  polymorphically on math operator sub classes that inherit this class.
 *        Version:  1.0
 *        Created:  01/09/2017 04:21:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan <jegan@tektutor.org>
 *   Organization:  TekTutor (http://www.tektutor.org)
 *
 * =====================================================================================
 */

#ifndef __MATHOPERATOR__H
#define __MATHOPERATOR__H

class MathOperator {
public:
	virtual double evaluate (int,int) = 0;
};

#endif /*  __MATHOPERATOR__H */
