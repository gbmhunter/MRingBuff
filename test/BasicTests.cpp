//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014/07/24
//! @last-modified 	2014/07/24
//! @brief 			Contains basic tests.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/RingBuffApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace RingBuffTest
{
	SUITE(BasicTests)
	{


		TEST(ConstructorWorksTest)
		{

			RingBuffNs::RingBuff ringBuff(100);
			
			// If we got here, test passed!
			CHECK(true);
		}

		TEST(BasicReadWriteTest)
		{

			RingBuffNs::RingBuff ringBuff(100);

			char someChars[] = "testing";
			ringBuff.Write(someChars);

			char readBuff[8];
			ringBuff.Read((uint8_t*)readBuff, 8);

			// Check read data is equal to written data
			CHECK_EQUAL("testing", readBuff);
		}

		TEST(BasicReadWhenEmptyTest)
		{
			RingBuffNs::RingBuff ringBuff(100);

			uint8_t readBuff[10] = {0};
			// Read while empty
			ringBuff.Read(readBuff, 8);

			// Check buffer is still empty
			CHECK_EQUAL(0, readBuff[0]);
		}
		
		TEST(ClearTest)
		{
			RingBuffNs::RingBuff ringBuff(100);

			char someChars[] = "testing";
			ringBuff.Write(someChars);

			// Clear the buffer
			ringBuff.Clear();

			char readBuff[8];
			ringBuff.Read((uint8_t*)readBuff, 8);

			// Check read data is empty
			CHECK_EQUAL("", readBuff);
		}

		TEST(MultipleWritesThenReadTest)
		{
			RingBuffNs::RingBuff ringBuff(100);

			ringBuff.Write((uint8_t*)"12", 2);
			ringBuff.Write((uint8_t*)"34", 2);
			ringBuff.Write((uint8_t*)"56", 2);
			ringBuff.Write((uint8_t*)"78", 2);

			char readBuff[9];
			ringBuff.Read((uint8_t*)readBuff, 8);
			readBuff[9] = '\0';

			// Check read data is empty
			CHECK_EQUAL("12345678", readBuff);
		}

	} // SUITE(BasicTests)
} // namespace RingBuffTest
