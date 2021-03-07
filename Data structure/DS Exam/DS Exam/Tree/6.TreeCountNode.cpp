#include<iostream>
#include<stdlib.h>

using namespace std;

int n=1;

struct node
{
    int data;
    struct  node * left;
    struct node * right;
};

struct node *createnode(int input)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=input;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

}

struct node *insertnode(struct node *root,int input)
{
    if(root == NULL)
    {
        return createnode(input);
    }
    if(input < root->data)
    {
        root->left = insertnode(root->left ,input);
    }
    if(input > root->data)
    {
        root->right = insertnode(root->right ,input);
    }
    return root;
}
///Node count function
int CountNodes(node*root)
{
    if(root==NULL)
        return 0;
    if(root->left!=NULL)
    {
        n=n+1;
        n=CountNodes(root->left);
    }
    if(root->right!=NULL)
    {
        n=n+1;
        n=CountNodes(root->right);
    }
    return n;
}
int main()
{
    struct node *ptr =NULL;
    ptr=insertnode(ptr,3);
    insertnode(ptr,4);
    insertnode(ptr,2);
    insertnode(ptr,5);
    insertnode(ptr,1);
    insertnode(ptr,3);
    cout<<"Total no of nodes in tree "<<CountNodes(ptr)<<endl;

    return 0;
}