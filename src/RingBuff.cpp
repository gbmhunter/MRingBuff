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
#include <iostream>		// std::cout

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

	RingBuff::RingBuff(uint32_t capacity)
	{			
		// Create space for buffer, also 0 buffer (although
		// not strictly needed)
		this->buffMemPtr = (char*)calloc(capacity, sizeof(char));
		
		if(this->buffMemPtr == NULL)
		{
			// Memory allocation failed
			this->initComplete = false;
			return;
		}
		
		this->capacity = capacity;
		this->headPos = 0;
		this->tailPos = 0;
		
		// Init completed successfully
		this->initComplete = true;
	}
	
	RingBuff::~RingBuff()
	{
		if(!this->initComplete)
			return;

		// Free memory allocated in constructor
		free(this->buffMemPtr);
	}

	uint32_t RingBuff::Read(uint8_t *buff, uint32_t numBytes)
	{
		if(!this->initComplete)
			return 0;
	
		uint32_t i;
		uint8_t *currPos;
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
				if(tailPos == capacity)
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
 
	uint32_t RingBuff::Write(const uint8_t *buff, uint32_t numBytes)
	{
		if(!this->initComplete)
			return 0;
	
		int i;
		const uint8_t * currPos;
		currPos = buff;
		 
		for(i = 0; i < numBytes; i++)
		{
			// Check to see if there is no space left in the buffer
			if((headPos + 1 == tailPos) ||
				((headPos + 1 == capacity) && (tailPos == 0)))
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
				if(headPos == capacity)
				{  
					headPos = 0;
				}
			}
		}
		
		// All bytes where written
		return numBytes;
	}
	
	uint32_t RingBuff::Write(const char *string)
	{
		if(!this->initComplete)
			return 0;

		bool nullFound = false;
		uint32_t x;
		for(x = 0; x < this->capacity; x++)
		{
			// Look for null-terminating string.
			if(string[x] == '\0')
			{
				nullFound = true;
				break;
			}
		}

		if(nullFound)
		{
			// Null has been found, valid string
			return this->Write((const uint8_t*)string, x);
		}
		else
		{
			// Null has not be found, either string was not null-terminated, or was too large
			// to fit in buffer, nothing written to buffer
			return 0;
		}
	}

	void RingBuff::Clear()
	{
		if(!this->initComplete)
			return;

		// Does not 0 data, as this does not matter,
		// just sets tail = head
		if(this->tailPos != this->headPos)
			this->tailPos = this->headPos;

	}

	uint32_t RingBuff::Capacity()
	{
		if(!this->initComplete)
			return 0;

		// Just return the saved size of the buffer
		return this->capacity;
	}


	uint32_t RingBuff::NumElements()
	{
		if(!this->initComplete)
			return 0;

		// Calculate the number of elements currently in the buffer
		if(this->headPos >= this->tailPos)
		{
			// This is the simple situation, no wrap around
			return this->headPos - this->tailPos;
		}
		else
		{
			// This is when wrap around has occurred
			return (this->capacity - this->tailPos) + this->headPos;
		}
	}

	//===============================================================================================//
	//=============================== PRIVATE METHOD DECLARATIONS ===================================//
	//===============================================================================================//


} // namespace RingBuffNs

// EOF
