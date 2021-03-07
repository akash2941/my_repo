#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node * next;
		node * prev;

		node *n1=new node();
		node *n2=new node();
		node *n3=new node();
		node(){};
		void init()
		{
			cout<<"\nEnter data for n1:";
			cin>>n1->data;

			cout<<"\nEnter data for n2:";
			cin>>n2->data;

			cout<<"\nEnter data for n3:";
			cin>>n3->data;
		}
		
		node * PreviousAdd()
		{
			//n1->prev=NULL;
			n2->prev=NULL;
			n3->prev=NULL;
			
			n1->prev=n1;
			n2->prev=n1;
			n3->prev=n2;
		}
		
		node * NextAdd()
		{
			n1->next=NULL;
			n2->next=NULL;
			n3->next=NULL;
			
			n1->next=n2;
			n2->next=n3;
			//n3->next=NULL;
		}
		
		void show()
		{
			node *temp=n1;
			while(temp!=NULL)
			{
				cout<<"\n\nPrevious add is:"<<temp->prev;
				cout<<"\nData is:"<<temp->data;
				cout<<"\nNext add is:"<<temp->next;
			}
		}


};

int main()
{
	node *obj = new node();
	obj->init();
	obj->PreviousAdd();
	obj->NextAdd();
	obj->show();

}
