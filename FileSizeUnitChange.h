/*
 * need
 * #include <stdio.h>
 *
 * use
test.c
#include <stdio.h>
#include "FileSizeUnitChange.h"

int main()
{
    char *str;
    char *buf;
    buf = FileSizeUnitChange(1024, &str);
    printf("buf = %s\n", str);

    return 0;
}
 */

#ifndef _FILESIZEUNITCHANGE_H
#define _FILESIZEUNITCHANGE_H

static const unsigned long long G = 1024 * 1024 * 1024ull;
static const unsigned long long M = 1024 * 1024;
static const unsigned long long K = 1024;

char* FileSizeUnitChange(unsigned long long size, char **str);

char* FileSizeUnitChange(unsigned long long size, char **str)
{
    if (size >= G) {
        sprintf(*str, "%0.2f GB", size / (G * 1.0)); return *str;
    }
    else if (size >= M) {
        sprintf(*str, "%0.2f MB", size / (1.0 * M)); return *str;
    }
    else if (size >= K) {
        sprintf(*str, "%0.2f KB", size / (1.0 * K)); return *str;
    }
    else {
        sprintf(*str, "%0.2f B", size * 1.0); return *str;
    }
}

#endif
