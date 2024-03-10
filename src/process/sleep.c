#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <time.h>

unsigned int sleep(unsigned int t)
{
    struct timespec treq = {(int)t, 0}, trem;

    int rez = nanosleep(&treq, &trem);

    if (rez == -1)
        return (unsigned int)trem.tv_sec;

    return 0;
}
