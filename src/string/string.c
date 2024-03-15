// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i;

	for (i = 0; source[i] != '\0'; i++) destination[i] = source[i];
	
	destination[i] = '\0';

	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t i;

	for (i = 0; i < len; i++) destination[i] = source[i];
	
	destination[i+1] = '\0';

	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i, j;
	int x = 0;

	for (i = 0; destination[i] != '\0'; i++) x++;

	for (j = 0; source[j] != '\0'; j++) destination[x + j] = source[j];	

	destination[x + j] = '\0';

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int i;
	size_t j;
	int x = 0;

	for (i = 0; destination[i] != '\0'; i++) x++;

	for (j = 0; source[j] != '\0' && j < len; j++) destination[x + j] = source[j];	

	destination[x + j] = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int ok = 0;

	if (strlen(str1) > strlen(str2)) return 1;
	if (strlen(str1) < strlen(str2)) return -1;
	
	for (size_t i = 0; i < strlen(str1); i++) {
		if (str1[i] == str2[i]) ok = 0;
		if (str1[i] < str2[i]) return -1;
		if (str1[i] > str2[i]) return 1;
	}
	return ok;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	int ok = 0;
	
	for (size_t i = 0; i < len; i++) {
		if (str1[i] == str2[i]) ok = 0;
		if (str1[i] < str2[i]) return -1;
		if (str1[i] > str2[i]) return 1;
	}
	return ok;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

// Inspirat de pe: https://www.harishnote.com/2016/06/c-programming-78-strchr-implementation.html
char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	const char *mystr = str;
	while(*mystr != c && *mystr) mystr++;

	if(*mystr == c) return (char *)mystr;
	else return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *result;
    
    while (*str) {
        if (*str == c) result = str;
        str++;
    }
    if (result) return (char *)result;
	else return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
    while (*haystack) {
        const char* h = haystack;
        const char* n = needle;

        while (*n && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {
            return (char *)haystack;
        }
        haystack++;
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *result;
    char *ok = strstr(haystack, needle);

    while (ok != NULL) {
        result = ok;
        ok = strstr(ok + 1, needle);
    }

    return result;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *d = destination;
	const char *s = source;
	for (size_t i = 0; i < num; i++) d[i] = s[i];
	
	return destination;
}

// copy-paste de la: https://aticleworld.com/memmove-function-implementation-in-c/
void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char isCopyRequired = 0;  // flag bit
    char *pcSource = (char *)source;
    char *pcDstn = (char *)destination;
	// return if pcDstn and pcSource are NULL or if num is 0
    if (pcSource == NULL || pcDstn == NULL || num == 0) {
        return destination;
    }

    // check for overlap
    if (pcDstn < pcSource && pcDstn + num > pcSource) {
        isCopyRequired = 1;
    } else if (pcSource < pcDstn && pcSource + num > pcDstn) {
        isCopyRequired = 1;
    }

    if (isCopyRequired) {
        if (pcDstn < pcSource) {
            // copy from the beginning to the end
            for (pcDstn += num, pcSource += num; num > 0; num--) {
                *--pcDstn = *--pcSource;
            }
        } else {
            // copy from the end to the beginning
            while (num--) {
                *pcDstn++ = *pcSource++;
            }
        }
    } else {
        // non-overlapping memory regions, perform a simple copy
        while (num--) {
            *pcDstn++ = *pcSource++;
        }
    }

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = ptr1;
    const unsigned char *p2 = ptr2;
    int result = 0;

    if (ptr1 == ptr2) return result;

    while (num > 0) {
        if (*p1 != *p2) {
            result = (*p1 >*p2)?1:-1;
            break;
        }
        num--;
        p1++;
        p2++;
    }
    return result;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char* p = source;
    while(num--) *p++ = value;
	return source;
}
