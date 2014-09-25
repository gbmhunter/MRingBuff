=========
MRingBuff
=========

---------------------------------------------------------------------------------
A C++ ring (aka circular, FIFO) buffer object designed for embedded applications.
---------------------------------------------------------------------------------

.. image:: https://api.travis-ci.org/mbedded-ninja/MRingBuff.png?branch=master   
	:target: https://travis-ci.org/mbedded-ninja/MRingBuff

- Author: gbmhunter <gbmhunter@gmail.com> (www.mbedded.ninja)
- First Ever Commit: 2013-07-30
- Last Modified: 2014-09-25
- Version: v2.3.1.1
- Company: mbedded.ninja
- Project: MToolkit module.
- Language: C++
- Compiler: GCC	
- uC Model: Any
- Computer Architecture: Any
- Operating System: Any
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

MRingBuff is a ring (aka circular or FIFO) buffer object designed for use in embedded applications. 

Features:

- Dynamic allocation and resize capabilities (with data preservation)
- Automatic memory management
- Embedded (microcontroller) support
- Unit tests
- Well-commented API.
- Portability

Uses the cyclic head/tail method to implement the ring buffer.

Typically, one task/interrupt will write to the buffer, while another will read from the buffer.

External Dependencies
=====================

Nothing here yet.

Issues
======

See GitHub Issues.

Limitations
===========

Nothing here yet.

Usage
=====

See the unit tests in the 'test/' directory for basic examples.
	
Changelog
=========

========= ========== ===================================================================================================
Version   Date       Comment
========= ========== ===================================================================================================
v2.3.1.1  2014-09-25 Fixed image link to TravisCI in README, closes #40.
v2.3.1.0  2014-09-25 Fixed unit tests so they fit the format 'CHECK_EQUAL(actual, expected)'. Many had actual and expected around the wrong way, closes #38. Fixed name of module in README.
v2.3.0.0  2014-08-12 Added method 'RingBuff::Peek()' that allows you to read data from the buffer without removing it, added associated unit tests, closes #34. Changed i variable in 'RingBuff::Write()' from int to uint32_t, and declared in for loop, closes #35. Made 'RingBuff' constructor/destructor use 'new[]' instead of calloc and delete[] instead of free (i.e. the C++ way), closes #33. Set 'RingBuff::isInitSuccess' to false in the constructors initialiser list, closes #32. Converted usages of 'NULL' to 'nullptr' when used in a pointer context, closes #31.
v2.2.4.0  2014-08-01 Added method 'RingBuff::Write(char myChar)' to easily write on character to the buffer, closes #25.  Added associated unit tests. Added method 'RingBuff::IsSpace()' that allows the user to quickly check if there is space to write more data, closes #26. Added associated unit tests.
v2.2.3.1  2014-07-30 Fixed the bullet points under 'Features' in README, closes #24.
v2.2.3.0  2014-07-29	Removed references to 'std::cout' to fix failing build.
v2.2.2.1  2014-07-29 Added TravisCI build passing/failed image to README, closes #23.
v2.2.2.0  2014-07-29 Added 'RingBuff::IsData()' and added relevant unit tests, closes #18. Added 'uint8_t RingBuff::Read()' and relevant unit tests, closes #17. Changed 'RingBuff::IsInitComplete()' to 'IsInitSuccess()', as complete suggests it could still be running, closes #16.
v2.2.1.0  2014-07-28 Fixed bug where 'RingBuff::Write(char* string)' will write partial messages even if buffer is not large enough, closes #19. Added ability to write only if all data will fit, or as much as possible, closes #20.
v2.2.0.0  2014-07-25 Added '.travis.yml' file for TravisCI integration, closes #4.
v2.1.4.1  2014-07-25 Updated the README with more information.
v2.1.4.0  2014-07-25 Added 'LotsOfDataTests.cpp' unit tests, makes sure buffer doesn't corrupt data under heavy use, closes #6. Fixed bug with 'RingBuff::Read()' and 'RingBuff::Write()' not returning the correct number, closes #15.
v2.1.3.0  2014-07-25 Added ability to resize buffer memory with method 'RingBuff::Resize()', closes #12. Added 'const' qualifier to appropriate methods. Add method definition for 'RingBuff::IsInitComplete()', closes #13. Fix bug in which you can only write to 'capacity - 1' elements, closes #14.
v2.1.2.0  2014-07-25 Added methods 'RingBuff::Capacity()' and 'RingBuff::NumElements()' for the user to read metrics about the buffer, closes #8. Add associated unit tests. Destructor now frees memory allocated in constructor, closes #11.
v2.1.1.0  2014-07-25 Added 'multiple write than read' unit test. Added ablity to write strings to the buffer, closes #9. Fixed bug where RingBuff::size was not being set correctly, closes #10.
v2.1.0.0  2014-07-24 Fixed preprocessor includes. Added 'Ns' to namespace, renamed class from 'Buffer' to 'RingBuff'. Added eclipse project files. Fixed makefile, closes #1. Added UnitTest++ to 'lib/'. Added constructor and basic read/write unit tests, closes #2. Added ability to clear data, closes #7.
v2.0.1.0  2014-07-23 Dropped the 'RingBuff' prefix from code files.
v2.0.0.0  2014-07-21 Renamed project from FiFoFum-Cpp to RingBuff-Cpp, refactored code appropriately.
v1.0.0.0  2013-07-30 Basic code finished, now have functional FIFO buffer. 
v0.1.0.1  2013-07-30 Got rid of exclamation mark which corrupted commit message.
v0.1.0.0  2013-07-30 First version. Bare-bones files, not functional yet.
========= ========== ===================================================================================================