//!
//! @file 			IsDataTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/07/29
//! @last-modified 	2014/07/29
//! @brief 			Tests that the method RingBuff::IsData() works correctly.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>
#include <cstring>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(IsDataTests)
	{

		TEST(IsDataTest)
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

	} // SUITE(IsDataTests)
} // namespace RingBuffTest
