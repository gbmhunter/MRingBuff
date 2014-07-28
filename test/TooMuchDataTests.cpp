//!
//! @file 			TooMuchDataTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/07/25
//! @last-modified 	2014/07/25
//! @brief 			Tests that the buffer behaves correctly when 'too much' data is written to it.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>
#include <cstring>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(TooMuchDataTests)
	{

		TEST(TooMuchDataTest)
		{
			// Make buffer with 10 bytes of memory
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert characters
			char someChars[] = "0123456789012";

			// Should only write 10 bytes, even though 12 are specified
			CHECK_EQUAL(10, ringBuff.Write((uint8_t*)someChars, 12, RingBuffNs::RingBuff::ReadWriteLogic::ANY));

			// Now read these out
			char readBuff[20] = {0};
			// Should only read 10 elements, even though 12 are specified
			CHECK_EQUAL(10, ringBuff.Read((uint8_t*)readBuff, 12));

			CHECK_EQUAL("0123456789", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

			// Now insert more
			ringBuff.Write((uint8_t*)someChars, 10, RingBuffNs::RingBuff::ReadWriteLogic::ANY);

			memset(readBuff, '\0', sizeof(readBuff));
			ringBuff.Read((uint8_t*)readBuff, 10);

			// Check data is read correctly
			CHECK_EQUAL("0123456789", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

		}

	} // SUITE(LotsOfDataTests)
} // namespace RingBuffTest
