//!
//! @file 			WriteStringTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-07-28
//! @last-modified 	2014-09-25
//! @brief 			Tests that Write(char* string) works correctly.
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
	MTEST_GROUP(WriteStringTests)
	{

		MTEST(WriteStringTest)
		{
			// Make buffer with 10 bytes of memory
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert characters
			char *myMsg = "hello";

			// Should write 5 characters
			CHECK_EQUAL(ringBuff.Write(myMsg), 5);

			// Now read these out
			char readBuff[20] = {0};
			// Should only read 5 elements, even though 12 are specified
			CHECK_EQUAL(ringBuff.Read((uint8_t*)readBuff, 12), 5);

			CHECK_EQUAL(readBuff, "hello");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

		MTEST(WriteToMuchTest)
		{
			// Make buffer with 10 bytes of memory
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Create C string
			char *myMsg = "hello!!!";

			// Should write 8 characters
			CHECK_EQUAL(ringBuff.Write(myMsg), 8);

			// Should write 0 characters,
			// since string will not fit in buffer
			CHECK_EQUAL(ringBuff.Write(myMsg), 0);

			// Now read out buffer
			char readBuff[20] = {0};
			// Should only read 8 elements, even though 12 are specified
			CHECK_EQUAL(ringBuff.Read((uint8_t*)readBuff, 12), 8);

			CHECK_EQUAL(readBuff, "hello!!!");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

	} // GROUP(WriteStringTests)
} // namespace RingBuffTestsNs
