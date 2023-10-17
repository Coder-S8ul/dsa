#include <stdio.h>
#include <stdlib.h>

struct linked{
    int data;
    struct linked *link;
};

void append(struct linked **q, int num){
    struct linked *temp, *r;
    temp = *q;
    
    if(*q == NULL){
        
        r = malloc(sizeof(struct linked));
        r->data = num;
        r->link = NULL;
        *q = r;
        return;
    }
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    r = malloc(sizeof(struct linked));
    r->data = num;
    r->link = NULL;
    temp->link = r;
    
} 

void display(struct linked *q){
    while(q != NULL){
        printf("%d ",q->data);
        q = q->link;
    }
}

void add_after(struct linked *q, int after, int num){
    struct linked *r;
    for(int i= 0; i<after-1; i++){
        q = q->link;
    }
    r = malloc(sizeof(struct linked));
    r->data = num;
    r->link = q->link;
    q->link = r;
}

void at_beg(struct linked **q, int num){
    struct linked *r;
    r = malloc(sizeof(struct linked));
    r->data = num;
    r->link = *q;
    *q = r;
}

int main(){
    struct linked *ptr;
    ptr = NULL;
    
    append(&ptr, 5);
    append(&ptr, 6);
    append(&ptr, 7);
    
    add_after(ptr, 1, 3);
    add_after(ptr, 4, 8);

    at_beg(&ptr, 4);

    display(ptr);
    
    return 0;
}