//!
//! @file 				RingBuff.hpp
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created 			2013-07-30
//! @last-modified		2014-07-25
//! @brief 				Implements the ring buffer.
//! @details
//!						See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef RING_BUFF_RING_BUFF_H
#define RING_BUFF_RING_BUFF_H

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
			//=================================== PUBLIC METHOD DECLARATIONS ================================//
			//===============================================================================================//
			
			//! @brief		Initialises the buffer (incl. malloc()ing memory for buffer), ready for use.
			//! @details	If initialisation fails, IsInitComplete() will return false. This method is used,
			//!				because exceptions are not supported (designed to be compatible with embedded
			//!				microcontrollers)
			//! @param		capacity	The size (in bytes) of the buffer.
			RingBuff(uint32_t capacity);

			//! @brief		Destructor. Frees memory allocated in constructor.
			~RingBuff();

			//! @brief		Use this to check if the initialisation in the constructor was successful.
			//! @returns	True if initialisation was successful, otherwise false.
			bool IsInitComplete() const;
			
			//! @brief		Writes a number of bytes to the ring buffer.
			//! @details	Will return early if there is no more space left in the buffer. Does
			//!				not write over contents. Returns 0 if IsInitComplete()
			//!				is false.
			uint32_t Write(const uint8_t* buff, uint32_t numBytes);

			//! @brief		Writes a null-terminated string to the buffer. Does not write the null character
			//!				to the buffer. Will not write anything (a returns 0) if null-character cannot be found or string
			//!				is too large for buffer.
			//! @details	This looks for the null character and then calls
			//!				uint32_t Write(const uint8_t* buff, uint32_t numBytes).
			//! @param		string		The null-terminated string to write to the buffer.
			uint32_t Write(const char *string);

			//! @brief		Reads up to a number of bytes from the ring buffer.
			//! @details	Will read numBytes of data, unless there is not enough data to read, in which case
			//!				returns early.
			//! @returns	Number of bytes read (which could be from 0 to numBytes). Returns 0 if IsInitComplete()
			//!				is false.
			uint32_t Read(uint8_t* buff, uint32_t numBytes);

			
			//! @brief		Clears all data in the ring buffer.
			//! @details	Does not actually 0 data as this is not required, just sets tailPos = headPos.
			void Clear();

			//! @brief		Returns the size (capacity) of the buffer.
			//! 			This is NOT how many bytes are currently in the buffer, see NumElements().
			uint32_t Capacity();

			//! @brief		Returns the number of elements currently in the buffer. Size() returns the capacity of
			//!				the buffer.
			uint32_t NumElements();

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
			uint32_t capacity;
			
			//! @brief		The head position, measured in bytes from the start of the buffer (bufPtr).
			//! @details	This is the next element to write to.
			uint32_t headPos;
			
			//! @brief		The tail position, measured in bytes from the start of the buffer (bufPtr).
			//! @details	This is the next element to read from.
			uint32_t tailPos;
		
	};

	//===============================================================================================//
	//================================= PUBLIC TEMPLATE METHOD DEFINITIONS ==========================//
	//===============================================================================================//
	
	// none
	
} // namespace RingBuffNs

#endif // #ifndef RING_BUFF_RING_BUFF_H

// EOF
