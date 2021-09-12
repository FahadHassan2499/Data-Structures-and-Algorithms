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

void insert(struct node* root,int key){
    struct node* prev = NULL;
    while(root!=NULL){
    prev = root;    
    if(root->data==key){
        printf("Cannot be inserted");
        return;
    }
    else if(root->data > key)
        root=root->left;
    
    else
        root=root->right;
}    
    struct node* new = createNode(key);
    if(prev->data>key){
        prev->left = new;
    }
    else
        prev->right = new;

    printf("Added\n");    
}

int main(){
    //Constructing the nodes
    struct node* p = createNode(9);
    struct node* p1 = createNode(4);
    struct node* p2 = createNode(11);
    struct node* p3 = createNode(2);
    struct node* p4 = createNode(7);
    struct node* p5 = createNode(15);
    struct node* p6 = createNode(5);
    struct node* p7 = createNode(8);
    struct node* p8 = createNode(14);




    /*Structure of tree
        9
       / \
      4   11
     / \   \
    2   7   15
       / \   /
      5   8  14
    */
    
    
    //Linking nodes
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->right = p5;

    p4->left = p6;
    p4->right = p7;

    p5->left = p8;

    // inOrder(p);
    insert(p,12);
    printf("%d",p->right->right->left->left->data);

    return 0;
}