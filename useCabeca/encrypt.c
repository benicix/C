#include"encrypt.h"
void encrypt(char *mensagem){
    char c;
    while(*mensagem){
        *mensagem=*mensagem ^ 31;
        mensagem++;
    }
}