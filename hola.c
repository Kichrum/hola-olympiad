#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void dump(char* text, char* arr, int n) {
    puts(text);
    int i = 0;
    while (n > 0) {
        printf("%2c:%2d,", *(arr + i), *(arr + i));
        n--;
        i++;
    }
    puts("");
}

/**
 * Concatenates strings.
 *
 * @param char* dst destination
 * @param const char* src source
 * @return char* ptr to concatenated string
 */
char * str_cat(char **dst, const char *src) {
    unsigned int lenDst = 0, lenSrc = 0;
    char *new;
    if (!src) return *dst;
    if (*dst) while (*(*dst + lenDst++));
    while (*(src + lenSrc++));
    new = (char*) calloc((!lenDst ? 0 : --lenDst) + lenSrc, 1);
    if (!new) return NULL; // TODO: exit(1) or throw some exception - depends on the project.
    while (lenSrc--) *(new + lenDst + lenSrc) = *(src + lenSrc);
    while (lenDst--) *(new + lenDst) = *(*dst + lenDst);
    free(*dst); // - if we sure we won't use something like str_cat(&s, a) where *a = s...
    return *dst = new;
}

/**
 * Copies the string.
 *
 * @note Don't forget free destination memory before call this function.
 * @param char* dst destination
 * @param const char* src source
 * @return char* ptr to copied string
 */
char * str_cpy(char **dst, const char *src) {
    *dst = NULL;
    return *dst = str_cat(dst, src);
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
