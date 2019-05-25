#include<stdio.h>
#include<stdlib.h>

enum resposta{DUMP , SECOND_CHANCE, MARRIAGE};

typedef struct{
    char *name;
    enum resposta tipo;
}responder;

void dump(responder r){
    printf("nome: %s\n", r.name);
}
void second_chance(responder r){
    printf("name: %s\n",r.name);
}
void marriage(responder r){
    printf("named: %s\n",r.name);
}
void (*teste[])(responder) = {dump,second_chance,marriage};
int main(){
    responder r[]={{"mike", DUMP},{"Luis",SECOND_CHANCE},{"MAtt", SECOND_CHANCE},{"willian", MARRIAGE}};
    for(int i=0;i<4;i++){
        /*switch(r[i].tipo){
            case DUMP:
                dump(r[i]);
                break;
            case SECOND_CHANCE:
                second_chance(r[i]);
                break;
            default:
                marriage(r[i]);
        }*/
        (teste[r[i].tipo](r[i]));
    }
}
