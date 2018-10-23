/*
 * =====================================================================================
 *
 *       Filename:  Mobile.cpp
 *
 *    Description:  Mobile class source file
 *
 *        Version:  1.0
 *        Created:  01/11/2017 08:02:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan <jegan@tektutor.org>
 *   Organization:  TekTutor <http://www.tektutor.org>
 *
 * =====================================================================================
 */
#include "Mobile.h"

Mobile::Mobile() {
	pCamera = new Camera;
}

Mobile::Mobile(Camera *pCamera) {
	this->pCamera = pCamera;
}

bool Mobile::powerOn() {
	cout << "\nInside Mobile powerOn() method" << endl;

	if (pCamera->ON()) {
		cout << "\nSome complex powerOn logic goes on here ..." << endl;
		return true;
	}

	cout << "\nSome complex powerOn failure logic goes on here ..." << endl;
	return false;
}

bool Mobile::powerOff() {
	cout << "\nInside Mobile powerOff() method" << endl;

	if (pCamera->OFF()) {
		cout << "\nSome complex powerOff logic goes on here ..." << endl;
		return true;
	}

	cout << "\nSome complex powerOff failure logic goes on here ..." << endl;
	return false;

}
