#include<stdio.h>
#include "encrypt.h"
int main(int argc, char const *argv[])
{
    char msg[80];
    while(fgets(msg, 80, stdin)){
        encrypt(msg);
        printf("%s", msg);
        puts("\nteste");
    }
    
    
    return 0;
}
