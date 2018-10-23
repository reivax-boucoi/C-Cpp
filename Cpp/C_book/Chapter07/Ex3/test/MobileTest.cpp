/*
 * =====================================================================================
 *
 *       Filename:  MobileTest.cpp
 *
 *    Description:  MobileTest source file
 *
 *        Version:  1.0
 *        Created:  01/11/2017 08:22:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jeganathan Swaminathan <jegan@tektutor.org>
 *   Organization:  TekTutor <http://www.tektutor.org>
 *
 * =====================================================================================
 */
#include "MobileTest.h"

TEST (MobileTest, testPowerOnWhenCameraONSucceeds) {

	//Mocking
	MockedCamera *pMockedCamera = new MockedCamera;

	//Stubbing
	EXPECT_CALL( *pMockedCamera, ON() ).Times(1).WillOnce(Return(true));

	//Construction Dependency Injection
	Mobile mobile ( pMockedCamera );

	//Verify Code Under Test
	ASSERT_TRUE ( mobile.powerOn() );

	delete pMockedCamera;

}

