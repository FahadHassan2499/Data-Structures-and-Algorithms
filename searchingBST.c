#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (root->data == key)
        return root;
    else if (root->data > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

struct node *searchIter(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
            return root;
        else if (root->data > key)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

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

    struct node *n = searchIter(p, 3);
    if (n != NULL)
    {
        printf("Element found : %d", n->data);
    }
    else
        printf("Element not found");

    return 0;
}