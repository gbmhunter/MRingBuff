//!
//! @file 				RingBuff.hpp
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created 			2013-07-30
//! @last-modified	2014-07-24
//! @brief 				Implements the ring buffer.
//! @details
//!						See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef RING_BUFF_H
#define RING_BUFF_H

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

// System libraries
#include <stdint.h>

// User source
#include "Config.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace RingBuffNs
{
	//===============================================================================================//
	//============================================= CLASS ===========================================//
	//===============================================================================================//
	class RingBuff
	{	
		
		public:
		
			//===============================================================================================//
			//==================================== CONSTRUCTORS/DESTRUCTOR ==================================//
			//===============================================================================================//
			
			//! @brief		Initialises the buffer (incl. malloc()ing memory for buffer), ready for use.
			//! @details	If initialisation fails, IsInitComplete() will return false. This method is used,
			//!				because exceptions are not supported (designed to be compatible with embedded
			//!				microcontrollers)
			//! @param		sizeOfBuff		The size (in bytes) of the buffer.
			RingBuff(uint32_t sizeOfBuff);
			
			//===============================================================================================//
			//=================================== PUBLIC METHOD DECLARATIONS ================================//
			//===============================================================================================//
			
			//! @brief		Use this to check if the initialisation in the constructor was successful.
			//! @returns	True if initialisation was successful, otherwise false.
			bool IsInitComplete();
			
			//! @brief		Reads up to a number of bytes from the ring buffer.
			//! @details	Will read numBytes of data, unless there is not enough data to read, in which case
			//!				returns early.
			//! @returns	Number of bytes read (which could be from 0 to numBytes). Returns 0 if IsInitComplete()
			//!				is false.
			uint32_t Read(char* buff, uint32_t numBytes);
			
			//! @brief		Writes a number of bytes to the ring buffer.
			//! @details	Will return early if there is no more space left in the buffer. Does
			//!				not write over contents. Returns 0 if IsInitComplete()
			//!				is false.
			uint32_t Write(const char* buff, uint32_t numBytes);
			
			//! @brief		Clears all data in the ring buffer.
			//! @details	Does not actually 0 data as this is not required, just sets tailPos = headPos.
			void Clear();

			//===============================================================================================//
			//======================================= PUBLIC VARIABLES ======================================//
			//===============================================================================================//
			
						
		private:
		
			//! @brief		Set to true by the constructor once initialisation is complete.
			//! @details	Used by most methods to prevent errors if initialisation failed.
			bool initComplete;
		
			//! @brief		Pointer to buffer. Memory allocated in constructor.
			char* buffMemPtr;
			
			//! @brief		The size of the buffer (in bytes). Set by Buffer().
			uint32_t size;
			
			//! @brief		The head position, measured in bytes from the start of the buffer (bufPtr).
			uint32_t headPos;
			
			//! @brief		The tail position, measured in bytes from the start of the buffer (bufPtr).
			uint32_t tailPos;
		
	};

	//===============================================================================================//
	//================================= PUBLIC TEMPLATE METHOD DEFINITIONS ==========================//
	//===============================================================================================//
	
	// none
	
} // namespace RingBuffNs

#endif // #ifndef RING_BUFF_H

// EOF
