#include <stdio.h>
#include <stdlib.h>

struct circular{
    int data;
    struct circular *next;
}*front, *rear;

void add(int num){
    struct circular *q;

    q = malloc(sizeof(struct circular));
    q->data = num;
    
    if(front == NULL){
        front = q;
    }
    else{
        rear->next = q;
    }

    rear = q;
    rear->next = front;
}

void display(){
    struct circular *q;
    q = front->next;
    printf("%d ", front->data);
    while(q != front){
        printf("%d ", q->data);
        q = q->next;
    }
}

void delete(){
    struct circular *q;
    if(front == NULL){
        printf("The circular linked list is null");
    }
    else{
        if(front->next == front){
            free(front);
            front = NULL;
            rear = NULL;
        }
        else{
            q = front;
            front = front->next;
            rear->next = front;
            free(q);
        }    
    }
}

void main(){
    add(1);
    add(4);
    add(9);
    add(5);

    display();

    printf("\n");

    delete();

    display();
}