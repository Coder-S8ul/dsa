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

void display(struct node *q){
    printf("\n");
    while(q != NULL){
        printf("%d ", q->data);
        q = q->next;
    }
}

void count(struct node *q){
    cnt= 0;
    while(q != NULL){
        q = q->next;
        cnt++;
    }
}

void bubble_sort_whole(struct node **start){
    struct node *p, *q, *r, *s;
    s = NULL;

    while(s != (*start)->next){
        p = r = *start;
        q = p->next;
        
        while(p != s){
            if(p->data > q->data){
                if(p == *start){
                    p->next = q->next;
                    q->next = p;
                    
                    *start = q;
                    r=q;
                }
                else{
                    p->next = q->next;
                    q->next = p;

                    r->next = q;
                    r = q;
                }
            }
            else{
                r = p;
                p = p->next;
            }
            q = p->next;
            if(q == s){
                s = p;
            }
        }
    }
}

void selection_sort_whole(struct node **dummy){
    struct node *p, *q, *r, *s, *temp;
    p = r = *dummy;

    while(p->next != NULL){
        q = s = p->next;

        while(q != NULL){
            if(p->data > q->data){
                if(p->next == q){
                    if(p == *dummy){
                        p->next = q->next;
                        q->next = p;

                        temp = p;
                        p = q;
                        q = temp;
                    
                        *dummy = p;
                        r = p;
                        s = q;
                        q = q->next;
                    }
                    else{
                        p->next = q->next;
                        q->next = p;
                        r->next = q;

                        temp = q;
                        q = p;
                        p = temp;
                        s = q;
                        q = q->next;
                    }
                }
                else{
                    if(p == *dummy){
                        temp = q->next;
                        q->next = p->next;
                        p->next = temp;
                        s->next = p;

                        temp = q;
                        q = p;
                        p = temp;
                        
                        r = p;
                        s = q;
                        q = q->next;
                        *dummy = p;
                    }
                    else{
                        temp = q->next;
                        q->next = p->next;
                        p->next = temp;
                        r->next = q;
                        s->next = p;

                        temp = q;
                        q = p;
                        p = temp;

                        s = q;
                        q = q->next;
                    }
                }
            }
            else{
                s = q;
                q = q->next;
            }
        }
        r = p;
        p = p->next;
    }
}    

int main(){

    struct node *start;
    start = NULL;

    printf("node list");

    add(&start, 6);
    add(&start, 4);
    add(&start, 9);
    add(&start, 7);
    add(&start, 1);

    count(start);

    display(start);

    selection_sort_whole(&start);

    printf("\nafter sorting");

    display(start);

    return 0;
}