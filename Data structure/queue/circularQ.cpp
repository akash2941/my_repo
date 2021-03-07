#include<iostream>
using namespace std;
static int count,read;
int queue[3];
int num;
//_____________________________________________________________________________

void insert()
{
	cout<<"\nInsert a num in queue:\t";
	cin>>num;

	queue[count]=num;	
	cout<<"\nNumber is:\t"<<queue[count];
	count++;
	cout<<"\ncount is:\t"<<count;
	
}
//_______________________________________________________________________________

void deleted()
{		
	
		cout<<"\nDeleted element is:"<<queue[read];		
			read++;	
				
}
void display()
{
	cout<<"\nCurrent node is:"<<queue[count];
}

int main()
{
	int ch;
	do
	{
		cout<<"\n\nEnter your choice:";
		cout<<"\n1.Insert";
		cout<<"\n2.Delete";
		cout<<"\n3.Display";
		cout<<"\n4.Exit\n\n";

		cin>>ch;
		
		switch(ch)
		{
			case 1: 
				/*if((read+1)%3==count)
			{
				cout<<queue[read];
			}*/
					if(read==0 && count==3)
					{
						cout<<"\nQueue is full:";

												
					}
					else
					{
						insert();

					}
					break;
			case 2: if(read==count)
					{
					
						cout<<"\nQueue is empty:";
						
					}
					else
					{						
							deleted();
						
					}
					break;
			case 3: display();
					break;
					
			case 4: exit(0);
					break;
			default:
					cout<<"\n\nInvalid choice:";
		}
	}
	while(ch!=0);
	return 0;
}
/*	if((read+1)%3==count)
			{
				cout<<queue[read];
			}*/
