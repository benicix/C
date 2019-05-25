#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char const *argv[])
{
     char line[80];
     char localiza[]="teste.text";
    FILE *in = fopen(localiza, "r");
    FILE *arquivo2 = fopen("teste2.txt", "w");
    FILE *arquivo3 = fopen("teste3.txt", "w");
    FILE *arquivo4 = fopen("teste4.txt", "w");
    while(fscanf(in, "%79[^\n]\n", line)==1){
        if(strstr(line, "teste")){
            fprintf(arquivo2,"%s\n", line);
        }else if(strstr(line,"batata")){
            fprintf(arquivo3,"%s\n",line);
        }else{
            fprintf(arquivo4,"%s\n", line);
        }
    }
    fclose(arquivo2);
    fclose(arquivo3);
    fclose(arquivo4);
    return 0;
}
