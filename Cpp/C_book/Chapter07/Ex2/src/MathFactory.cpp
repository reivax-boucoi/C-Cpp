/*
 * =====================================================================================
 *
 *       Filename:  MathFactory.cpp
 *
 *    Description:  MathFactory is a factory method class that helps create concrete math objects.
 *
 *        Version:  1.0
 *        Created:  01/09/2017 04:33:53 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan  <jegan@tektutor.org>
 *   Organization:  TekTutor <http://www.tektutor.org>
 *
 * =====================================================================================
 */
#include "MathFactory.h"


map<string,MathOperator*> * MathFactory::static_init_block() {
	map<string, MathOperator*> *pStringToMathObjectMap = new map<string,MathOperator*>();

	pStringToMathObjectMap->insert ( make_pair("+",new Add()) );
	pStringToMathObjectMap->insert ( make_pair("-",new Subtract()) );
	pStringToMathObjectMap->insert ( make_pair("*",new Multiply()) );
	pStringToMathObjectMap->insert ( make_pair("/",new Divide()) );

	return pStringToMathObjectMap;
}

map<string,MathOperator*> * MathFactory::pStringToMathObjectMap = static_init_block();

MathOperator* MathFactory::getMathObject ( string typeOfMathObjectRequired ) {

	return pStringToMathObjectMap->find( typeOfMathObjectRequired )->second;

}

