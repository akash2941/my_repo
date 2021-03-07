#include<iostream>

using namespace std;

class stack
{
	int data;
	stack *next;
	int count;
	stack *temp = NULL;
	public:
		stack *push(int input)
		{
			stack *n1 = new stack();
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
			else
			{
				cout<<temp->data<<endl;
				temp = temp->next;
			}			
		}
};
int main()
{
	stack *obj = new stack();
	obj->push(10);	
	obj->push(20);
	obj->push(110);	
	obj->push(220);
	
	obj->pop();
	obj->pop();
	obj->pop();
	obj->pop();
	obj->pop();	
	
	return 0;
}
