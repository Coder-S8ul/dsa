#include <stdio.h>
#include <stdlib.h>

int cnt;

struct node{
    int data;
    struct node *next;
};

void add(struct node **q, int num){
    struct node *temp, *r;
    temp = *q;
    
    if(*q == NULL){
        
        r = malloc(sizeof(struct node));
        r->data = num;
        r->next = NULL;
        *q = r;
        return;
    }
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    r = malloc(sizeof(struct node));
    r->data = num;
    r->next = NULL;
    temp->next = r;
    
} 

void add_acc(struct node **q, int num){
    struct node *r, *temp = *q;
    
    r = malloc(sizeof(struct node()));
    r->data = num;

    if(*q == NULL||num<(*q)->data){
        r->next = *q;
        *q =r;
        return;
    }
    else{
        while(temp != NULL){
            if(temp->next == NULL||temp->next->data>=num){
                r->next = temp->next;
                temp->next = r;
                return;
            }
            temp = temp->next;
        }
    }
}

void display(struct node *q){
    printf("\n");
    while(q != NULL){
        printf("%d ", q->data);
        q = q->next;
    }
}

void reverse(struct node **q){
    struct node *temp = *q, *r = NULL, *s;
    while(temp != NULL){
        s=r;
        r=temp;
        temp = temp->next;
        r->next =s;
    }
    *q = r;
}

void count(struct node *q){
    cnt= 0;
    while(q != NULL){
        q = q->next;
        cnt++;
    }
}

void merge(struct node *p,struct node *q,struct node **s){
    struct node *z;
    if(p == NULL|| q == NULL){
        return;
    }
    while(p != NULL && q != NULL){
        if(*s == NULL){
            *s = malloc(sizeof(struct node));
            z = *s;
        }
        else{
            z->next = malloc(sizeof(struct node));
            z = z->next;
        }
        if(p->data < q->data){
            z->data = p->data;
            p = p->next;
        }
        else{
            if(q->data < p->data){
                z->data = q->data;
                q = q->next;
            }
            else{
                z->data = p->data;
                p = p->next;
                q = q->next;
            }
        }
    }
    if(p != NULL){
        z->next = p;
    }
    else if(q != NULL){
        z->next = q;
    }
}

void selection_sort(struct node *q){
    int i, j, temp, min;
    struct node *a, *b;
    
    a = q;

    for(i = 0; i<cnt-1; i++){
        b = a->next;
        for(j= i+1; j<cnt; j++){
            if(b->data < a->data){
                temp = b->data;
                b->data = a->data;
                a->data = temp;
            }
            b = b->next;
        }
        a = a->next;
    }
}

void bubble_sort(struct node *q){
    int i, j, temp;
    struct node *a, *b;
    
    for(i = 0; i<cnt-1; i++){
        a = q;
        b = a->next;
        for(j= 1; j<cnt-i; j++){
            if(a->data > b->data){
                temp = a->data;
                a->data = b->data;
                b->data = temp;
            }
                a = a->next;
                b = b->next;
        }
    }
}

int main(){

    struct node *start, *new, *result;
    start = NULL;
    new = NULL;
    result = NULL;

    printf("node list");

    add(&start, 6);
    add(&start, 4);
    add(&start, 9);
    add(&start, 7);
    add(&start, 1);

    count(start);

    display(start);

    return 0;
}