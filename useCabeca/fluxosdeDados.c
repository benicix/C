#include<stdio.h>
int main(int argc, char const *argv[])
{
    char teste[80];
    fgets(teste,sizeof(teste),stdin);
    FILE *out_file = fopen("input.txt","w");
    FILE *in_file = fopen("input.txt", "r");
    //fprintf(out_file,"teste %s", input.txt);
    return 0;
}
