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
	n1->prev=n1;
	
	struct node *n2;
	n2 = new node();
	n2->data=50;
	n2->next=NULL;
	n2->prev=NULL;
	
	n1->next=n2;
	n2->prev=n1;

	struct node *n3;
	n3 = new node();
	n3->data=100;
	n3->next=NULL;
	n3->prev=NULL;
	
	n2->next=n3;
	n3->prev=n2;
	
	cout<<"\n\n1.Prev:"<<n1->prev;	
	cout<<"\n1.Data:"<<n1->data;
	cout<<"\n1.Next:"<<n1->next;

	cout<<"\n\n2.Prev:"<<n2->prev;
	cout<<"\n2.Data:"<<n2->data;
	cout<<"\n2.Next:"<<n2->next;

	cout<<"\n\n3.Prev:"<<n3->prev;
	cout<<"\n3.Data:"<<n3->data;
	cout<<"\n3.Next:"<<n3->next;

}
