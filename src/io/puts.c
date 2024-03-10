#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(char *s)
{
    int rez = write(1, (void *)s, strlen(s));

    if (rez < 0)
    {
        errno = -rez;
        return -1;
    }

    write(1, "\n", 1);
    return rez;
}
