#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node * n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right  = NULL;
    return n;
}
int main(){
    //Constructing the nodes
    struct node* p = createNode(2);
    struct node* p1 = createNode(1);
    struct node* p2 = createNode(4);
    struct node* p3 = createNode(11);
    struct node* p4 = createNode(12);
    struct node* p5 = createNode(3);

    //Linking nodes
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = NULL;
    p->right = p5;

    return 0;
}
