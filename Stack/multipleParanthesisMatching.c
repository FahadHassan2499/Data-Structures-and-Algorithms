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

int match(char a,char b){
    if(a == '('&&b==')' || a=='{'&&b=='}' || a=='['&&b==']')
        return 1;
    return 0;    
}

int parenthesisMatching(char * exp,int l){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->size = l;
    s->arr = (char *)malloc(s->size * sizeof(char));
    s->top = -1;
    char popped_ch;
    int i=0;
    while(exp[i]!='\0'){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(s,exp[i]);
        }
        else if(exp[i]==')'|| exp[i]=='}'|| exp[i]==']'){
            if(isEmpty(s)){
                return 0;
            }
            popped_ch=pop(s);
            if(!match(popped_ch,exp[i])){
                return 0;
            }
        }
        i++;
    }
    if(isEmpty(s))
        return 1;
    else
        return 0;    

}

int main(){
     char * exp = "8*2*[1+2])";
     int l = strlen(exp);

     if(parenthesisMatching(exp,l)){
         printf("parenthesis is balanced");
     }
     else
        printf("parenthesis is not balanced");
     return 0;   

}