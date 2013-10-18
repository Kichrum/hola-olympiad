#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void dump(char* text, const char* arr, int n) {
    puts(text);
    int i = 0;
    while (n > 0) {
        printf("%2c:%2d,", *(arr + i), *(arr + i));
        n--;
        i++;
    }
    puts("");
}

void throw_error(const char *str, const char *a, const char *b) {
    printf("ERROR on %s : \"%s\" != \"%s\"\n", str, a, b);
    exit(1);
}

void compare(const char *str, const char *a, const char *b) {
    printf("COMPARE on %s : \"%s\" == \"%s\"\n", str, a, b);
    if(strcmp(a, b)) {
        throw_error(str, a, b);
    }
}

#define ENOMEM 12
#define EINVAL 22

int str_cat(char **dst, const char *src)
{
    if (!dst)
#if defined(EINVAL)
        return EINVAL;
#else
        return EXIT_FAILURE;
#endif
    size_t dst_len = 0, src_len = 0, len = 0;
    int overlap = 0;
    char *new = NULL;
    const char *dst_tmp = *dst, *src_tmp = src;
    if (dst_tmp && *dst_tmp) while (*++dst_tmp);
    if (src_tmp && *src_tmp) while (*++src_tmp);
    if (!(new = (
        overlap = (dst_tmp > src_tmp ? dst_tmp : src_tmp) - 
            (*dst < src ? *dst : src) <= (
                len = (dst_len = dst_tmp - *dst) + (src_len = src_tmp - src)
            )
        ) ? calloc(len + 1, 1) : realloc(*dst, len + 1)) ||
        (overlap && !memcpy(new, *dst, dst_len)) ||
        !memcpy(new + dst_len, src, src_len))
#if defined(ENOMEM)
        return ENOMEM;
#else
        return EXIT_FAILURE;
#endif
    if (overlap) free(*dst);
    *dst = new;
    return EXIT_SUCCESS;
}

int str_cpy(char **dst, const char *src)
{
    if (!dst)
#if defined(EINVAL)
        return EINVAL;
#else
        return EXIT_FAILURE;
#endif
    size_t src_len = 0;
    char *new = NULL;
    const char *tmp = src;
    if (src && *src) while (*++tmp);
    if (!(new = calloc((src_len = tmp - src) + 1, 1)) || !memcpy(new, src, src_len))
#if defined(ENOMEM)
        return ENOMEM;
#else
        return EXIT_FAILURE;
#endif
    free(*dst);
    *dst = new;
    return EXIT_SUCCESS;
}

void str_printf(char **a, const char *b, const char *c){}
void str_free(char **a){}

// http://thecodeil.com/5min_challenge_ru.html
/* Copyright (C) Hola 2012, 2013
 *
 * Welcome to TheCodeIL.com Challenge!
 */

void testing() {
    char *s = NULL;
    str_cpy(NULL, NULL);
    str_cat(NULL, NULL);
    str_cpy(&s, "Hola Hola");
    compare("str_cpy(&s, \"Hola Hola\");", s, "Hola Hola");
    str_cpy(&s, s+5);
    compare("str_cpy(&s, s+5);", s, "Hola");
    str_cat(&s, " World");
    compare("str_cat(&s, \" World\");", s, "Hola World");
    str_cat(&s, s+5);
    compare("str_cat(&s, s+5);", s, "Hola WorldWorld");
    s = NULL; str_cpy(&s, s);
    compare("s = NULL; str_cpy(&s, s);", s, "");
    str_cat(&s, "a");
    compare("str_cat(&s, \"a\");", s, "a");
    s = NULL; str_cat(&s, s);
    compare("s = NULL; str_cat(&s, s);", s, "");
    str_cpy(&s, "a");
    compare("str_cpy(&s, \"a\");", s, "a");
    s = NULL; str_cat(&s, "");
    compare("s = NULL; str_cat(&s, \"\");", s, "");
    str_cat(&s, "Hola Hola");
    compare("str_cat(&s, \"Hola Hola\");", s, "Hola Hola");
    s = NULL; str_cpy(&s, "");
    compare("s = NULL; str_cpy(&s, \"\");", s, "");
    str_cpy(&s, "Hola Hola");
    compare("str_cpy(&s, \"Hola Hola\");", s, "Hola Hola");
}

int main(int argc, char *argv[])
{
    testing();
    char *s = NULL;
    str_cpy(&s, "Hola Hola");
    str_cpy(&s, s+5);
    str_cat(&s, " World");
    str_printf(&s, "%s!", s);
    puts(s); /* result: "Hola World!" */
    str_free(&s);
    return 0;
}
