//!
//! @file 			SingleElementReadTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/07/29
//! @last-modified 	2014/07/29
//! @brief 			Tests that the method 'uint8_t RingBuff::Read()' works correctly.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>
#include <cstring>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(SingleElementReadTests)
	{

		TEST(SingleElementReadTest1)
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

			CHECK_EQUAL(5, x);
			CHECK_EQUAL("12345", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

		}

		TEST(SingleElementReadTest2)
		{
			RingBuffNs::RingBuff ringBuff(3);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert characters
			char * someChars = "12345";
			CHECK_EQUAL(3, ringBuff.Write(someChars, RingBuffNs::RingBuff::ReadWriteLogic::ANY));

			// Now read these out, only 3 should of been written
			char readBuff[20];
			uint8_t x = 0;

			while(ringBuff.IsData())
			{
				// Do a single element read
				readBuff[x] = ringBuff.Read();
				x++;
			}

			CHECK_EQUAL(3, x);
			CHECK_EQUAL("123", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

		}

	} // SUITE(SingleElementReadTests)
} // namespace RingBuffTest
