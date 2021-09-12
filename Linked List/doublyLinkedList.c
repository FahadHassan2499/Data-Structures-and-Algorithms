#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void linkedListTraversal(struct Node* head){
    struct Node* p = head;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

struct Node* insertAtFirst(struct Node* head,int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    head->prev = ptr;
    ptr->next = head;
    head=ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->prev = NULL;
    head->next = second;

    second->data = 8;
    second->prev = head;
    second->next = third;

    third->data = 9;
    third->prev=second;
    third->next = fourth;

    fourth->data = 10;
    fourth->prev = third;
    fourth->next = NULL;

    linkedListTraversal(head);
    head=insertAtFirst(head,56);
    printf("After Insertion\n");
    linkedListTraversal(head);


    return 0;
}