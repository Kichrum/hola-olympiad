/* Copyright (C) Hola 2012, 2013
 *
 * Welcome to TheCodeIL.com Challenge!
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

void str_cpy(char **dst, const char *src) {
    *dst = (char*) malloc(sizeof (char) * (strlen(src) + 1));
    char *a = *dst;
    while (*a++ = *src++);
}

void str_cat(char **dst, const char *src) {
    *dst = (char*) realloc(*dst, (*dst ? strlen(*dst):0) + strlen(src)+1);
    printf("len=%d\n", (int)sizeof(dst));
    char *a = *dst;
    while (*++a != '\0') {
printf ("c1: %c\n", (char) *a);
}
*a--;
    while (*a++ = *src++)
    {
printf ("c2: a=%c c=%c\n", *(a-1), *(src-1));
}
}

void str_printf(char **a, const char *b, const char *c){}
void str_free(char **a){}

//
//int main(int argc, char *argv[])
//{
//    char *s = NULL;
//    str_cpy(&s, "Hola Hola");
//    str_cpy(&s, s+5);
//    str_cat(&s, " World");
//    char a[] = "Hola World";
//    if(strcmp(s, "Hola World") == 0 && strlen(s) == strlen("Hola World")) {
//        puts("Correct!");
//    }
//    puts(a);
//    printf("S=");
//    puts(s);
//    s = strcat(s,a);
//    return 0;
//}

// http://thecodeil.com/5min_challenge_ru.html
int main(int argc, char *argv[])
{
    char *s = NULL;
//    str_cpy(&s, "Hola Hola");
//    str_cpy(&s, s+5);
    str_cat(&s, " World");
//    str_printf(&s, "%s!", s);
    puts(s); /* result: "Hola World!" */
    str_free(&s);
    return 0;
}
