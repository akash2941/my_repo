#include<iostream>
using namespace std;
class Stack
{
public:
int stack[3];
 int count=0;
	int isFull()
	{
		if(count==3)
		{
			return 0;
		}
		return 1;
	}
	void push(int element)
	{
			int res = isFull();
			if(res==0)
			{
			cout<<"\nStack is full:";	
			}
			else
			{
			stack[count]=element;
			cout<<"\nEntered element is:"<<stack[count];
			count++;				
			}
	}	
	int isEmpty()
	{
		if(count==0)
		{
			return 0;
		}
		return 1;
	}	
	void pop()
	{				
			int res = isEmpty();
			
			if(res==0)
			{
			cout<<"\nStack is empty:";	
			}
			else
			{
					count--;
				cout<<"\nPoped element is:"<<stack[count];				
			}
	}
};


int main()
{
	Stack s;
	s.push(10);
	s.push(120);
	s.push(130);
	s.push(150);
	s.push(160);
	cout<<"\n";
			
	s.pop();
	s.pop();
	s.pop();
	s.pop();
return 0;
}
