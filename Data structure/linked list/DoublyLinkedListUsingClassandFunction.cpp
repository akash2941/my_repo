#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	 node * next;
	 node * prev;

		node * firstNode(int input)
		{

			node *n1=new node();
			n1->data=input;
			n1->next=NULL;
			n1->prev=NULL;
			return n1;
		}

		node * createNode(int input)
		{
			node *n2= new node();
						
			n2->data=input;
			n2->next=NULL;
			n2->prev=NULL;
			return n2;
		}

		void connection( node *n1, node *n2)
		{
			n1->next=n2;
			n2->prev=n1;
		}
		
		void traverse( node *temp)
		{
			while(temp!=NULL)
			{
				cout<<"\n\nPrevious:"<<temp->prev;
				cout<<"\nData:"<<temp->data;
				cout<<"\nNext:"<<temp->next;

				
				temp=temp->next;
			}
		}

};

int main()
{
	node obj;
	 node *d=d->firstNode(10);
	 node *d1=d1->createNode(20);
	 node *d2=d2->createNode(30);

	 obj.connection(d,d1);
	 obj.connection(d1,d2);
	 obj.traverse(d);

}
