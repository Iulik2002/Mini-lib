#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdlib.h>

int puts(const char *s) {
    char *buffer = malloc((strlen(s) + 2) * sizeof(*buffer));
    strcpy(buffer, s);
    strcat(buffer, "\n");

    long result = syscall(1, 1, buffer, strlen(buffer));
    free(buffer);

    if (result >= 0) return result;

    return -1;
}