#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char * str_cpy(char **dst, const char *src) {
    if (!src) return *dst = NULL;
    unsigned int len = 0;
    while (*(src + len++));
    *dst = (char*) realloc(*dst, len);
    char *tmp = *dst;
    while (*tmp++ = *src++);
    return *dst;
}

char * str_cat(char **dst, const char *src) {
    if (!src) return *dst;
    unsigned int dynamicLenDst = 0, lenSrc = 0;
    if (*dst) while (*(*dst + dynamicLenDst++));
    while (*(src + lenSrc++));
    *dst = (char*) realloc(*dst, (!dynamicLenDst ? 0 : --dynamicLenDst) + lenSrc);
    while (*(*dst + dynamicLenDst++) = *(src++));
    return *dst;
}

void str_printf(char **a, const char *b, const char *c){}
void str_free(char **a){}

// http://thecodeil.com/5min_challenge_ru.html
/* Copyright (C) Hola 2012, 2013
 *
 * Welcome to TheCodeIL.com Challenge!
 */

int main(int argc, char *argv[])
{
    char *s = NULL;
    str_cpy(&s, "Hola Hola");
    str_cpy(&s, s+5);
    str_cat(&s, " World");
    str_printf(&s, "%s!", s);
    puts(s); /* result: "Hola World!" */
    str_free(&s);
    return 0;
}
