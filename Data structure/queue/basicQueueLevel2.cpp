#include<iostream>
using namespace std;

int main()
{
	int count=0,read=0;
	int queue[3];
	
	cout<<"\nEnter an element in queue:";
	for(int i=count;i<3;i++)
	{
		cin>>queue[i];
	}
	cout<<"\nEntered element in queue are:";
	for(int i=count;i>0;i--)
	{
		cout<<queue[i];
	}
/*	cout<<"\nDequed elements are:";
	for(int i=read;i>=count;i++)
	{
		cout<<queue[read];
	}*/
	return 0;
}
