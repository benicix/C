#include"checksum.h"
int checksum( char *mensagem){
    int c=0;
    while(*mensagem){
        c+=c^(int)(*mensagem);
        mensagem++;
    }
    return c;
}