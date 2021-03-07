//Basic program to access data from the node

#include<iostream>

using namespace std;

//Creating Node Structure

struct Node
{
    int data;
    Node *next;
};

//Creating Head Pointer And equating to NULL

Node *head = NULL;

int main()
{
    //Creating a new node
    Node * ptr = new Node();

    //Adding data and setting next = NULL
    ptr->data = 20;
    ptr->next = NULL;

    //Pointing Head to create node
    head=ptr;
    cout<<"data is :"<<head->data;
    return 0;

}
