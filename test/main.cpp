//!
//! @file 			main.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-07-24
//! @last-modified 	2014-09-25
//! @brief 			Contains main entry point for unit tests.
//! @details
//!					See README.rst in root dir for more info.

//===== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

using namespace MbeddedNinja;

int main()
{

	return TestRegister::RunAllTests();
	
}
