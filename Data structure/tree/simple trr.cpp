#include<iostream>
using namespace std;
 struct tree
 {
 	int data;
 	struct tree * right;
 	struct tree * left;
 };
 
 int main()
 {
 	struct tree *n1= new tree();

	n1->data=10;
 	n1->left=NULL;
 	n1->right=NULL;

 	struct tree *n2= new tree();
 	n2->data=510;
 	n2->left=NULL;
 	n2->right=NULL;
 	n1->left=n2;

 	struct tree *n3= new tree();
 	n3->data=410;
 	n3->left=NULL;
 	n3->right=NULL;
	n1->right=n3;

  	struct tree *n4= new tree();
 	n4->data=210;
 	n4->left=NULL;
 	n4->right=NULL;
 	n3->right=n4;
 	
 	cout<<"\n1."<<n1->data;
 	cout<<"\n2."<<n2->data;
 	cout<<"\n3."<<n3->data;
 	cout<<"\n4."<<n4->data;
 	

}
