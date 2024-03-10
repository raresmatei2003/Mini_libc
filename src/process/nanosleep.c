// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *t1, struct timespec *t2)
{
	long rez = syscall(__NR_nanosleep, t1, t2);

	if(rez < 0)
	{
		errno = -rez;
		return -1;
	}

	return rez;
}
