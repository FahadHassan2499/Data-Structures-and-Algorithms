#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void inOrder(struct node * root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}


struct node* createNode(int data){
    struct node * n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right  = NULL;
    return n;
}

struct node* inPredecessor(struct node* root){
    if(root->left!=NULL){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    }
    else{

        root=root->right;
        while(root->left!=NULL){
            root=root->left;
        }
    }
    return root;
}


struct node* deleteNode(struct node* root,int value){
    struct node* iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(value<root->data){
        root->left = deleteNode(root->left,value);
    }
    else if(value>root->data){
        root->right = deleteNode(root->right,value);
    }
    else{
        iPre = inPredecessor(root);
        root->data = iPre->data;
        if(root->left!=NULL)
            root->left = deleteNode(root->left,iPre->data);
        else
            root->right=deleteNode(root->right,iPre->data);    
    }
    return root;

}

// struct node* inOrderPredecessor(struct node* root){
//     root=root->left;
//     while(root->right != NULL ){
//         root=root->right;
//     }
//     return root;
// }

// struct node* deleteNode(struct node* root,int value){
//     struct node* iPre;
//     if(root==NULL)
//         return NULL;
//     if(root->left==NULL && root->right==NULL){
//         free(root);
//         return NULL;
//     }    
//     if(root->data>value)
//         root->left=deleteNode(root->left,value);
//     else if(root->data<value)
//         root->right=deleteNode(root->right,value);
//     else{
//         iPre=inOrderPredecessor(root);
//         root->data = iPre->data;
//         root->left=deleteNode(root->left,iPre->data);
//     }  
//     return root;          
// }

int main()
{
    //Constructing the nodes
    struct node *p = createNode(9);
    struct node *p1 = createNode(4);
    struct node *p2 = createNode(11);
    struct node *p3 = createNode(2);
    struct node *p4 = createNode(7);
    struct node *p5 = createNode(15);
    struct node *p6 = createNode(5);
    struct node *p7 = createNode(8);
    struct node *p8 = createNode(14);

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
    inOrder(p);
    deleteNode(p,15);
    printf("\n");
    inOrder(p);
    
    return 0;
}