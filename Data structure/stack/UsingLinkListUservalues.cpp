#include<iostream>

using namespace std;

class stack
{
	public:
		int data,input;
	stack *next;
	int count;
	stack *temp = NULL;

		stack *push()
		{
			stack *n1 = new stack();
			cout<<"Enter data:";
			cin>>input;
			n1->data = input;
			n1->next = temp;
			temp = n1;
		}
		stack pop()
		{

				if(temp == NULL)
			{
				cout<<endl<<"Stack is Empty ";
			}
			
			else{
				cout<<temp->data<<endl;
				temp = temp->next;
				
			}			
		}
};
int main()
{
stack s;
	int ch;	
	do
	{
	cout<<"\n__________________________";
	cout<<"\n1.Push";
	cout<<"\n2.Pop";
	cout<<"\n3.Exit";
	cout<<"\n__________________________";
	cout<<"\nEnter your choice:";
	cin>>ch;
		switch(ch)
		{
			case 1: 	
					s.push();
					break;
			case 2:				
						s.pop();											
					break;
			case 3:
					exit(0);
			default:
					cout<<"\nInvalid choice";
		}
	}
	while(ch!=0);
	return 0;
}
