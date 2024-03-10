// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */

	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if ((long)ptr == -1)
		return NULL;

	mem_list_add(ptr, size);

	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */

	void *ptr = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	do
	{
		nmemb--;
		(*((char *)(ptr) + nmemb)) = 0;
	} while (nmemb > 0);

	mem_list_add(ptr, nmemb * size);

	return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *aux = mem_list_find(ptr);
	int len = aux->len;
	mem_list_del(ptr);
	munmap(ptr, len);
	ptr = NULL;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */

	struct mem_list *aux = mem_list_find(ptr);
	int len = aux->len;
	aux->len = size;

	mremap(ptr, len, size, MAP_PRIVATE | MAP_ANONYMOUS);

	return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */

	struct mem_list *aux = mem_list_find(ptr);
	int len = aux->len;
	aux->len = size;

	mremap(ptr, len, nmemb * size, MAP_PRIVATE | MAP_ANONYMOUS);

	return ptr;
}
