#include<stdio.h>
#include<stdarg.h>
void print_ints(int args, ...){
    va_list ap;
    va_start(ap, args);
    for(int i=0;i<args;i++){
        printf("argumentos: %i\n", va_arg(ap,int));
    }
    va_end (ap);
}
int main(int argc, char const *argv[])
{
    print_ints(8, 32,33,34,35,36,37,38);
    return 0;
}
