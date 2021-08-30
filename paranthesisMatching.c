#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
} 

void push(struct stack* s,char value){
    if(!isFull(s)){
        s->top++;
        s->arr[s->top]=value;
    }
    else{
        printf("Stack Overflow\n");
    }
}

char pop(struct stack* s){
    if(isEmpty(s)){
    
        return -1;
    }
    else{
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int parenthesisMatching(char * exp,int l){
    struct stack* s;
    s->size = l;
    s->arr = (char *)malloc(s->size * sizeof(char));
    s->top = -1;
    int i=0;
    while(exp[i]!='\0'){
        if(exp[i]=='('){
            push(s,'(');
        }
        else if(exp[i]==')'){
            if(isEmpty(s)){
                return 0;
            }
            pop(s);
        }
        i++;
    }
    if(isEmpty(s))
        return 1;
    else
        return 0;    

}

int main(){
     char * exp = "((((8)(*--$$9))))";
     int l = strlen(exp);

     if(parenthesisMatching(exp,l)){
         printf("parenthesis is matching");
     }
     else
        printf("parenthesis is not matching");
     return 0;   

}