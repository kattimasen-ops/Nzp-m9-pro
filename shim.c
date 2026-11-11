#define _GNU_SOURCE
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

size_t strlcpy(char *dst, const char *src, size_t size) {
    size_t srclen = strlen(src);
    if (size > 0) {
        size_t copylen = (srclen >= size) ? size - 1 : srclen;
        memcpy(dst, src, copylen);
        dst[copylen] = '\0';
    }
    return srclen;
}

size_t strlcat(char *dst, const char *src, size_t size) {
    size_t dstlen = strlen(dst);
    size_t srclen = strlen(src);
    if (dstlen >= size) {
        return size + srclen;
    }
    size_t copylen = size - dstlen - 1;
    if (srclen < copylen) {
        copylen = srclen;
    }
    memcpy(dst + dstlen, src, copylen);
    dst[dstlen + copylen] = '\0';
    return dstlen + srclen;
}

int __system_property_get(const char *name, char *value) {
    if (!name || !value) return 0;
    if (strcmp(name, "ro.build.version.sdk") == 0) {
        strcpy(value, "19");
        return 2;
    }
    if (strcmp(name, "ro.product.model") == 0) {
        strcpy(value, "M9 Pro");
        return 6;
    }
    value[0] = '\0';
    return 0;
}
