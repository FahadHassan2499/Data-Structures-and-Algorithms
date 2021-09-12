#include<stdio.h>
#include<malloc.h>

struct queue{
    int size;
    int front;
    int rear;
    int * arr;
};
int isEmpty(struct queue *p){
    if(p->front==p->rear)
        return 1;
    return 0;    
}

int isFull(struct queue *p){
    if(p->rear == p->size-1)
        return 1;
    return 0;    
}

void enqueue(struct queue *p,int val){
    if(isFull(p))
        printf("Queue is full\n");
    else{
        p->rear++;
        p->arr[p->rear]=val;
    }    
}

int dequeue(struct queue *p){
    if(isEmpty(p)){
        printf("Queue is Empty\n");
        return -1;
    }
    else{
        p->front++;
        return p->arr[p->front];
    }
}

int main(){
    struct queue q;
    q.size=100;
    q.front=-1;
    q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,14);
    printf("%d deleted\n",dequeue(&q));
    printf("%d deleted\n",dequeue(&q));
    printf("%d deleted\n",dequeue(&q));
    printf("%d deleted\n",dequeue(&q));


    // if(isFull(&q))
    //     printf("Queue is full\n");
    // else if(isEmpty(&q))
    //     printf("Queue is empty\n");
    return 0;    
}