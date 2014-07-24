//!
//! @file 				RingBuff.cpp
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
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System libraries
#include <stdint.h>		// uint32_t, e.t.c
#include <stdlib.h>		// calloc();

// User includes
#include "../include/Config.hpp"
#include "../include/RingBuff.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace RingBuffNs
{
	
	//===============================================================================================//
	//================================ PUBLIC METHOD DECLARATIONS ===================================//
	//===============================================================================================//

	RingBuff::RingBuff(uint32_t sizeOfBuff)
	{			
		// Create space for buffer
		this->buffMemPtr = (char*)calloc(sizeOfBuff, sizeof(char));
		
		if(this->buffMemPtr == NULL)
		{
			// Memory allocation failed
			this->initComplete = false;
			return;
		}
		
		this->size = size;
		this->headPos = 0;
		this->tailPos = 0;
		
		// Init completed successfully
		this->initComplete = true;
	}
	
	uint32_t RingBuff::Read(char* buff, uint32_t numBytes)
	{
		if(!this->initComplete)
			return 0;
	
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
				*currPos++ = buffMemPtr[tailPos];
				
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
 
	uint32_t RingBuff::Write(const char * buff, uint32_t numBytes)
	{
		if(!this->initComplete)
			return 0;
	
		int i;
		const char * currPos;
		currPos = buff;
		 
		for(i = 0; i < numBytes; i++)
		{
			// Check to see if there is no space left in the buffer
			if((headPos + 1 == tailPos) ||
				((headPos + 1 == size) && (tailPos == 0)))
			{
				// We have run out of space!
				return i; 
			}
			else
			{
				// Write one byte to buffer
				buffMemPtr[headPos] = *currPos++;
				
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
	
	void RingBuff::Clear()
	{
		// Does not 0 data, as this does not matter,
		// just sets tail = head
		if(this->tailPos != this->headPos)
			this->tailPos = this->headPos;

	}

	//===============================================================================================//
	//=============================== PRIVATE METHOD DECLARATIONS ===================================//
	//===============================================================================================//


} // namespace RingBuffNs

// EOF
