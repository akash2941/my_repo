#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <bits/stdc++.h>

using namespace std;

int n=1;

struct node
{
    int data;
    struct  node * left;
    struct node * right;
};
// Create Node Fn
struct node *createnode(int input)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=input;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

}
//Insert Node Fn
struct node *insertnode(struct node *root,int input)
{
    if(root == NULL)
    {
        return createnode(input);  //calling create node
    }
    if(input < root->data)
    {
        root->left = insertnode(root->left ,input);
    }
    if(input > root->data)
    {
        root->right = insertnode(root->right ,input);
    }
    return root; // return root
}
//check binsry tree is BST or not function
int checkBST(node* root,int &prev){
	
	if(root==NULL)  //null tree is BST
		return 1;

	if(!(checkBST(root->left,prev)))   //doing inorder traversal and checking whether
                                        //all tree node data is sorted or not
		return 0;
	if(root->data<prev)
		return 0;
	prev=root->data; //update prev value

	return checkBST(root->right,prev);
}
int main()
{
    struct node *root = NULL;

    int temp,c,n,a=0;
    int prev= INT_MIN;

    cout << " Enter how many elements (Nodes) you want to be inserted :";
    cin>>n;
    do{
       	cout << " Enter Number to be inserted : ";
        scanf("%d",&temp);
        root=insertnode(root,temp);
        a++;
    }while(a<5);
    c=checkBST(root,prev);
	if(c)
	cout<<"This binary tree is binary search tree :"<<endl;
	else
	cout<<"This is not a binary search tree";
  return 0;
}