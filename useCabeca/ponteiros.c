#include<stdio.h>
int main(){
    char food[5];
    printf("coloque a comida favorita\n");
    fgets(food,sizeof(food),stdin);
    printf("\n%s", food);
}