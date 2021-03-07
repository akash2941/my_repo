#include<iostream>
using namespace std;
 class tree
 {
 public:
 	int data;
 	 tree * right;
	
	 tree * left;
	  int inorder(tree *root)
 		{
 			//cout<<"\nCalling traverse function:";
 			if(root!=NULL)
 				{
 					inorder(root->left);
 					cout<<"\n"<<root->data;
 					inorder(root->right); 			
				}
		}
		
		int preorder(tree *root)
 		{
 			//cout<<"\nCalling traverse function:";
 			if(root!=NULL)
 				{
 					cout<<"\n"<<root->data;
					 preorder(root->left);
 					preorder(root->right); 			
				}
		}	  
		int postorder(tree *root)
 		{
 			//cout<<"\nCalling traverse function:";
 			if(root!=NULL)
 				{
 					postorder(root->left);
 					postorder(root->right); 			
 					cout<<"\n"<<root->data;
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

	tree *n7= new tree();
 	n7->data=50;
 	n7->left=NULL;
 	n7->right=NULL;   
 	n3->left=n7; 	
	
	tree t;
	cout<<"Inorder is:";
	t.inorder(n1);

	cout<<"\n\nPreorder is:";
	t.preorder(n1);

	cout<<"\n\nPostorder is:";
	t.postorder(n1);
 	
}
