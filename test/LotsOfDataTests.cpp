//!
//! @file 			LotsOfDataTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/07/25
//! @last-modified 	2014/07/25
//! @brief 			Tests that the buffer does not do weird things when lots of data is read/written to it.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>
#include <cstring>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(LotsOfDataTests)
	{

		TEST(LotsOfDataTest)
		{
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert 5 characters
			char someChars[] = "12345";
			ringBuff.Write(someChars);

			// Now read these out
			char readBuff[20];
			ringBuff.Read((uint8_t*)readBuff, 5);

			CHECK_EQUAL("12345", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

			// Now insert 7 more, this should wrap around
			char someChars2[] = "1234567";
			ringBuff.Write(someChars2);

			memset(readBuff, '\0', sizeof(readBuff));
			ringBuff.Read((uint8_t*)readBuff, 7);

			// Check num elements is calculated correctly
			CHECK_EQUAL("1234567", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

			ringBuff.Write(someChars2);

			memset(readBuff, '\0', sizeof(readBuff));
			ringBuff.Read((uint8_t*)readBuff, 7);

			// Check num elements is calculated correctly
			CHECK_EQUAL("1234567", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());


		}

	} // SUITE(LotsOfDataTests)
} // namespace RingBuffTest
