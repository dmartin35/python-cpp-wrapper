#include <stdio.h>
#include "demo.h"

int main(void)
{
    char str[] = "Hello World!";
    char * output;
    output = echo(str);
    printf("echo>> %s\n", output);

    struct tm *tm = now();
    printf("now>> %d-%d-%d %d:%d:%d\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
        tm->tm_hour, tm->tm_min, tm->tm_sec);
    printf ("Current local time and date>> %s", asctime(tm));

    long sum = addition(1, 2);
    printf("addition>>%d\n", sum);

    return 0;
}