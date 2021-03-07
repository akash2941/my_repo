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
bool SearchNode(struct node* root, int key) 
{ 
    
    while (root != NULL)  // Traverse untill root reaches to dead end 
     { 
       
        if (key > root->data)   // pass right subtree as new tree 
            root = root->right; 
  
        
        else if (key < root->data) // pass left subtree as new tree 
            root = root->left; 
        else
            return true; // if the key is found return 1 
    } 
    return false; 
} 
int main()
{
    int a;
    struct node *root =NULL;
    root=insertnode(root,3);
    insertnode(root,4);
    insertnode(root,2);
    insertnode(root,5);
    insertnode(root,1);
    insertnode(root,3);
    a=SearchNode(root , 5);
    if (a) 
        cout << "Yes node found !!!!"; 
    else
        cout << "Not Found !!!!"; 
    return 0;

    return 0;
}