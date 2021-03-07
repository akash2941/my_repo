
#include<iostream>

using namespace std;


struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;


//Function to delete node using pointer
//Deleting Middle Node
void deleteNode(Node *ptr)
{

 Node *temp;         //creating temporary pointer

 temp=ptr->next;    //Pointing temp to next part of current node i.e. next node

 ptr->data=temp->data;  //copy data and next part of next node to current node

 ptr->next=temp->next; //point current node to link part of next node

// free(temp);   //Delete current node

}



void insertEnd(int a)
{
    Node *ptr = new Node();
    ptr->data = a;
    ptr->next=NULL;


    if(head == NULL)    // adding 1st node
    {
        head = ptr;
    }
    else
    {
        Node * temp = head;
        while(temp->next != NULL)   //traversing untill get lsat node
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}

// function to display Linked list

void displayList()
{
    Node *ptr = head;
    if(ptr == NULL)
    {
        cout<<"List is empty ";
    }
    else
    {
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
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


 displayList();
 deleteNode(head->next);
 displayList();
 deleteNode(head->next->next);
 displayList();
 return 0;
}
