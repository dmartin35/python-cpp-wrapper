#include "demo.h"


char * echo(char * msg){
    return msg;
}


struct tm * now(void)
{
    time_t t = time(NULL);
    return localtime ( &t );
}


long addition(long a, long b)
{
   long result;
   result = a + b;
   return result;
}