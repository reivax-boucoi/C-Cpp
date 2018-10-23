/*
 * =====================================================================================
 *
 *       Filename:  MathFactory.h
 *
 *    Description:  MathFactory is a Factory method that helps create concrete math objects.
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

#include <string>
#include <map>
using namespace std;

#include "MathOperator.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "NullObject.h"

class MathFactory : public MathOperator {
private:
	static map<string,MathOperator*> *pStringToMathObjectMap;
	static map<string,MathOperator*>* static_init_block();
public:
	static MathOperator* getMathObject( string strMathOperator = "" ); 
};
