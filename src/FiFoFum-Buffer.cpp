//!
//! @file 				RingBuff-Buffer.cpp
//! @author 			Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created 			2013-07-30
//! @last-modified	2014-07-21
//! @brief 				Implements the ring buffer.
//! @details
//!						See README.rst in root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// User includes
#include "../include/RingBuff-Config.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace RingBuff
{
	
	//===============================================================================================//
	//================================ PUBLIC METHOD DECLARATIONS ===================================//
	//===============================================================================================//

	Buffer(char* bufPtr, uint32_t size)
	{
		this->bufPtr = bufPtr;
		this->size = size;
		this->headPos = 0;
		this->tailPos = 0;
	}
	
	uint32_t Read(char* buff, uint32_t numBytes)
	{
		uint32_t i;
		char* currPos;
		currPos = buff;
		
		for(i = 0; i < numBytes; i++)
		{
			// Make sure tail != head
			// (check if any data is available)
			if(tailPos != headPos)
			{ 		
				// Read one byte from the FIFO buffer
				*currPos++ = fifoBuff[tailPos];
				
				 // Increment the tail
				tailPos++; 
				
				// Check for wrap-around
				if(tailPos == size)
				{  
					// Reset tail
					tailPos = 0;
				}
			}
			else
			{
				// Return number of bytes read
				return i;  
			}
		}
		
		// All bytes were read
		return numBytes;
	}
 
	uint32_t Write(const char * buff, uint32_t numBytes)
	{
		int i;
		const char * currPos;
		currPos = buff;
		 
		for(i = 0; i < nbytes; i++)
		{
			// Check to see if there is no space left in the buffer
			if((headPos + 1 == tailPos) ||
				((headPos + 1 == size) && (tailPos == 0))
			{
				// We have run out of space!
				return i; 
			}
			else
			{
				// Write one byte to buffer
				fifoBuff[headPos] = *currPos++;
				
				// Increment the head
				headPos++;  
				
				// Check for wrap-around
				if(headPos == size)
				{  
					headPos = 0;
				}
			}
		}
		
		// All bytes where written
		return numBytes;
	}
	
	//===============================================================================================//
	//=============================== PRIVATE METHOD DECLARATIONS ===================================//
	//===============================================================================================//


} // namespace RingBuff

// EOF
