#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;


//Function to Display middle element
void showMid()
{
    Node *slow = head;
    Node *fast = head;

    if(head == NULL)
        cout<<"List id Empty ";
    else
    {
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"Middle element is : "<<slow->data;
    }
}

void insertEnd(int a)
{
    Node *ptr = new Node();
    ptr->data = a;
    ptr->next = NULL;

    if(head == NULL)
    {
        head=ptr;
    }
    else
    {
        Node *temp = head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = ptr;
    }
}

//Function to display linked list

void displayList()
{
    Node *ptr = head;
    if(ptr == NULL)
    {
        cout<<"List is empty :";
    }
    else
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
}

int main()
{
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    //insertEnd(6);
    //insertEnd(7);
   // insertEnd(8);

    displayList();
    showMid();
    return 0;
}
