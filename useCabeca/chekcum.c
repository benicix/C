#include "chekcum.h"
int checksum( char* mensagem){
    int c=0;
    while(*mensagem){
        c+=c^(int)(*mensagem);
    }
    return c;
}