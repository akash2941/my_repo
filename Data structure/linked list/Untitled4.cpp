#include<iostream>
using namespace std;
 class tree
 {
 public:
 	int data;
 	tree(){
	 };
 	 tree * next=new tree();

 	
 	void setdata(int input)
 	{
 		data=input;
	}
 	void setnext(tree * temp)
 	{
 		next=temp;
	}
 	int getdata()
 	{
 		return data;
	}
 	tree * getnext()
 	{
 		return next;
	}
 };
 
 int main()
 {
 	 //tree res= getnext();
	  tree *n1= new tree();

	n1->setdata(10);
 	n1->setnext();

  tree *n2= new tree();
	n1->setdata(10);
 	n1->setnext();
 	n1->setnext(n2);

 tree *n3= new tree();
	n1->setdata(10);
 	n1->setnext();
 	n2->setnext(n3);
 	
 	cout<<"\n1."<<n1->data;
 	cout<<"\n2."<<n2->data;
 	cout<<"\n3."<<n3->data;

 	

}
