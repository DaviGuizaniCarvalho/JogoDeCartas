#ifndef GETCH_H
#define GETCH_H

    #if (!defined(__MINGW32__) && !defined (_MSC_VER) && !defined(_WIN32) && !defined(WIN32))
        int getch();
    #endif

#endif
