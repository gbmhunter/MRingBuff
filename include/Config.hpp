//!
//! @file 				Config.hpp
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created 			2013-07-30
//! @last-modified	2014-07-24
//! @brief 				Configuration file for RingBuff.
//! @details
//!						See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef RING_BUFF_CONFIG_H
#define RING_BUFF_CONFIG_H

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

// none

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace RingBuff
{

	//===============================================================================================//
	//==================================== PUBLIC DEFINES ===========================================//
	//===============================================================================================//

	//=============== DEBUG SWITCHES ============//

	#define RingBuff_Config_DEBUG_PRINT_GENERAL		1u				//!< Print general debug msgs
	#define RingBuff_Config_DEBUG_PRINT_VERBOSE		1u				//!< Print verbose debug msgs
	#define RingBuff_Config_DEBUG_PRINT_ERROR		1u				//!< Print error debug msgs

	#define RingBuff_Config_DEBUG_PRINT_ANY	(RingBuff_Config_DEBUG_PRINT_GENERAL | RingBuff_Config_DEBUG_PRINT_VERBOSE | RingBuff_Config_DEBUG_PRINT_ERROR)
	
	//! @brief		The size of the debug buffer.
	//! @details	All writes use snprintf so should be safe if too small.
	#define RingBuff_Config_DEBUG_BUFF_SIZE			(200u)
	
		
} // namespace RingBuff

#endif // #ifndef RING_BUFF_CONFIG_H

// EOF
