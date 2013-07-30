//!
//! @file 		FiFoFum-Port.cpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @date 		2012/07/30
//! @brief 		Contains port-specific skeleton functions.
//! @details
//!				See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System includes
#include <stdio.h>		// snprintf()

// User includes
#include "./include/FiFoFum-Port.hpp"

#if(CY_PSOC5)
	#include "./Comms/include/UartDebug.h"
	#include "./Comms/include/UartComms.h"
#endif

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace FiFoFum
{

	//===============================================================================================//
	//===================================== PUBLIC FUNCTIONS ========================================//
	//===============================================================================================//

	void Port::DebugPrint(const char* msg) 
	{
		#ifdef __linux__
			printf("%s", msg);
		#elif(CY_PSOC5)
			UartDebugNs::UartDebug::PutString(msg);
		#else
			#warning No debug output defined
		#endif
	}
	
	//===============================================================================================//
	//==================================== PRIVATE FUNCTIONS ========================================//
	//===============================================================================================//

	// none

} // namespace FiFoFum