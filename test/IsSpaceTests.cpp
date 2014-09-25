//!
//! @file 			IsSpaceTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-01
//! @last-modified 	2014-09-25
//! @brief 			Tests that the method 'bool RingBuff::IsSpace()' works correctly.
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
	MTEST_GROUP(IsSpaceTests)
	{

		MTEST(IsSpaceTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

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

	} // GROUP(IsSpaceTests)
} // namespace RingBuffTestsNs
