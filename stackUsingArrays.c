#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
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

void push(struct stack* s,int value){
    if(!isFull(s)){
        s->top++;
        s->arr[s->top]=value;
        printf("Successful\n");
    }
    else{
        printf("Stack Overflow\n");
    }
}

int pop(struct stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int peek(struct stack* s,int i){
    if(s->top-i+1<0){
        printf("Not valid\n");
        return -1;
    }
    else{
        return s->arr[s->top-i+1];
    }
}

int stackTop(struct stack* s){
    return s->arr[s->top];
}

int stackBottom(struct stack* s){
    return s->arr[0];
}

int main(){
    struct stack *s;
    s->size = 8;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s,7);
    push(s,8);
    push(s,9);
    push(s,10);
    push(s,11);
    push(s,13);
    push(s,18);
    push(s,19);


    int i=5;
    printf("Element at %d position is %d\n",i,peek(s,i));

    printf("Topmost element is %d\n",stackTop(s));
    printf("Bottom most element is %d\n",stackBottom(s));


    // printf("Element removed %d\n",pop(s));
    // printf("Element removed %d\n",pop(s));
    // printf("Element removed %d\n",pop(s));


    
    return 0;
}