#include<stdio.h>
#include<malloc.h>

struct circularQueue{
    int front;
    int rear;
    int size;
    int * arr;
};

int dequeue(struct circularQueue *c){
    if(c->front == c->rear){
        printf("Queue is Empty\n");
        return -1;
    }
    c->front = (c->front +1) % c->size;
    return c->arr[c->front];
}

void enqueue(struct circularQueue *c, int val){
    if((c->rear +1) % c->size == c->front)
        printf("Queue is Full\n");
    else{
        c->rear = (c->rear +1) % c->size;
        c->arr[c->rear] = val;
        printf("Enqueued Element: %d\n",c->arr[c->rear]);
    }    
}

int main(){
    struct circularQueue c;
    c.size = 20;
    c.rear = 0;
    c.front = 0;
    c.arr = (int *)malloc(c.size * sizeof(int));
    enqueue(&c,12);
    enqueue(&c,14);
    enqueue(&c,15);
    enqueue(&c,16);
    
    printf("Dequeued Element: %d\n",dequeue(&c));
    printf("Dequeued Element: %d\n",dequeue(&c));
    printf("Dequeued Element: %d\n",dequeue(&c));

    
    return 0;
}