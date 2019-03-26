#include<stdio.h>
#include"encrypt.h"
#include"checksum.h"
int main(int argc, char const *argv[])
{
    char s[]="verificando funcionalidade do codigo";
    encrypt(s);
    printf("%s\n",s);
    printf("checksum is %i\n", checksum(s));
    encrypt(s);
    printf("descriptografado %s\n",s);
    printf("checksum is %i\n", checksum(s));
    return 0;
}
