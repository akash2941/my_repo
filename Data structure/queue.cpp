#include <iostream>
using namespace std;
# define SIZE 5
class Queue
{
	int front ,rear;
	int queue[SIZE];

public:
	Queue(void)
	{
		front=rear=-1;
	}

	bool is_queue_empty()
	{
		if(front==rear)
		{
			return 1;
		}
		return 0;
	}
	bool is_queue_full()
	{
		if(rear==SIZE-1)
		{
			return 1;
		}
		return 0;
	}

	void enqueue(int ele)
	{
		if(is_queue_full()==1)
		{
			cout<<"Queue is Full :"<<endl;
		}
		else
			if(front==-1&&rear==-1)
			{
				front=rear=0;
				queue[rear]=ele;
				cout<<"\n Item Inserted"<<ele<<endl;
			}
			else
			{
				rear++;
				queue[rear]=ele;
				cout<<"\n Item Inserted :"<<ele<<endl;


			}
	}
	void dequeue(void)
	{
		int ele;
		if(is_queue_empty())
		{
		    cout<<"hdhcdh"<<endl;
			cout<<"Queue Overflow"<<endl;
		}
		else if(front==0 && rear==0)
		{
			ele=queue[front];
			front=rear=-1;
			cout<<"\nItem Deleted :"<<ele<<endl;
		}
		else
		{
			ele=queue[front];
			front++;
			cout<<"\nItem Deleted :"<<ele;
		}
	}
	void displayqueue()
	{
		int i;
		if(is_queue_empty()) {
			cout << endl << "Queue is Empty!!" << endl;
		}
		else {
			cout << endl << "Front = " << front;
			cout << endl << "Queue elements : ";
			for(i=front; i<=rear; i++)
				cout << queue[i] << "\t";
			cout << endl << "Rear = " << rear << endl;
		}
	}
	int get_front(void)
	{
		int gfront;
		if(is_queue_empty())
		{
			cout<<"Queue is Empty"<<endl;
		}
		else
			gfront=queue[front];
		return gfront;
	}
};
int main() {
int data;
	Queue q;

	q.dequeue();

	cout<<" \nQueue created:"<<endl;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	q.displayqueue();
	q.dequeue();
	q.displayqueue();

	q.get_front();
		cout<<"front element :"<<q.get_front()<<endl;


	return 0;
}
