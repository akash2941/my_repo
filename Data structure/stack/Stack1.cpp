#include<iostream>
using namespace std;
int stack[3];
static int count;
int n,element;
	void push()
	{

			cout<<"\nEnter an element in stack:";
			cin>>element;
			stack[count]=element;
			cout<<"\nEntered element is:"<<stack[count];
			count++;
			cout<<"\nCount is:"<<count;
	}	
	
	void pop()
	{				
				count--;
				cout<<"\nPoped element is:"<<stack[count];
				cout<<"\nCount is:"<<count;
	}


int main()
{
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
					if(count<3)
					{
						push();
					}
					else
					{
						cout<<"\nStack is already full";
					}
					break;
			case 2:
					if(count>0)
					{
						pop();	
					}
					else
					{
						cout<<"\nStack is already empty";						
					}
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
