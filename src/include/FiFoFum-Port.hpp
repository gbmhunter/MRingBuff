//!
//! @file 		FiFoFum-Port.hpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @date 		2013/07/30
//! @brief 		Contains port-specific skeleton functions.
//! @details
//!				See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef FIFOFUM_PORT_H
#define FIFOFUM_PORT_H

#if(CY_PSOC5)
	extern "C" {
		// PSoC
		#include <device.h>
	}
#endif // #if(CY_PSOC5)

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace FiFoFum
{

	//===============================================================================================//
	//==================================== PUBLIC DEFINES ===========================================//
	//===============================================================================================//

	#define STR_EXPAND(tok) #tok
	#define STR(tok) STR_EXPAND(tok)
	
	#if(defined __linux__)
		#define FiFoFumPort_PF_UINT32_T		u
		#define FiFoFumPort_PF_INT32_T		i
		#define FiFoFumPort_PF_CHAR_T		c
	#elif(CY_PSOC5)
		#define FiFoFumPort_PF_UINT32_T		lu
		#define FiFoFumPort_PF_INT32_T		li
		#define FiFoFumPort_PF_CHAR_T		li
	#else
		#warning No platform defined. Using defaults.
		#define FiFoFumPort_PF_UINT32_T		u
		#define FiFoFumPort_PF_INT32_T		i
		#define FiFoFumPort_PF_CHAR_T		c
	#endif
		
	//===============================================================================================//
	//=================================== PUBLIC TYPEDEFS ===========================================//
	//===============================================================================================//

	// none

	//===============================================================================================//
	//================================== PUBLIC VARIABLES/STRUCTURES ================================//
	//===============================================================================================//

	// none

	//===============================================================================================//
	//=================================== PUBLIC FUNCTION PROTOTYPES ================================//
	//===============================================================================================//

	//! @brief		Contains all the port-specific functions
	class Port
	{

		public:
		
			//===============================================================================================//
			//==================================== CONSTRUCTORS/DESTRUCTOR ==================================//
			//===============================================================================================//
			
			// none
		
			//! @brief		Prints debug messages. Port specific.
			//! @public
			static void DebugPrint(const char* msg);

	};

} // namespace FiFoFum

#endif	// #ifndef FIFOFUM_PORT_H

// EOF
