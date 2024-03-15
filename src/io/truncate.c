// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
	int result = syscall(76, path, length);

	if (result >= 0) return result;
	errno = -result;
	return -1;
}
