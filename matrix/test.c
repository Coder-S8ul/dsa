#include <stdio.h>
#include <stdlib.h>
#define MAX1 3
#define MAX2 3

struct matrice{
    int *sp;
    int row;
}s1, s2;

void array(struct matrice *p){
    int n;

    p->sp = NULL;

    p->sp = (int*)malloc(MAX1 * MAX2 *sizeof(int));

    for(int i = 0; i< MAX1*MAX2; i++){
        printf("Enter element %d:\n", i+1);
        scanf("%d",&n);
        (p->sp[i]) = n;
    }
}

void display(struct matrice p){
    for(int i = 0; i< MAX1*MAX2; i++){
        if(i%MAX2 == 0)
        printf("\n");
        printf("%d\t",*(p.sp + i));
    }
    printf("\n");
}

int count_non(struct matrice p){
    int cnt = 0;
    for(int i = 0; i< MAX1 * MAX2; i++){
        if(*(p.sp + i) != 0)
        cnt ++;
    }
    return cnt;
}

void create_tuple(struct matrice p){
    int n, a = 3, r = -1, c = 0;
    n = count_non(p);
    s2.sp = NULL;
    s2.sp = (int*)malloc((n + 1) * 3 *sizeof(int));

    *(s2.sp + 0) = MAX1;
    *(s2.sp + 1) = MAX2;
    *(s2.sp + 2) = n;

    for(int i = 0; i< MAX1*MAX2; i++){
        if(i%MAX2 == 0){
            r++;
            c = 0;
        }
        if(*(p.sp + i) != 0){
            *(s2.sp + a) = r;
            a++;
            *(s2.sp + a) = c;
            a++;
            *(s2.sp + a) = *(p.sp + i);
            a++;
        }
        c++;
    }
}

void display_tuple(struct matrice p){
    for(int i = 0; i< (count_non(s1) + 1) * 3; i++){
        if(i%3 == 0)
        printf("\n");
        printf("%d ", *(p.sp + i));
    }
}

int main(){
    int n;

    array(&s1);
    display(s1);
    
    create_tuple(s1);

    display_tuple(s2);

    return 0;
}