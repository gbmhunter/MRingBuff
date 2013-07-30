//!
//! @file 		FiFoFum-Config.hpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @date 		2013/07/30
//! @brief 		Configuration file for FiFoFum.
//! @details
//!				See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef FIFOFUM_CONFIG_H
#define FIFOFUM_CONFIG_H

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

// none

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace FiFoFum
{

	//===============================================================================================//
	//==================================== PUBLIC DEFINES ===========================================//
	//===============================================================================================//

	//=============== DEBUG SWITCHES ============//

	#define FiFoFum_Config_DEBUG_PRINT_GENERAL		1u				//!< Print general debug msgs
	#define FiFoFum_Config_DEBUG_PRINT_VERBOSE		1u				//!< Print verbose debug msgs
	#define FiFoFum_Config_DEBUG_PRINT_ERROR		1u				//!< Print error debug msgs

	#define FiFoFum_Config_DEBUG_PRINT_ANY	(FiFoFum_Config_DEBUG_PRINT_GENERAL | FiFoFum_Config_DEBUG_PRINT_VERBOSE | FiFoFum_Config_DEBUG_PRINT_ERROR)
	
	//! @brief		The size of the debug buffer.
	//! @details	All writes use snprintf so should be safe if too small.
	#define FiFoFum_Config_DEBUG_BUFF_SIZE			(200u)
	
		
} // namespace FiFoFum

#endif	// #ifndef FIFOFUM_CONFIG_H

// EOF
