#ifndef _FILESIZEUNITCHANGE_H
#define _FILESIZEUNITCHANGE_H

static const unsigned long long G = 1024 * 1024 * 1024ull;
static const unsigned long long M = 1024 * 1024;
static const unsigned long long K = 1024;
static char str[20];

char* FileSizeUnitChange(unsigned long long size);

char* FileSizeUnitChange(unsigned long long size)
{
    if (size > G) {
        sprintf(str, "%0.2f GB", size / (G * 1.0)); return str;
    }
    else if (size > M) {
        sprintf(str, "%0.2f MB", size / (1.0 * M)); return str;
    }
    else if (size > K) {
        sprintf(str, "%0.2f KB", size / (1.0 * K)); return str;
    }
    else {
        sprintf(str, "%0.2f B", size * 1.0); return str;
    }
}

#endif
