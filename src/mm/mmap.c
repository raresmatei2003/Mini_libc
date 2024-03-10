// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <internal/types.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	void *rez = (void *)syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

	if ((long)rez < 0)
	{
		errno = -((long)rez);
		return MAP_FAILED;
	}

	return rez;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	void *rez = (void *)syscall(__NR_mremap, old_address, old_size, new_size, flags);

	if ((long)rez < 0)
	{
		errno = -((long)rez);
		return MAP_FAILED;
	}

	return rez;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	long rez = syscall(__NR_munmap, addr, length);

	if (rez == 0)
		return 0;
	else
	{
		errno = -rez;
		return -1;
	}
}
