#include<iostream>

using namespace std;


struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;


//Function to delete node at the beginning

void deleteBeg()
{
    if(head == NULL)
    {
        cout<<"List Empty : ";
    }
    else
    {
        Node *ptr = head;
        head = head->next;
        //free(ptr);
    }

}

//Function to delete node at the end

void deleteEnd()
{
    Node *ptr,*prev;
    if(head == NULL)            //is empty
    {
        cout<<"List is Empty";
    }
    else if(head->next == NULL) //Only one node in the list
    {
        ptr = head;
        head = NULL;
       // free(ptr);
    }
    else          // more then One node in list
    {
       ptr = head;

        while(ptr->next != NULL)  //traverse link list
        {
            prev = ptr;
            ptr =ptr->next;
        }
        prev->next = NULL;    //prev = second last node
      //  free(ptr);
    }
}

//Function to insert at the end of linked list

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

 deleteBeg();
 displayList();
 deleteEnd();
 displayList();
 return 0;
}
