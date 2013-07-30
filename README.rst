=======
FiFoFum
=======

---------------------------------------------------------------
A C++ FIFO buffer framework designed for embedded applications.
---------------------------------------------------------------

- Author: gbmhunter <gbmhunter@gmail.com> (http://www.cladlab.com)
- First Ever Commit: 2013/07/30
- Last Modified: 2013/07/30
- Version: v1.0.0.0
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

Uses the cyclic head/tail method to implement the FIFO buffer. The head is where data is currently being written to, while the tail is where data is currently being read from.

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
v1.0.0.0 2013/07/30 Basic code finished, now have functional FIFO buffer. 
v0.1.0.1 2013/07/30 Got rid of exclamation mark which corrupted commit message.
v0.1.0.0 2013/07/30 First version. Bare-bones files, not functional yet.
======== ========== ===================================================================================================