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

struct Node* deleteFirst(struct Node* head){
    struct Node* ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node* deleteEnd(struct Node* head){
    struct Node* p;
    struct Node* q;
    p = head;
    q = head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct Node* deleteIndex(struct Node* head,int index){
    struct Node* p;
    struct Node* q;
    p = head;
    q = head->next;
    int i=0;
    while(i<index-1){
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node* deleteValue(struct Node* head,int value){
    struct Node* p;
    struct Node* q;
    p = head;
    q= head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next = q->next;
        free(q);
    }
    else
        printf("Not Found");
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
    // head=deleteFirst(head);
    // head = deleteEnd(head);
    // head = deleteIndex(head,2);
    head = deleteValue(head,20);
    
    printf("Linked List after deletion\n");
    linkedListTraversal(head);
    return 0;
}