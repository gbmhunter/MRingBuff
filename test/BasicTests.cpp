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
			ringBuff.Write(someChars, 8);

			char readBuff[8];
			ringBuff.Read(readBuff, 8);

			// Check read data is equal to written data
			CHECK_EQUAL("testing", readBuff);
		}

		TEST(BasicReadWhenEmptyTest)
		{
			RingBuffNs::RingBuff ringBuff(100);

			char readBuff[10] = {0};
			// Read while empty
			ringBuff.Read(readBuff, 8);

			// Check buffer is still empty
			CHECK_EQUAL("", readBuff);
		}
		
		TEST(ClearTest)
		{
			RingBuffNs::RingBuff ringBuff(100);

			char someChars[] = "testing";
			ringBuff.Write(someChars, 8);

			ringBuff.Clear();

			char readBuff[8];
			ringBuff.Read(readBuff, 8);

			// Check read data is equal to written data
			CHECK_EQUAL("", readBuff);
		}

	} // SUITE(BasicTests)
} // namespace RingBuffTest
