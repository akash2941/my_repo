#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
     node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
};
struct node *createnode(int input)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = input;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
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

//preorder function
void preOrder(struct node *root)
{
    if(root != NULL)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
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

//PostOrder function
void PostOrder(struct node *root)
{
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    int r,n,temp,a=0;
    struct node*root = NULL;
   /*  struct node *root = new node(1); 
    root->left           = new node(2); 
    root->right         = new node(3); 
    root->left->left     = new node(4); 
    root->left->right = new node(5); */
    cout << " Enter how many elements (Nodes) you want to be inserted :";
    cin>>n;
    do{
        cout << " Enter Node to be inserted : ";
        scanf("%d",&temp);
        root=insertnode(root,temp);
        a++;
    }while(a<n);
    do{
    	cout<<endl<<"Select An Operation : ";
    	cout<<endl<<"1. Inorder Traversal "<<endl;
    	cout<<"2. Priorder Traversal "<<endl;
    	cout<<"3. Postorder Traversal"<<endl;
    	cout<<"4. Exit"<<endl;
   		cin>>r;

   			switch (r)
   			 {
   			 case 1 :
                cout<<"Inorder traversal : ";
                inorder(root);
					break;
				
   			 case 2 :
                cout<<"preorder traversal : ";
                preOrder(root);
      			  break;
             case 3 : 
                cout<<"Postorder traversal : ";
                PostOrder(root);
      			  break;
      		 case 4 :
      			  break;
      	    default : cout<<"Encorrect input"<<endl;
   			 }

		   }while(r!=4);
    return 0;
}