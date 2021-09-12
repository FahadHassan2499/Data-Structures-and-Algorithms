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



void push(struct stack* s,char value){
    
        s->top++;
        s->arr[s->top]=value;

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

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;    
}

int priority(char ch){
    if(ch == '+' || ch == '-')
        return 2;
    if(ch == '*' || ch == '/')
        return 3;
    return 0;        
}

char stackTop(struct stack* sp){
    return sp->arr[sp->top];
}


char * infixToPostfix(char * infix){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->size = strlen(infix);
    s->top = -1;
    s->arr = (char*)malloc(s->size * sizeof(char));
    int i=0;
    int j=0;
    char * postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));
    
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            if(infix[i]=='('){
                push(s,infix[i]);
                i++;
            }
            else if(infix[i]==')'){
                while(!isEmpty(s)&&s->arr[s->top]!='('){
                    postfix[j]=pop(s);
                    j++;
                    
                }
                pop(s);
                i++;
            }    
            else{    
            postfix[j]=infix[i];
            i++;
            j++;
            }
        }
        else{
            if(priority(infix[i])>priority(s->arr[s->top])){
                push(s,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(s);
                j++;
            }
        }
    }
    while(!isEmpty(s)){
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
     char * infix ="(m-n)*(p+q)";
     printf("Infix Expression: %s\n",infix);
     printf("Postfix Expression: %s\n",infixToPostfix(infix));

     return 0;   

}