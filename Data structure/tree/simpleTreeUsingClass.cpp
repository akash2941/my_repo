#include<iostream>
using namespace std;
 class tree
 {
 public:
 	int data;
 	 tree * right;
 	 tree * left;
 };
 
 int main()
 {
 	 tree *n1= new tree();

	n1->data=10;
 	n1->left=NULL;
 	n1->right=NULL;

  tree *n2= new tree();
 	n2->data=510;
 	n2->left=NULL;
 	n2->right=NULL;
 	n1->left=n2;

 tree *n3= new tree();
 	n3->data=410;
 	n3->left=NULL;
 	n3->right=NULL;
	n1->right=n3;

   tree *n4= new tree();
 	n4->data=210;
 	n4->left=NULL;
 	n4->right=NULL;
 	n3->right=n4;
 	
 	cout<<"\n1."<<n1->data;
 	cout<<"\n2."<<n2->data;
 	cout<<"\n3."<<n3->data;
 	cout<<"\n4."<<n4->data;
 	

}
