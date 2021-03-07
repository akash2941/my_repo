#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

//Function to insert at the beginning of linked list

void insertBeg(int d)
{
    Node *ptr=new Node();
    ptr->data = d;
    ptr->next = head;
    head=ptr;
}

//Function to insert at the end of linked list

void insertEnd(int a)
{
    Node *ptr = new Node();
    ptr->data = a;
    ptr->next = NULL;


    if (head == NULL)   // IF list is empty
    {
        head=ptr;       //stored inserted node as a head node(only one node in list)
    }
    else            //ELSE list is not empty
    {
        Node *temp =head;
        while (temp->next != NULL)  //traversing list
    {
        temp=temp->next;
    }
    temp->next = ptr;

    }

}

//Function to display linked list

void dispLink()
{
 Node *temp=head;
 while(temp!=NULL)
 {
  cout<<temp->data<<" ";
  temp=temp->next;
 }
 cout<<"\n";
}


//Main Function

int main()
{
 insertBeg(4);
 insertBeg(3);
 insertBeg(2);
 insertBeg(1);
 //insertEnd(3);
 dispLink();
 return 0;
}
