#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

void push(struct stack **p, int n){
    struct stack *temp;

    temp = malloc(sizeof(struct stack));
    temp->data = n;
    temp->next = *p;
    *p = temp;
}

void pop(struct stack **p){
    if(*p == NULL){
        printf("\nStack is empty\n");
    }
    printf("Element removed: %d\n", (*p)->data);
    struct stack *temp = *p;
    *p = (*p)->next;
    free(temp);
}

int main(){
    struct stack *p;
    p = NULL;

    push(&p, 7);
    push(&p, 3);

    pop(&p);
    pop(&p);
    pop(&p);
}