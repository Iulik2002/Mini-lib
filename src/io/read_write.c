// SPDX-License-Identifier: BSD-3-Clause

#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>

ssize_t write(int fd, const void *buf, size_t len)
{
	int result = syscall(1, fd, buf, len);

	if (result >= 0) return result;
	errno = -result;
	return -1;
}

ssize_t read(int fd, void *buf, size_t len)
{
	int result =  syscall(0, fd, buf, len);

	if (result >= 0) return result;
	errno = -result;
	return -1;
}
