#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare_scores(const void* score_a, const void* score_b);
int compare_scores_desc(const void* score_a, const void* score_b);
int compare_areas(const void* a,const void* b);
int compare_names(const void* a, const void* b);
int compare_areas_desc(const void* a, const void*b);
int compare_names_desc( const void* a, const void* b);
//void mysort(void *array, size_t length, size_t item_size, int (*compar) (const void *, const void *));
int main(int argc, char const *argv[])
{
    int scores[]={543,323,32,554,11,3,112};
    qsort(scores,7,sizeof(int),compare_scores_desc);
    puts("these scores in order");
    for( int i=0; i<7;i++){
        printf("scores = %i\n",scores[i]);
    }
    char *names[]={"Karen", "Mark", "Brett", "Molly"};
    qsort(names,4, sizeof(char*),compare_names);
    puts("these names in order");
    for(int i=0;i<4;i++){
        printf("names in order= %s\n", names[i]);
    }
    return 0;
}
int compare_scores(const void* score_a, const void* score_b){
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return a-b;
}
int compare_scores_desc(const void* score_a, const void* score_b){
    int a = *(int*)score_a;
    int b = *(int*)score_b;
    return b-a;
}
typedef struct{
    int width;
    int height;
}rectangle;
int compare_areas(const void* a, const void* b){
    rectangle* ra= (rectangle*)a;
    rectangle* rb=(rectangle*)b;
    int area_a=(ra->height*ra->width);
    int area_b=(ra->height*ra->width);
    return area_a-area_b;
}
int compare_names(const void* a, const void* b){
    char** sa = (char**)a;
    char** sb=(char**)b;
    return strcmp(*sa, *sb);
}
int compare_areas_desc(const void* a, const void* b){
    return compare_areas(b,a);
}
int compare_names_desc(const void* a, const void* b){
    -compare_names(a,b);
}
