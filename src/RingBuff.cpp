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

	RingBuff::RingBuff(uint32_t capacity):
		capacity(capacity),
		headPos(0),
		tailPos(0),
		numElements(0)
	{			
		// Create space for buffer, also 0 buffer (although
		// not strictly needed)
		this->buffMemPtr = (uint8_t*)calloc(capacity, sizeof(char));
		
		if(this->buffMemPtr == NULL)
		{
			// Memory allocation failed
			this->initComplete = false;
			return;
		}
		
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

	bool RingBuff::IsInitComplete() const
	{
		return this->initComplete;
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
			if(this->numElements >= this->capacity)
				// We have run out of space!
				return 0;

			// Write one byte to buffer
			buffMemPtr[this->headPos] = *currPos++;

			// Increment the head
			this->headPos++;

			// Increment the number of elements
			this->numElements++;

			// Check for wrap-around
			if(this->headPos == this->capacity)
			{
				headPos = 0;
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

	uint32_t RingBuff::Read(uint8_t *buff, uint32_t numBytes)
	{
		if(!this->initComplete)
			return 0;

		uint32_t i;
		uint8_t *currPos;
		currPos = buff;

		for(i = 0; i < numBytes; i++)
		{
			//
			// Check if any data is available
			if(this->numElements == 0)
				return 0;

			// Read one byte from the FIFO buffer
			*currPos++ = this->buffMemPtr[this->tailPos];

			// Decrement the number of elements
			this->numElements--;

			 // Increment the tail
			this->tailPos++;

			// Check for wrap-around
			if(this->tailPos == this->capacity)
			{
				// Reset tail
				this->tailPos = 0;
			}
		}

		// All bytes were read
		return numBytes;
	}

	void RingBuff::Clear()
	{
		if(!this->initComplete)
			return;

		// Does not 0 data, as this does not matter,
		// Just resets tail, head and number of elements
		this->tailPos = 0;
		this->headPos = 0;
		this->numElements = 0;
	}

	uint32_t RingBuff::Capacity() const
	{
		if(!this->initComplete)
			return 0;

		// Just return the saved size of the buffer
		return this->capacity;
	}


	uint32_t RingBuff::NumElements() const
	{
		if(!this->initComplete)
			return 0;

		return this->numElements;
	}

	bool RingBuff::Resize(uint32_t newCapacity)
	{
		// First, shuffle all data backwards so that tailPos is at 0
		// this makes resizing easier
		this->ShiftElementsSoTailPosIsZero();

		// Now realloc() the memory. realloc() is guaranteed to preserve as much data as possible
		// Since elements have been shifted to start of buffer this should work as intended
		this->buffMemPtr = (uint8_t*)realloc(this->buffMemPtr, newCapacity);

		// Make sure realloc() was successful
		if(this->buffMemPtr != NULL)
		{
			// Update headPos if old headpos is larger than new capacity, as headPos will be
			// currently out of range
			if(this->numElements > newCapacity)
			{
				std::cout << "Head pos > capacity." << std::endl;
				// Update headpos to end of memory (memory is full with data)
				this->headPos = newCapacity - 1;
				this->numElements = newCapacity;
			}
			std::cout << "Updating capacity." << std::endl;
			// Update capacity
			this->capacity = newCapacity;

			return true;
		}
		else
			// realloc failed! Don't update capacity and return false
			return false;

	}

	//===============================================================================================//
	//=============================== PRIVATE METHOD DECLARATIONS ===================================//
	//===============================================================================================//

	void RingBuff::ShiftElementsSoTailPosIsZero()
	{
		uint32_t currNumElements = this->NumElements();

		// Create a temp buffer memory space for copying
		// existing data into
		uint8_t tempBuffMem[currNumElements];

		// Read all data into temp memory
		this->Read(tempBuffMem, currNumElements);

		// Reset the head and tail positions back to 0, numElements does not change.
		this->headPos = 0;
		this->tailPos = 0;

		// Now write all data back, tailPos should stay at 0
		this->Write(tempBuffMem, currNumElements);

		// Done!
	}


} // namespace RingBuffNs

// EOF
