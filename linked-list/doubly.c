#include <stdio.h>
#include <stdlib.h>

struct doubly{
    struct doubly *prev;
    int data;
    struct doubly *next;
}*node;

void add(int num){
    struct doubly *r, *temp = node;
    
    r = malloc(sizeof(struct doubly));
    r->data = num;

    if(node == NULL){
        node = r;
        node->prev = NULL;
        node->next = NULL;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        r->prev = temp;
        r->next = NULL;
        temp->next = r;
    }
}

void display(){
    struct doubly *temp = node;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main(){

    add(5);
    add(3);
    add(8);

    display();
}