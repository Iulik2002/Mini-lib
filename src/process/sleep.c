#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds) {
    const struct timespec time = {seconds, 0};
    struct timespec remTime = {0, 0};
    int result = nanosleep(&time, &remTime);

    if (result == 0) return 0;
    return -1;
}
