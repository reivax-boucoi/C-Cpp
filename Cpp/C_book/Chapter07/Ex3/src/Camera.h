/*
 * =====================================================================================
 *
 *       Filename:  Camera.h
 *
 *    Description:  Camera header file.
 *
 *        Version:  1.0
 *        Created:  01/11/2017 08:08:45 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan <jegan@tektutor.org>
 *   Organization:  TekTutor <http://www.tektutor.org>
 *
 * =====================================================================================
 */

#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <iostream>
using namespace std;

class Camera {
public:
	Camera();
	virtual bool ON();
	virtual bool OFF();
};

#endif /* __CAMERA_H__ */
