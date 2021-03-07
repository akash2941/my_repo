#include<iostream>
using namespace std;
class node
 {
 	public:
 		int counter=0;
 	
 	int data;
   node * next;
   
   node * push(int input)
 {
       node *node1=new  node();
    		counter++;
    	  node1->data=input;
    	  node1->next=NULL;	
 }
  node * connection( node *n1,node *n2)
 {
 	n2->next=n1;
 }
 
  node *pop(node *temp)
 {
  if(counter==0)
   {
  	cout<<"Stack is empty";
   }	
  else
   {
  //	counter--;
    while(temp!=NULL)
 	{
 		cout<<temp->data<<endl;
 		cout<<temp->next<<endl;
 		temp=temp->next;
	 }
   }
 }
 
 
};
 
 int main()
 {
 	node dn;
 	 node *d1=dn.push(10);
 	 node *d2=dn.push(20);
     node *d3=dn.push(30);
 	 node *d4=dn.push(40);
 	// node *d5=push(90);
 	//struct node *d4=push(40);
 	
 	 dn.connection(d1,d2);
 	 dn.connection(d2,d3);
 	 dn.connection(d3,d4);
 	 //connection(d4,d5);
 	 //connection(d3,d4);
 	 
 	dn.pop(d4);
 	 
// display(d3);
 }
