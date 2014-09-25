//!
//! @file 			NumElementsTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-07-25
//! @last-modified 	2014-09-25
//! @brief 			Tests that the RingBuff::NumElements() method works correctly.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <stdio.h>

//===== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MRingBuffApi.hpp"

namespace RingBuffTestsNs
{
	MTEST_GROUP(NumElementsTests)
	{

		MTEST(BasicNumElementsTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			char someChars[] = "testing";
			ringBuff.Write(someChars);

			// Check num elements is calculated correctly
			CHECK_EQUAL(ringBuff.NumElements(), 7);
		}

		MTEST(WrappingNumElementsTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			// Insert 5 characters
			char someChars[] = "12345";
			ringBuff.Write(someChars);

			// Now read these out
			char readBuff[5];
			ringBuff.Read((uint8_t*)readBuff, 5);

			// Now insert 7 more, this should wrap around
			char someChars2[] = "1234567";
			ringBuff.Write(someChars2);

			// Check num elements is calculated correctly
			CHECK_EQUAL(ringBuff.NumElements(), 7);
		}

	} // GROUP(NumElementsTests)
} // namespace RingBuffTestsNs
