#include<iostream>
#include<stdlib.h>
using namespace std;
struct demo
{
	int data;
	struct demo*next;
};


struct demo * firstNode(int input)
{
	struct demo *node=(struct demo *)malloc(sizeof(struct demo));
	{
		node->data=input;
		node->next=NULL;
		return node;
	}
}
//_________________________________________________________________________________________________________
struct demo * createNode(int input)
{
	struct demo *n=(struct demo *)malloc(sizeof(struct demo));
	n->data=input;
	n->next=NULL;
	return n;
}
//_________________________________________________________________________________________________________
void connection(struct demo *n1,struct demo *n2)
{
	n1 ->next=n2;
}
//_________________________________________________________________________________________________________
void traverse(struct demo *temp)
{
	while(temp!=NULL)
	{
		cout<<"\n"<<temp->data;
				cout<<"\n"<<temp->next;
		temp=temp->next;
	}
}
//_________________________________________________________________________________________________________
int main()
{
	struct demo *d=firstNode(10);
	struct demo *d1=createNode(20);
	struct demo *d2=createNode(30);
	connection(d2,d1);
	connection(d1,d);
	traverse(d2);
	
}

