# Berkeley DB 1.85 - Mac68k #

Classic Mac OS (System 6 and 7) port of the Berkeley DB 1.85 library.
This port is designed for use with THINK C 5.0.4 on 68k Macintosh
computers.  You will need a copy of THINK C in order to compile the
library.

## Compilation ##

bdb185-mac68k requires the following non-default THINK C compilation
options:

-   **Language Settings**
    -   #define \_\_STDC\_\_
    -   enums are always ints
-   **Compiler Settings**
    -   4-byte ints

Configure your Prefix as follows:

    #include <MacHeaders>

    #define __DBINTERFACE_PRIVATE (1)
    #define MMAP_NOT_AVAILABLE (1)
    #define NO_POSIX_SIGNALS (1)
