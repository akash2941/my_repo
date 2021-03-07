1#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

struct node* top=NULL;
void push(int val)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=top;
	top=newnode;
}
void pop()
{
	if(top==NULL)
	cout<<"stack underflow"<<endl;
	 else
	 {
	 	cout<<"the poped element is:"<<top->data<<endl;
	 	top=top->next;
	 }
}
void display()
{
	struct node* ptr;
	if(top==NULL)
	cout<<"stack is empty";
	else{
		ptr=top;
		cout<<"stack elements are:";
		while(ptr!=NULL)
		{
			cout<<ptr->data<<" ";
			ptr=ptr->next;
		}
	}
		cout<<endl;
}
int main()
{
	int ch,val;
	cout<<"1)push in stack"<<endl;
		cout<<"2)pop from the stack"<<endl;
			cout<<"3)display stack"<<endl;
				cout<<"4)Exit"<<endl;	

do{
		cout<<"enter choice:"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			
			case 1:{
				cout<<"enter value to be pushed"<<endl;
				cin>>val;
				push(val);
				
				break;
			}			
			case 2:
				{
					pop();
					break;
				}
		
			
			case 3:
				{
					display();
					break;
				}
		
			case 4:
				{
					cout<<"Exit"<<endl;
					break;
				}
				default:{
					cout<<"Invalid character"<<endl;
					
				}
		
			
		}
}while(ch!=4);
return 0;

}
