#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int input)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = input;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}
//inorder function
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
//Function to insert node
struct node*insertnode(struct node* root , int input)
{
    if(root == NULL)
    {
        return createnode(input);
    }
    if(input < root->data)
        root->left = insertnode(root->left ,input);
        else if(input > root->data)
        root->right = insertnode(root->right,input);
        return root;
}

int main()
{
    struct node*root = NULL;
    root = insertnode(root,8); 
    insertnode(root,2);
    insertnode(root,6);
    insertnode(root,4);
    insertnode(root,5);
    insertnode(root,3);
    cout<<"Inorder traversal : ";
    inorder(root);  // calling inorder
    return 0;
}