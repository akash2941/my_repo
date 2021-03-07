#include<iostream>
using namespace std;
int count=0;
int queue[3];
int read=0;
//_____________________________________________________________________________
int isFull()
{
	if(count==3)
	{
		return 0;
	}
	return 1;
}
void insert(int input)
{
	if(isFull()==0)
	{
		cout<<"\nFull\n";
	}
	else
	{
		queue[count]=input;	
		cout<<"\n"<<queue[count];
			count++;
	}
}
//_______________________________________________________________________________
int isEmpty()
{
	if(read==count)
	{
		return 0;
	}
	return 1;
}
void deleted()
{
	if(isEmpty()==0)
	{
		cout<<"\nEmpty";
	}
	else
	{		
		cout<<"\n"<<queue[read];
		read++;
	}
}

int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	
	deleted();
	deleted();	
	deleted();
	deleted();
	deleted();
	return 0;
}
