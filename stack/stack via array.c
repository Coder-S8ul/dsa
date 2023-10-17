#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct stack{
    int *data;
    int top;
};

void size(struct stack *p){
    p->data = NULL;
    p->data = (int*)malloc(MAX*sizeof(int));
    p->top = -1;
}

void push(struct stack *p, int n){
    if(p->top == MAX-1){
        printf("\nStack is full\n");
    }
    p->top++;
    p->data[p->top] = n;
}

void pop(struct stack *p){
    if(p->top == -1){
        printf("\nStack is empty\n");
    }
    printf("Item popped: %d", p->data[p->top]);
    p->top--;
}

int main(){
    struct stack s1;

    size(&s1);

    push(&s1, 9);
    push(&s1, 3);
    
    pop(&s1);
    pop(&s1);
    pop(&s1);

    return 0;
}