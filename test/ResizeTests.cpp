//!
//! @file 			ResizeTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/07/25
//! @last-modified 	2014/07/25
//! @brief 			Tests that the RingBuff::Resize() method works correctly.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(ResizeTests)
	{

		TEST(BasicResizeWithNoDataTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.Resize(20))
				CHECK(false);

			// Check num elements is calculated correctly
			CHECK_EQUAL(ringBuff.Capacity(), 20);
			CHECK_EQUAL(ringBuff.NumElements(), 0);
		}

		TEST(IncreaseResizeWithNoWrapTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			// Insert 5 characters
			char someChars[] = "12345";
			ringBuff.Write(someChars);

			// Read one
			char readBuff1[5];
			ringBuff.Read((uint8_t*)readBuff1, 1);

			// Now resize to 20
			if(!ringBuff.Resize(20))
				CHECK(false);

			char readBuff2[5];
			ringBuff.Read((uint8_t*)readBuff2, 4);

			// Check data is still correct
			CHECK_EQUAL(readBuff2, "2345");
			CHECK_EQUAL(ringBuff.NumElements(), 0);
		}

		TEST(IncreaseResizeWithWrapTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert 5 characters
			char someChars[] = "12345";
			ringBuff.Write(someChars);

			// Now read these out
			char readBuff[5];
			ringBuff.Read((uint8_t*)readBuff, 5);

			// Now insert 7 more, this should wrap around
			char someChars2[] = "1234567";
			ringBuff.Write(someChars2);

			// Now resize to 20
			if(!ringBuff.Resize(20))
				CHECK(false);

			char readBuff2[8] = {0};
			ringBuff.Read((uint8_t*)readBuff2, 7);

			// Check num elements is calculated correctly
			CHECK_EQUAL(readBuff2, "1234567");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

		TEST(DecreaseResizeWithNoWrapTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			// Insert 5 characters
			char someChars[] = "123456789";
			ringBuff.Write(someChars);

			// Read one
			char readBuff1[5];
			ringBuff.Read((uint8_t*)readBuff1, 1);

			// Now resize to 5
			if(!ringBuff.Resize(5))
				CHECK(false);

			char readBuff2[5];
			ringBuff.Read((uint8_t*)readBuff2, 5);

			// Check data is still correct
			CHECK_EQUAL(readBuff2, "23456");
			CHECK_EQUAL(ringBuff.NumElements(), 0);
		}

		TEST(DecreaseResizeWithWrapTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert 5 characters
			char someChars[] = "12345";
			ringBuff.Write(someChars);

			// Now read these out
			char readBuff[5];
			ringBuff.Read((uint8_t*)readBuff, 5);

			// Now insert 7 more, this should wrap around
			char someChars2[] = "1234567";
			ringBuff.Write(someChars2);

			// Now resize to 5
			if(!ringBuff.Resize(5))
				CHECK(false);

			char readBuff2[6] = {0};
			ringBuff.Read((uint8_t*)readBuff2, 5);

			// Check num elements is calculated correctly
			CHECK_EQUAL(readBuff2, "12345");
			CHECK_EQUAL(ringBuff.NumElements(), 0);

		}

	} // SUITE(ResizeTests)
} // namespace RingBuffTest
