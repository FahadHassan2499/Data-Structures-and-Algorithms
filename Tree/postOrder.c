#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void postOrder(struct node * root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

struct node* createNode(int data){
    struct node * n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right  = NULL;
    return n;
}
int main(){
    //Constructing the nodes
    struct node* p = createNode(4);
    struct node* p1 = createNode(1);
    struct node* p2 = createNode(6);
    struct node* p3 = createNode(5);
    struct node* p4 = createNode(2);
    /*Structure of tree
        4
       / \
      1   6
     / \
    5   2 
    */
    
    
    //Linking nodes
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    postOrder(p);

    return 0;
}