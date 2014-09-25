//!
//! @file 			IsSpaceTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/08/01
//! @last-modified 	2014/08/01
//! @brief 			Tests that the method 'bool RingBuff::IsSpace()' works correctly.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>
#include <cstring>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(IsSpaceTests)
	{

		TEST(IsSpaceTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				// Init failed, error!
				CHECK(false);

			for(uint8_t x = 0; x < 9; x++)
			{
				// Insert 1 character
				ringBuff.Write('a');

				CHECK_EQUAL(ringBuff.IsSpace(), true);
			}

			// Should be 9 characters in buffer, lets write one more to fill it up
			ringBuff.Write('a');

			// Now there should be no more space!
			CHECK_EQUAL(ringBuff.IsSpace(), false);

			// Now lets read a single character to free up space again
			ringBuff.Read();

			// Now there should be space!
			CHECK_EQUAL(ringBuff.IsSpace(), true);

		}

	} // SUITE(IsSpaceTests)
} // namespace RingBuffTest
