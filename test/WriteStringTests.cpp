//!
//! @file 			WriteStringTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/07/28
//! @last-modified 	2014/07/28
//! @brief 			Tests that Write(char* string) works correctly.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>
#include <cstring>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(WriteStringTests)
	{

		TEST(WriteStringTest)
		{
			// Make buffer with 10 bytes of memory
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Insert characters
			char *myMsg = "hello";

			// Should write 5 characters
			CHECK_EQUAL(5, ringBuff.Write(myMsg));

			// Now read these out
			char readBuff[20] = {0};
			// Should only read 5 elements, even though 12 are specified
			CHECK_EQUAL(5, ringBuff.Read((uint8_t*)readBuff, 12));

			CHECK_EQUAL("hello", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

		}

		TEST(WriteToMuchTest)
		{
			// Make buffer with 10 bytes of memory
			RingBuffNs::RingBuff ringBuff(10);

			if(!ringBuff.IsInitSuccess())
				CHECK(false);

			// Create C string
			char *myMsg = "hello!!!";

			// Should write 8 characters
			CHECK_EQUAL(8, ringBuff.Write(myMsg));

			// Should write 0 characters,
			// since string will not fit in buffer
			CHECK_EQUAL(0, ringBuff.Write(myMsg));

			// Now read out buffer
			char readBuff[20] = {0};
			// Should only read 8 elements, even though 12 are specified
			CHECK_EQUAL(8, ringBuff.Read((uint8_t*)readBuff, 12));

			CHECK_EQUAL("hello!!!", readBuff);
			CHECK_EQUAL(0, ringBuff.NumElements());

		}

	} // SUITE(WriteStringTests)
} // namespace RingBuffTest
