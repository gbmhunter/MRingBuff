//!
//! @file 			PeekReadTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-12
//! @last-modified 	2014-09-26
//! @brief 			Tests that RingBuff::Peek() works correctly.
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
	MTEST_GROUP(PeekReadTests)
	{

		MTEST(PeekReadTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			// Insert 5 characters
			char someChars[] = "12345";
			ringBuff.Write(someChars);

			// Now read these out with the Peek() function,
			// this shouldn't remove the data from the ring buffer
			char readBuff[20];
			ringBuff.Peek((uint8_t*)readBuff, 5);

			CHECK_EQUAL(readBuff, "12345");

			// Now make sure there are still 5 elements in the buffer
			CHECK_EQUAL(ringBuff.NumElements(), 5);

			// Now read them out like usual to make sure they havn't been corrupted
			memset(readBuff, '\0', sizeof(readBuff));
			ringBuff.Read((uint8_t*)readBuff, 5);

			CHECK_EQUAL(readBuff, "12345");

			// Now make sure the elements are gone
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

	} // GROUP(PeekReadTests)
} // namespace RingBuffTestsNs
