//!
//! @file 			TooMuchDataTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-07-25
//! @last-modified 	2014-09-25
//! @brief 			Tests that the buffer behaves correctly when 'too much' data is written to it.
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
	MTEST_GROUP(TooMuchDataTests)
	{

		MTEST(TooMuchDataTest)
		{
			// Make buffer with 10 bytes of memory
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert characters
			char someChars[] = "0123456789012";

			// Should only write 10 bytes, even though 12 are specified
			CHECK_EQUAL(ringBuff.Write((uint8_t*)someChars, 12, RingBuffNs::RingBuff::ReadWriteLogic::ANY), 10);

			// Now read these out
			char readBuff[20] = {0};
			// Should only read 10 elements, even though 12 are specified
			CHECK_EQUAL(ringBuff.Read((uint8_t*)readBuff, 12), 10);

			CHECK_EQUAL(readBuff, "0123456789");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

			// Now insert more
			ringBuff.Write((uint8_t*)someChars, 10, RingBuffNs::RingBuff::ReadWriteLogic::ANY);

			memset(readBuff, '\0', sizeof(readBuff));
			ringBuff.Read((uint8_t*)readBuff, 10);

			// Check data is read correctly
			CHECK_EQUAL(readBuff, "0123456789");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

	} // GROUP(TooMuchDataTests)
} // namespace RingBuffTestsNs
