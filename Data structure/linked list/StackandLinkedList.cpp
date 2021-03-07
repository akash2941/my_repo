#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	 node * next;
	 node * prev;
	 
	 node *n1 = new node();		
	 node *n2= new node();		
	 node *n3= new node();
		
		node(){};
/*	int isFull()
	{
		node *temp = new node();
		temp=n3->next;
		if(temp==NULL)
		{
			return 0;
		}
		return 1;
	}*/
	void push()
	{
//		int res= isFull();
		
//		if(res==0)
//		{
//			cout<<"No further node:";
//		}
		
//		else
//		{
		cout<<"\nEnter data for n1:";
		cin>>n1->data;

		cout<<"\nEnter data for n2:";
		cin>>n2->data;

		cout<<"\nEnter data for n3:";
		cin>>n3->data;			
		//n1->data=input;
		n1->next=NULL;
		n1->prev=NULL;
		
	//	n2->data=input;
		n2->next=NULL;
		n2->prev=NULL;
		n1->next=n2;
		n2->prev=n1;
		
	//	n3->data=input;
		n3->next=NULL;
		n3->prev=NULL;
		n2->next=n3;
		n3->prev=n2;
		
		node * temp1 = new node();
		temp1 = n1->next;
		while(temp1!=NULL)
		{
			cout<<"\ndata:"<<n1->data;
			temp1=temp1->next;
		}
	
		}


//	}	
	
/*	void pop()
	{				
				count--;
				cout<<"\nPoped element is:"<<stack[count];
				cout<<"\nCount is:"<<count;
	}*/
};




int main()
{
	node n;
	//n.isFull();
	n.push();
	n.push(); 

	return 0;
}
