//!
//! @file 			NumElementsTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/07/25
//! @last-modified 	2014/07/25
//! @brief 			Tests that the RingBuff::NumElements() method works correctly.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(NumElementsTests)
	{

		TEST(BasicNumElementsTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			char someChars[] = "testing";
			ringBuff.Write(someChars);

			// Check num elements is calculated correctly
			CHECK_EQUAL(ringBuff.NumElements(), 7);
		}

		TEST(WrappingNumElementsTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			// Insert 5 characters
			char someChars[] = "12345";
			ringBuff.Write(someChars);

			// Now read these out
			char readBuff[5];
			ringBuff.Read((uint8_t*)readBuff, 5);

			// Now insert 7 more, this should wrap around
			char someChars2[] = "1234567";
			ringBuff.Write(someChars2);

			// Check num elements is calculated correctly
			CHECK_EQUAL(ringBuff.NumElements(), 7);
		}

	} // SUITE(NumElementsTests)
} // namespace RingBuffTest
