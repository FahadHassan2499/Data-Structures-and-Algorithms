#include<stdio.h>
#include<stdlib.h>
struct node *f=NULL;
struct node *r=NULL;
struct node{
    int data;
    struct node *next;
};

void traversal(){
    struct node *ptr = f;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int dequeue(){
    if(f==NULL){
        printf("Queue is empty\n");
        return -1;
    }
    struct node *ptr = f;
    f = f->next;
    int val = ptr->data;
    free(ptr);
    return val;
}

void enqueue(int val){
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    if(f==NULL)
        f=r=n;
    else{
        r->next = n;
        r=n;
    }    
}

int main(){
    enqueue(23);
    enqueue(56);
    enqueue(6);
    enqueue(36);
    enqueue(26);

    traversal();
    printf("Dequeuing Element: %d\n",dequeue());
    printf("Dequeuing Element: %d\n",dequeue());

    traversal();

    return 0;
}