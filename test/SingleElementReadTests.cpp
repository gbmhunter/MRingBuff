//!
//! @file 			SingleElementReadTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-07-29
//! @last-modified 	2014-09-25
//! @brief 			Tests that the method 'uint8_t RingBuff::Read()' works correctly.
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
	MTEST_GROUP(SingleElementReadTests)
	{

		MTEST(SingleElementReadTest1)
		{
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert 5 characters
			char * someChars = "12345";
			ringBuff.Write(someChars);

			// Now read these out
			char readBuff[20];
			uint8_t x = 0;

			while(ringBuff.IsData())
			{
				// Do a single element read
				readBuff[x] = ringBuff.Read();
				x++;
			}

			CHECK_EQUAL(x, 5);
			CHECK_EQUAL(readBuff, "12345");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

		MTEST(SingleElementReadTest2)
		{
			RingBuffNs::RingBuff ringBuff(3);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert characters
			char * someChars = "12345";
			CHECK_EQUAL(ringBuff.Write(someChars, RingBuffNs::RingBuff::ReadWriteLogic::ANY), 3);

			// Now read these out, only 3 should of been written
			char readBuff[20];
			uint8_t x = 0;

			while(ringBuff.IsData())
			{
				// Do a single element read
				readBuff[x] = ringBuff.Read();
				x++;
			}

			CHECK_EQUAL(x, 3);
			CHECK_EQUAL(readBuff, "123");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

	} // GROUP(SingleElementReadTests)
} // namespace RingBuffTestsNs
