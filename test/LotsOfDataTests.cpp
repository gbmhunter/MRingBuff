//!
//! @file 			LotsOfDataTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-07-25
//! @last-modified 	2014-09-26
//! @brief 			Tests that the buffer does not do weird things when lots of data is read/written to it.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <stdio.h>
#include <cstring>

//===== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MRingBuffApi.hpp"

namespace RingBuffTestsNs
{
	MTEST_GROUP(LotsOfDataTests)
	{

		MTEST(LotsOfDataTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			// Insert 5 characters
			char someChars[] = "12345";
			ringBuff.Write(someChars);

			// Now read these out
			char readBuff[20];
			ringBuff.Read((uint8_t*)readBuff, 5);

			CHECK_EQUAL(readBuff, "12345");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

			// Now insert 7 more, this should wrap around
			char someChars2[] = "1234567";
			ringBuff.Write(someChars2);

			memset(readBuff, '\0', sizeof(readBuff));
			ringBuff.Read((uint8_t*)readBuff, 7);

			// Check num elements is calculated correctly
			CHECK_EQUAL(readBuff, "1234567");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

			ringBuff.Write(someChars2);

			memset(readBuff, '\0', sizeof(readBuff));
			ringBuff.Read((uint8_t*)readBuff, 7);

			// Check num elements is calculated correctly
			CHECK_EQUAL(readBuff, "1234567");
			CHECK_EQUAL(ringBuff.NumElements(), 0);


		}

	} // GROUP(LotsOfDataTests)
} // namespace RingBuffTestsNs
