============
RingBuff-Cpp
============

--------------------------------------------------------------------------
A C++ ring (circular) buffer framework designed for embedded applications.
--------------------------------------------------------------------------

- Author: gbmhunter <gbmhunter@gmail.com> (http://www.cladlab.com)
- First Ever Commit: 2013-07-30
- Last Modified: 2014-07-25
- Version: v2.1.1.0
- Company: CladLabs
- Project: Free Code Libraries
- Language: C++
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

Description
===========

Designed to be both powerful, efficient and portable in an embedded (microcontroller) environment.

Uses the cyclic head/tail method to implement the ring buffer. The head is where data is currently being written to, while the tail is where data is currently being read from.

Typically, one task/interrupt will write to the buffer, while another will read from the buffer.

External Dependencies
=====================

Coming soon...

Issues
======

See GitHub Issues.

Limitations
===========

Coming soon...

Usage
=====

Coming soon...
	
Changelog
=========

======== ========== ===================================================================================================
Version  Date       Comment
======== ========== ===================================================================================================
v2.1.1.0 2014/07/25 Added 'multiple write than read' unit test. Added ablity to write strings to the buffer, closes #9. Fixed bug where RingBuff::size was not being set correctly, closes #10.
v2.1.0.0 2014/07/24 Fixed preprocessor includes. Added 'Ns' to namespace, renamed class from 'Buffer' to 'RingBuff'. Added eclipse project files. Fixed makefile, closes #1. Added UnitTest++ to 'lib/'. Added constructor and basic read/write unit tests, closes #2. Added ability to clear data, closes #7.
v2.0.1.0 2014/07/23 Dropped the 'RingBuff' prefix from code files.
v2.0.0.0 2014/07/21 Renamed project from FiFoFum-Cpp to RingBuff-Cpp, refactored code appropriately.
v1.0.0.0 2013/07/30 Basic code finished, now have functional FIFO buffer. 
v0.1.0.1 2013/07/30 Got rid of exclamation mark which corrupted commit message.
v0.1.0.0 2013/07/30 First version. Bare-bones files, not functional yet.
======== ========== ===================================================================================================