//!
//! @file 			IsDataTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-07-29
//! @last-modified 	2014-09-25
//! @brief 			Tests that the method RingBuff::IsData() works correctly.
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
MTEST_GROUP(IsDataTests)
	{

		MTEST(IsDataTest)
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
				ringBuff.Read((uint8_t*)&readBuff[x], 1);
				x++;
			}

			CHECK_EQUAL(x, 5);
			CHECK_EQUAL(readBuff, "12345");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

	} // GROUP(IsDataTests)
} // namespace RingBuffTestsNs
