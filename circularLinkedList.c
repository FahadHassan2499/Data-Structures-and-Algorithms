#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    struct Node* p;
    p=ptr;
    do{
        printf("%d\n",p->data);
        p=p->next;
    }while(p!=ptr);
    
}

struct Node* insertAtFirst(struct Node* head,int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data =data;
    struct Node* p;
    p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next = ptr;
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
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = head;

    linkedListTraversal(head);
    head = insertAtFirst(head,56);
    printf("After Insertion\n");
    linkedListTraversal(head);


    return 0;
}