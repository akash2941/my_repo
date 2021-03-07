#include<iostream>
using namespace std;
	static int count,read;
	int queue[3];
	int num;
class Que
{
	public:
	void insert()
	{
	cout<<"\nInsert a num in queue:\t";
	cin>>num;
	
	queue[count]=num;	
	cout<<"\nNumber is:\t"<<queue[count];
	count++;
	cout<<"\ncount is:\t"<<count;	
	}
	void deleted()
	{	
			cout<<"\nDeleted element is:"<<queue[read];
			read++;			
	}
};


int main()
{
	Que q;
	int ch;
	do
	{
		cout<<"\n\nEnter your choice:";
		cout<<"\n1.Insert";
		cout<<"\n2.Delete";
		cout<<"\n3.Exit\n\n";

		cin>>ch;
		
		switch(ch)
		{
			case 1: 
					if(count==3)
					{
						cout<<"\nQueue is full:";
					}
					else
					{
						q.insert();
					}
					break;
			case 2: if(read==count)
					{
						count=0;
						cout<<"\nQueue is empty:";
					}
					else
					{
						while(read!=3)
						{
							q.deleted();
						}
					}
					break;
			case 3: exit(0);
					break;
			default:
					cout<<"\n\nInvalid choice:";
		}
	}
	while(ch!=0);
	return 0;
}
