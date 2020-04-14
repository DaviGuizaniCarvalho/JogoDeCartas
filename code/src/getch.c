#if (!defined(__MINGW32__) && !defined (_MSC_VER) && !defined(_WIN32) && !defined(WIN32))

#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/getch.h"

int getch() // somente para linux
{
    struct termios velho, novo;
    int x;
    tcgetattr( STDIN_FILENO, &velho );
    novo = velho;
    novo.c_lflag &= ~( ICANON | ECHO );
    tcsetattr(STDIN_FILENO, TCSANOW, &novo);
    x = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &velho);
    return x;
}

#endif
