#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node * next;
	struct node * prev;
};

int main()
{
	struct node *n1;
	n1 = new node();
	n1->data=10;
	n1->next=NULL;
	n1->prev=NULL;
	
	struct node *n2;
	n2 = new node();
	n1->next=n2;
	n1->next->data=50;
	n1->next->next=NULL;
	n1->next->prev=NULL;
	
	n1->next->next=n2;
	n2->next->prev=n1;

	struct node *n3;
	n3 = new node();
	n1->next->next=n3;
	n1->next->next->data=100;
	n1->next->next->next=NULL;
	n1->next->next->prev=NULL;
	
	n1->next->next=n3;
	n1->next->next->prev=n2;
	
	struct node * temp= n1;
	cout<<"\nForword order is:";
	for(temp=n1;temp!=NULL;temp=temp->next)
	{
		cout<<"\n\n Prev  is:"<<temp->prev;
		cout<<"\n Data is:"<<temp->data;
		cout<<"\n Next is:"<<temp->next;
	}
	cout<<"\n\nReverse order is:";	
	struct node * temp1= n1->next->next;
	//for(temp1=n1;temp1!=NULL;temp1=temp1->next);
	
		struct node * temp2=temp1;

		while(temp1!=n1)
		{
			//temp1=temp1->prev;
			cout<<"\n\n Prev  is:"<<temp1->prev;
			cout<<"\n Data is:"<<temp1->data;
			cout<<"\n Next is:"<<temp1->next;
			temp1=temp1->prev;
			//temp2=temp2->prev;
		}
	
}
