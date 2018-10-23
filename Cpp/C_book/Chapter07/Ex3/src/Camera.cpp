/*
 * =====================================================================================
 *
 *       Filename:  Camera.cpp
 *
 *    Description:  Camera source file
 *
 *        Version:  1.0
 *        Created:  01/11/2017 08:17:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan <jegan@tektutor.org>
 *   Organization:  TekTutor <http://www.tektutor.org>
 *
 * =====================================================================================
 */
#include "Camera.h"

Camera::Camera() {

}

bool Camera::ON() {
	cout << "Camera ON hardware interaction happens here ..." << endl;
	return true;
}

bool Camera::OFF() {
	cout << "Camera OFF hardware interaction happens here ..." << endl;
	return true;
}


