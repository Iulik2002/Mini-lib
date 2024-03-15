// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	if (length < 0) {
        errno = EINVAL;
        return -1;
    }

	int result = syscall(77, fd, length);

	if (result >= 0) {
		return result;
	}

	errno = -result;
	return -1;
}
