Hola - Coding Challange
=======================

**GUIDELINES:**
- Look at main(): it calls various functions.
- You are asked to implement two functions: str_cpy() and str_cat(). No need to implement str_printf() and str_free() (Jungo employees: you are required to implement them).
- Reading main() carefully will allow to understand str_cpy() and str_cat() signature and usage.
- The code you write needs to be "library quality"; as good as you would expect a good libc to implement such functions.
- At the top of the page, you see 4 includes - indicating the functions that can be used to implement str_cpy() and str_cat().
- You have 15 minutes to implement the whole solution.
- Copy/paste your solution and send it to email.

FYI: It is possible to implement str_cpy() and str_cat() efficiently in no more than 7 lines of code per function, and in less than 5 minutes.

```
/* Copyright (C) Hola 2012, 2013
 *
 * Welcome to TheCodeIL.com Challenge!
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

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
```

