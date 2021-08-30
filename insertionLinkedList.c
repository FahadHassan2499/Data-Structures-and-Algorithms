#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertAtBeg(struct Node* head,int value){
    struct Node* ptr  = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next =head;
    head=ptr;
    return head;
}

struct Node* insertAtEnd(struct Node* head,int value){
    struct Node* ptr  = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    struct Node* p;
    p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node* insertAtIndex(struct Node* head,int value,int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    struct Node* p;
    p=head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next = ptr;
    return head;

}

struct Node* insertAfterNode(struct Node* head,struct Node* q,int value){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = q->next;
    q->next=ptr;
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
    fourth->next = NULL;

    linkedListTraversal(head);
    printf("Linked List after insertion\n");
    head=insertAtBeg(head,20);
    // head=insertAtEnd(head,20);
    // head =  insertAtIndex(head,20,2);
    // head  = insertAfterNode(head,third,20);
    linkedListTraversal(head);
    return 0;
}