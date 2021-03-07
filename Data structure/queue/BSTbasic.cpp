#include<iostream>
using namespace std;
 class tree
 {
 public:
 	int data;
 	 tree * right;	
	 tree * left;
	  
	  tree *newnode(int input)
	  {
	  	tree * temp = new tree();
	  	temp->data=input;
	  	temp->right=NULL;
	  	temp->left=NULL;
	  		return temp;
	  }
	  
	  tree *insertnode(tree * root,int x)
	  {
	  	if(root==NULL)
	  	{
	  		tree * temp1 = new tree();
	  		return temp1;
		}
		else if(x>root->data)
		{
			insertnode(root->right,x);
		}
		else
		{
			insertnode(root->left,x);
		}
	  }
 };

 int main()
 {
 	 tree *n1= new tree(); 
	n1->data=100;
 	n1->left=NULL;
 	n1->right=NULL;

  tree *n2= new tree();
 	n2->data=90;
 	n2->left=NULL;
 	n2->right=NULL;
 	n1->left=n2;

 tree *n3= new tree();
 	n3->data=180;
 	n3->left=NULL;
 	n3->right=NULL;
	n1->right=n3;

   tree *n4= new tree();
 	n4->data=750;
 	n4->left=NULL;
 	n4->right=NULL;
 	n3->right=n4;
 
   tree *n5= new tree();
 	n5->data=95;
 	n5->left=NULL;
 	n5->right=NULL;
 	n2->right=n5; 	

	tree *n6= new tree();
 	n6->data=50;
 	n6->left=NULL;
 	n6->right=NULL;   
 	n3->left=n6; 	
	
	tree t;

	t.insertnode(n1,1);
	
		cout<<"\n\t\t\t\t\t"<<n1->data;
		cout<<"\n\t\t"<<n2->data;
		cout<<"\n\t\t\t\t\t\t\t"<<n3->data;
		cout<<"\n\t\t\t\t\t\t\t\t\t"<<n4->data;
		cout<<"\n\t\t\t\t"<<n5->data;
		cout<<"\n"<<n6->data;
		//cout<<"\n"<<n7->data;*/
}
