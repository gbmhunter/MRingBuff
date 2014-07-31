//!
//! @file 			SingleElementWriteTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/08/01
//! @last-modified 	2014/08/01
//! @brief 			Tests that the method 'bool RingBuff::Write(char charToWrite)' works correctly.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>
#include <cstring>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(SingleElementWriteTests)
	{

		TEST(SingleElementWriteTest1)
		{
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert 1 character
			ringBuff.Write('a');

			// Now read these out
			char readBuff[20];
			uint8_t x = 0;

			while(ringBuff.IsData())
			{
				// Do a single element read
				readBuff[x] = ringBuff.Read();
				x++;
			}

			CHECK_EQUAL(1, x);
			CHECK_EQUAL("a", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

		}

		TEST(SingleElementReadTest2)
		{
			RingBuffNs::RingBuff ringBuff(3);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

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

			CHECK_EQUAL(3, x);
			CHECK_EQUAL("abc", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

		}

	} // SUITE(SingleElementWriteTests)
} // namespace RingBuffTest
