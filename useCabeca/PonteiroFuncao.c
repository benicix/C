#include<stdio.h>
#include<string.h>
void find(int var, char **tuts);

int main(int argc, char const *argv[])
{
    int numADS=2;
    char *ADS[]={
        "teste: teste3",
        "legume: batata"
    };
    typedef void (*testeFunc)(int, char**);
    testeFunc teste=find;
    find(numADS, ADS);
    return 0;
}
void find(int var, char **tuts){
    int i;
    puts("procurando resultados");
    puts("------------------------------------");
    for(i=0;i<var;i++){
        if(strstr(tuts[i], "legume") && !strstr(tuts[i], "teste")){
            printf("%s\n", tuts[i]);
        }
    }
    puts("------------------------------------");
}