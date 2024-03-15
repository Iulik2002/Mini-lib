#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int result = syscall(35, req, rem);

    if (result >= 0) return 0;
    errno = -result;
    return -1;
}