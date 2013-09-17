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
int str_cat(char **dst, const char *src) {
    unsigned int dst_len = 0, src_len = 0;
    char *new = NULL;
    const char *dst_tmp = *dst, *src_tmp = src;
    if (!src) return 0;
    while (*dst_tmp++);
    dst_len = dst_tmp - *dst;
    while (*src_tmp++);
    src_len = src_tmp - src;
    if (!(new = calloc(dst_len + src_len - 1, 1))) return 1;
    if (!memcpy(new, *dst, dst_len) || !memcpy(new + dst_len - 1, src, src_len)) return 1;
    free(*dst);
    *dst = new;
    return 0;
}

/**
 * Copies the string.
 *
 * @param char* dst destination
 * @param const char* src source
 * @return char* ptr to copied string
 */
int str_cpy(char **dst, const char *src) {
    unsigned int src_len = 0;
    char *new = NULL;
    const char *tmp = src;
    if (!src) return 0;
    while (*tmp++);
    src_len = tmp - src;
    if (!(new = calloc(src_len, 1))) return 1;
    if (!memcpy(new, src, src_len)) return 1; //bcopy(src, new, src_len);
    free(*dst);
    *dst = new;
    return 0;
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
