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
	void *result = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (result != MAP_FAILED) mem_list_add(result, size);
    return result;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *result = malloc(nmemb * size);
	return result;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	mem_list_del(ptr);
    munmap(ptr, mem_list_find(ptr)->len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	// size_t old_size = *(((size_t *) ptr) - 1);
	void *result = malloc(size);
	if (size > *(((size_t *) ptr) - 1)) memcpy(result, ptr, *(((size_t *) ptr) - 1));
	else memcpy(result, ptr, size);
	free(ptr);
	return result;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *result = realloc(ptr, nmemb * size);
	return result;
}
