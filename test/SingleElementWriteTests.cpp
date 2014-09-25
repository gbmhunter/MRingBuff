//!
//! @file 			SingleElementWriteTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-01
//! @last-modified 	2014-09-26
//! @brief 			Tests that the method 'bool RingBuff::Write(char charToWrite)' works correctly.
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
	MTEST_GROUP(SingleElementWriteTests)
	{

		MTEST(SingleElementWriteTest1)
		{
			RingBuffNs::RingBuff ringBuff(10);

			// Insert 1 character
			ringBuff.Write('a');

			// Now read these out
			char readBuff[20] = {0};
			uint8_t x = 0;

			while(ringBuff.IsData())
			{
				// Do a single element read
				readBuff[x] = ringBuff.Read();
				x++;
			}

			CHECK_EQUAL(x, 1);
			CHECK_EQUAL(readBuff, "a");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

		MTEST(SingleElementReadTest2)
		{
			RingBuffNs::RingBuff ringBuff(3);

			// Insert characters
			ringBuff.Write('a');
			ringBuff.Write('b');
			ringBuff.Write('c');

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
			CHECK_EQUAL(readBuff, "abc");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

	} // GROUP(SingleElementWriteTests)
} // namespace RingBuffTestsNs
