/*
 * =====================================================================================
 *
 *       Filename:  MobileTest.h
 *
 *    Description:  MobileTest Test Case header
 *
 *        Version:  1.0
 *        Created:  01/11/2017 08:20:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan <jegan@tektutor.org>
 *   Organization:  TekTutor <http://www.tektutor.org>
 *
 * =====================================================================================
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::Return;

#include "Mobile.h"

class MockedCamera : public Camera {
public:
	MOCK_METHOD0( ON,  bool() );
	MOCK_METHOD0( OFF, bool() );
};
