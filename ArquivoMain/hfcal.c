#include<stdio.h>
#include"/home/benicio/c/ArquivosHeader/hfcal.h"

void display_calories(float weight, float distance, float coeff){
    printf("weight: %3.2f\n",weight);
    printf("Distance: %3.2f\n", distance);    
    printf("Calories burned: %4.2f\n", coeff*weight*distance);
}