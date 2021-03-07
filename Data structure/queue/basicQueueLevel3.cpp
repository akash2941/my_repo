#include<iostream>
using namespace std;
int count=0;
int queue[3];
int read=0;

void insert(int input)
{
	if(count==3)
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
void deleted()
{
	if(read==count)
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
