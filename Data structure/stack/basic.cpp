#include<iostream>
using namespace std;

int stack[3];
static int count;
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


int main()
{
	push(10);
	push(120);
	push(130);
	push(150);
	push(160);
	cout<<"\n";
			
	pop();
	pop();
	pop();
	pop();
return 0;
}
