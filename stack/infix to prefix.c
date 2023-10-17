#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#define Max 30

struct prefix{
    char stack[Max];
    char target[Max];
    char *t;
    char *s;
    int top;
}i;

void setStruct(char *in){
    strrev(in);
    i.t = i.target;
    i.s = in;
    i.top = -1;
}

void push(){
    i.top++;
    i.stack[i.top] = *i.s;
}

void pop(){
    *i.t = i.stack[i.top];
    i.t++;
    i.top--;
}

int priority(char n){
    if(n == '+' || n == '-')
    return 0;
    if(n == '*' || n == '/')
    return 1;
    if(n == ')')
    return -1;
    if(i.top == -1)
    return -1;
}

void convertIntoPre(){
    while(*i.s){
        if((*i.s == ' ')||(*i.s == '\t')){
            i.s++;
        }
        if(isalpha(*i.s) || isdigit(*i.s)){
            *i.t = *i.s;
            i.t++;
            i.s++;
        }
        if(*i.s == ')'){
            push();
            i.s++;
        }
        if(*i.s == '+' || *i.s == '-' || *i.s == '*' || *i.s == '/'){
            if(i.top != -1){
                if(priority(i.stack[i.top]) < priority(*i.s)){
                    push();
                }
                else{
                    while(priority(i.stack[i.top]) >= priority(*i.s))
                    pop();
                    push();
                }
            }
            else
            push();
            i.s++;
        }
        if(*i.s == '('){
            while(i.top > -1 && i.stack[i.top] != ')'){
                pop();
            }
            i.top--;
            i.s++;
        }
    }
    while(i.top != -1)
    pop();

    i.t ='\0';
}

int main(){
    char input[Max];
    printf("Enter the infix: ");
    scanf("%s", input);

    setStruct(input);

    convertIntoPre();

    strrev(i.target);

    printf("Output: %s", i.target);

    return 0;
}