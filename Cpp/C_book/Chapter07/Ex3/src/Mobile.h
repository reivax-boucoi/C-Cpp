/*
 * =====================================================================================
 *
 *       Filename:  Mobile.h
 *
 *    Description:  Mobile class header
 *
 *        Version:  1.0
 *        Created:  01/11/2017 07:38:46 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan <jegan@tektutor.org>
 *   Organization:  TekTutor <http://www.tektutor.org>
 *
 * =====================================================================================
 */

#ifndef __MOBILE_H__
#define __MOBILE_H__

#include <iostream>
using namespace std;

#include "Camera.h"

class Mobile {
private:
	Camera *pCamera;
public:
	Mobile();
	Mobile(Camera *pCamera);
	bool powerOn();
	bool powerOff();
};

#endif /* __MOBILE_H__ */

